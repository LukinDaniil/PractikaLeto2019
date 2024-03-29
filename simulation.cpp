#include "simulation.h"
#include "ui_simulation.h"
//#include "painthelper.h"
#include "QWidget"
#include "qfile.h"
#include "floormap.h"
#include "vector"
#include "QFileDialog"
Simulation::Simulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);
    //group.timeshet.ReadTimesheet("F:/Projects/PractikaLeto2019/Files/raspisanie_pravilnoe.txt");
    group.timeshet.ReadTimesheet("F:/Projects/PractikaLeto2019/Files/rosp.txt");
    entranceToTheUniversity.X = 17;
    entranceToTheUniversity.Y = 17;
    on_loadMapButton_clicked();

    group.numberOfPreviousCabinet = -1;
    group.amountOfPeopleInTheCabinet = 0;
    //vector<Cabinet> allCabinets = mapOfTheFloor->getAllCabinets();
    //allCabinets[0].used[0] = true;


    //int entryXCoordinate = 18, entryYCoordinate = 18;
    //group.numberOfCurrentCabinet = 0;
    //PathOfWay currentCabinetCoordinates = mapOfTheFloor->getCoordinatesOfCabinet(group.numberOfCurrentCabinet);
    //vector<PathOfWay> groupWay = goTowardsPoint(currentCabinetCoordinates.X, currentCabinetCoordinates.Y, entryXCoordinate, entryYCoordinate, true);
    //group.groupWay = groupWay;
}

Simulation::~Simulation()
{
    delete ui;
}

void Simulation::stepModel()
{

    //каждый шаг совершаются действия на карте, изменяется mapOfTheFloor, после этого карта опять рисуется для отображения изменений


    if(group.People.size() < 1)
    {
        group.addStudent(entranceToTheUniversity.X, entranceToTheUniversity.Y);
        int hisIndex = group.People.size() - 1;
        //if(group.groupWay.size() != 0)
            //group.People[hisIndex].SetWay(group.groupWay);
    }

    paintHelper->changeMapAccordingWithHumans(group);

    paintHelper->draw();
    paintHelper->setKeepFloor(mapOfTheFloor);
    //в начале дня - ставить текущий кабинет в соответствии с расписанием
    //group.groupMakeStep();
    int numberOfCurrentLesson = group.timeshet.getNumberOfCurrentLesson(currentTime);//получаю номер текущего занятия
    int currentCabinet = group.timeshet.SchoolDay[0][numberOfCurrentLesson].NumCabinet;
    //if(group.amountOfPeopleInTheCabinet == group.People.size())//если все сидят в кабинетеё
    //{
    //    int numberOfCurrentLesson = group.timeshet.getNumberOfCurrentLesson(currentTime);//получаю номер текущего занятия
    //    //int currentCabinet = group.timeshet.getNumberOfTimesheetCabinet(currentTime.GetDay(), numberOfCurrentLesson);
    //    int currentCabinet = group.timeshet.SchoolDay[0][numberOfCurrentLesson].NumCabinet;
    //}
    if(group.numberOfCurrentCabinet == -1)//если это первое занятие, то просто составляем пути и устанавливаем его студентам группы
    {

        group.numberOfCurrentCabinet = currentCabinet;
        PathOfWay coordinatesOfNewCabinet = mapOfTheFloor->getCoordinatesOfCabinet(group.numberOfCurrentCabinet);
        vector<PathOfWay> newWay = goTowardsPoint(entranceToTheUniversity.X, entranceToTheUniversity.Y, coordinatesOfNewCabinet.X, coordinatesOfNewCabinet.Y, true);
        group.DefineWay(newWay);

    }
    else
        if(group.numberOfCurrentCabinet != currentCabinet && group.amountOfPeopleInTheCabinet == group.People.size())//если текущий кабинет не соответсвует тому что должен быть по расписанию, то устанавливаем текущий кабинет как в расписании
        {
            group.numberOfPreviousCabinet = group.numberOfCurrentCabinet;
            group.numberOfCurrentCabinet = currentCabinet;
            PathOfWay coordinatesOfOldCabinet = mapOfTheFloor->getCoordinatesOfCabinet(group.numberOfPreviousCabinet);
            PathOfWay coordinatesOfNewCabinet = mapOfTheFloor->getCoordinatesOfCabinet(group.numberOfCurrentCabinet);
            vector<PathOfWay> wayTowardsTheCabinet = goTowardsPoint(coordinatesOfOldCabinet.X, coordinatesOfOldCabinet.Y, coordinatesOfNewCabinet.X, coordinatesOfNewCabinet.Y, true);
            //vector<Cabinet> allCabinets = mapOfTheFloor->getAllCabinets();
            for(int i = 0; i < group.People.size(); i ++)
            {
                //идём к точке выхода из кабинета
                vector<PathOfWay> wayFromTheCabinet = goTowardsPoint(group.People[i].GetPositionX(), group.People[i].GetPositionY(), coordinatesOfOldCabinet.X, coordinatesOfOldCabinet.Y, false);

                wayFromTheCabinet.insert(wayFromTheCabinet.end(), wayTowardsTheCabinet.begin(), wayTowardsTheCabinet.end());//вроде как совместит вектора, проверить!

                int oldPlace = group.People[i].getNumberOfPlaceInTheCabinet();
                mapOfTheFloor->cabinets[group.numberOfPreviousCabinet].used[oldPlace] = false;
                group.People[i].setNumberOfPlaceInTheCabinet(-1);//отмечаю, что студент не сидит
                group.amountOfPeopleInTheCabinet --;//уменьшаем число людей в кабинете
                group.People[i].SetWay(wayFromTheCabinet);//устанавливаю маршрут

            }

        }



    for (int i = 0; i < group.People.size() && group.amountOfPeopleInTheCabinet != group.People.size(); i ++)
    {
        //проверить нужды и если надо пустить по пути в туалет или столовку
        if(group.People[i].isWayEmpty() && group.People[i].getNumberOfPlaceInTheCabinet() == -1/*не надо в туалет и не надо есть*/)//если пути нет и нет кабинета - значит дошёл до кабинета
        {
            vector<PathOfWay> wayTowardsDesk;
            wayTowardsDesk = goToYourPlace(group.numberOfCurrentCabinet, i);
            group.amountOfPeopleInTheCabinet ++;//увеличиваем число людей в кабинете
        }
    }





    currentTime.AddMinute(10);
    group.groupMakeStep();
    ui->simulationTime->setText(currentTime.ToString());

}


