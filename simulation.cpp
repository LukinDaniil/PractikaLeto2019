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
    on_loadMapButton_clicked();
    int entryXCoordinate = 18, entryYCoordinate = 18;
    group.numberOfCurrentCabinet = 0;
    vector<PathOfWay> groupWay = goTowardsCabinet(group.numberOfCurrentCabinet, entryXCoordinate, entryYCoordinate, true);
    group.groupWay = groupWay;
}

Simulation::~Simulation()
{
    delete ui;
}

void Simulation::stepModel()
{
    //каждый шаг совершаются действия на карте, изменяется mapOfTheFloor, после этого карта опять рисуется для отображения изменений
    /*
    group.groupMakeStep();
    group.groupMakeStep();
    if(group.People.size() < 2)
    {
        group.addStudent(18, 18);
        int hisIndex = group.People.size() - 1;
        group.People[hisIndex].SetWay(group.groupWay);
    }

    paintHelper->changeMapAccordingWithHumans(group);
    */
    paintHelper->setKeepFloor(mapOfTheFloor);
    paintHelper->draw();
    currentTime.AddMinute(1);
    ui->simulationTime->setText(currentTime.ToString());
    /*
    vector<Cabinet> allCabinets = mapOfTheFloor->getAllCabinets();

    for(int j = 0; j < group.People.size(); j ++)
        if(group.People[j].isWayEmpty() && group.People[j].getNumberOfPlaceInTheCabinet() == -1)
        {
            for(int i = 0; i < allCabinets[0].CountOfStudentPlace; i ++)//прохожу по всем партам
            {
                if(allCabinets[0].used[i] == false)//если парта не использована
                {
                    group.DefineWay(allCabinets[0].Ways[i]);//записываем путь к данной парте
                    allCabinets[0].used[i] = true;
                }
            }
        }
    */
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
    //продумать ресет таймера
    //добавить сохранение координат входа в институт пока что его координаты entryXCoordinate и entryYCoordinate
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

        //myWay = goTowardsCabinet(i, entryXCoordinate, entryYCoordinate);//в myWay путь до i-го кабинета,
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
        //myWay.push_back(afterLastOne);//добавляем новый блок в пути в конец пути
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

vector<PathOfWay> Simulation::goTowardsCabinet(int xFrom, int yFrom, int xInto, int yInto, bool needToGoInside)//составляет путь от точки с координатами xFrom yFrom до точки с координатами
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
vector<PathOfWay> Simulation::goToYourPlace(int numberOfCabinet)//возвращает путь к свободной парте в кабинете под номером numberOfCabinet
{
    vector<Cabinet> allCabinets = mapOfTheFloor->getAllCabinets();
    for(int i = 0; i < allCabinets[numberOfCabinet].CountOfStudentPlace; i ++)//прохожу по всем местам для студентов
    {
        if(allCabinets[numberOfCabinet].used[i] == false)//если i-ая парта не использована
        {
            allCabinets[numberOfCabinet].used[i] = true;//отмечаю место как занятое
            return allCabinets[0].Ways[i];//возвращаем путь к этой парте

        }
    }

}