void Simulation::on_loadMapButton_clicked()
{
    disconnect(timer, SIGNAL(timeout()), this, SLOT(stepModel()));
    QFileDialog choseFile;
    QString filename = QFileDialog::getSaveFileName(this, tr("Chose document"), QDir::currentPath(), tr("Documents (*.txt)") );
    //QString path = choseFile.getSaveFileUrl(0, "Open dialog", " ");
    QFile file(filename);
    if(file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString currentString;
        currentString = in.readLine(50);
        int width = currentString.toInt();
        currentString = in.readLine(50);
        int height = currentString.toInt();
        file.close();
        FloorMap* newMap = new FloorMap(width, height, filename);
        mapOfTheFloor = newMap;
        paintHelper = ui->mapWidget;
        //paintHelper->setKeepFloor(newMap);
        paintHelper->setKeepFloor(mapOfTheFloor, filename);
        paintHelper->draw();
    }
    int entryXCoordinate = 18, entryYCoordinate = 18;//пока что так, затем брать из полей соответствующих, они будут в PathOfWay
    Student filler;
    filler.SetPositions(entryXCoordinate, entryYCoordinate);
    vector<vector<int>> forTheWay(mapOfTheFloor->getFloorForTheWay());//массив для волнового алгоритма
    for (int i = 0; i < mapOfTheFloor->getAmountOfCabinets(); i ++)//проходим по всем кабинетам
    {
        PathOfWay coordinatesOfCabinet = mapOfTheFloor->getCoordinatesOfCabinet(i);//получаем координаты i-го кабинета
        vector<PathOfWay> myWay;//новый путь

        bool needToFillMap;
        if(i == 0)
            needToFillMap = true;//для первого кабинета карту нужно заполнить
        else
            needToFillMap = false;//для остальных карта готова

        //myWay = goTowardsPoint(i, entryXCoordinate, entryYCoordinate);//в myWay путь до i-го кабинета,
        filler.SetPositions(entryXCoordinate, entryYCoordinate);
        myWay = filler.MakeWay(coordinatesOfCabinet.X, coordinatesOfCabinet.Y, &forTheWay, needToFillMap);//в myWay путь до i-го кабинета,
                                                                                                           //после первого вызова в forTheWay карта заполненная для других
        //нахождение клетки, которая будет находится сразу за входом в кабинет
        PathOfWay lastOne = myWay[myWay.size() - 1];
        PathOfWay preLastOne = myWay[myWay.size() - 2];
        int newX, newY;
        if(lastOne.X < preLastOne.X)
        {
            newX = lastOne.X - 1;
            newY = lastOne.Y;
        }

        if(lastOne.X > preLastOne.X)
        {
            newX = lastOne.X + 1;
            newY = lastOne.Y;
        }

        if(lastOne.Y < preLastOne.Y)
        {
            newX = lastOne.X;
            newY = lastOne.Y + 1;
        }

        if(lastOne.Y > preLastOne.Y)
        {
            newX = lastOne.X;
            newY = lastOne.Y - 1;
        }
        PathOfWay afterLastOne(newX, newY);
        myWay.push_back(afterLastOne);//добавляем новый блок в пути в конец пути
        filler.SetPositions(afterLastOne.X, afterLastOne.Y);//filler в кабинете сразу после входа в него
        vector<vector<int>> forTheWayModified(mapOfTheFloor->getFloorForTheWay());
        forTheWayModified[coordinatesOfCabinet.X][coordinatesOfCabinet.Y] = -1;//отмечаем вход в кабинет как стену, чтобы волновой алгоритм искал только в кабинете
        filler.MakeWayInTheCabinet(&forTheWayModified, mapOfTheFloor, i);//идёт заполнение информации об этом кабинете
    }

    MyTime newCurrentTime;
    currentTime = newCurrentTime;
    timer->setInterval(200);
    connect(timer, SIGNAL(timeout()), this, SLOT(stepModel()));
    timer->start();
    ui->simulationTime->setText(currentTime.ToString());
}

vector<PathOfWay> Simulation::goTowardsPoint(int xFrom, int yFrom, int xInto, int yInto, bool needToGoInside)//составляет путь от точки с координатами xFrom yFrom до точки с координатами
{
     vector<PathOfWay> myWay;//новый путь
    vector<vector<int>> forTheWay(mapOfTheFloor->getFloorForTheWay());//массив для волнового алгоритма
    //PathOfWay coordinatesOfCabinet = mapOfTheFloor->getCoordinatesOfCabinet(numberOfCabinet);
    Student whoWalks;
    whoWalks.SetPositions(xFrom, yFrom);
    myWay = whoWalks.MakeWay(xInto, yInto, &forTheWay, true);//в myWay будет от путь от текущего положения человека до входа в кабинет
    //добавляем ещё один блок в пути, чтобы путь заканчивался в кабинете(1 шаг в него)
    if(needToGoInside)
    {
        PathOfWay lastOne = myWay[myWay.size() - 1];
        PathOfWay preLastOne = myWay[myWay.size() - 2];
        int newX, newY;
        if(lastOne.X < preLastOne.X)
        {
            newX = lastOne.X - 1;
            newY = lastOne.Y;
        }

        if(lastOne.X > preLastOne.X)
        {
            newX = lastOne.X + 1;
            newY = lastOne.Y;
        }

        if(lastOne.Y < preLastOne.Y)
        {
            newX = lastOne.X;
            newY = lastOne.Y + 1;
        }

        if(lastOne.Y > preLastOne.Y)
        {
            newX = lastOne.X;
            newY = lastOne.Y - 1;
        }
        PathOfWay afterLastOne(newX, newY);
        myWay.push_back(afterLastOne);//добавляем новый блок в пути в конец пути
    }
    return myWay;
}
vector<PathOfWay> Simulation::goToYourPlace(int numberOfCabinet, int numberOfStudent)//возвращает путь к свободному месту за партой в кабинете под номером numberOfCabinet
{
    for(int i = 0; i < mapOfTheFloor->cabinets[numberOfCabinet].CountOfStudentPlace; i ++)//прохожу по всем местам для студентов
    {
        if(mapOfTheFloor->cabinets[numberOfCabinet].used[i] == false)//если i-ая парта не использована
        {
            group.People[numberOfStudent].setNumberOfPlaceInTheCabinet(i);
            mapOfTheFloor->cabinets[numberOfCabinet].used[i] = true;//отмечаю место как занятое
            return mapOfTheFloor->cabinets[numberOfCabinet].Ways[i];//возвращаем путь к месту за партой
        }
    }

}


