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

}

Simulation::~Simulation()
{
    delete ui;
}

void Simulation::stepModel()
{

    //каждый шаг совершаются действия на карте, изменяется mapOfTheFloor, после этого карта опять рисуется для отображения изменений
    //group.groupMakeStep();
    //paintHelper->setKeepFloor(mapOfTheFloor);
    //paintHelper->changeMapAccordingWithHumans(group);
    //paintHelper->draw();
    currentTime.AddMinute(1);
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
    //продумать ресет таймера
    //добавить сохранение координат входа в институт пока что его координаты entryXCoordinate и entryYCoordinate
    int entryXCoordinate = 20, entryYCoordinate = 2;//пока что так, затем брать из полей соответствующих, они будут в PathOfWay
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
        myWay = filler.MakeWay(coordinatesOfCabinet.X, coordinatesOfCabinet.Y, &forTheWay, needToFillMap);//в myWay путь до i-го кабинета,
                                                                                                           //после первого вызова в forTheWay карта заполненная для других
        filler.SetPositions(myWay[size()])

    }



    MyTime newCurrentTime;
    currentTime = newCurrentTime;
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(stepModel()));
    timer->start();
    ui->simulationTime->setText(currentTime.ToString());
}

vector<PathOfWay> Simulation::goTowardsCabinet(int numberOfCabinet, int xFrom, int yFrom)//в какой кабинет и кто идёт
{
    vector<PathOfWay> myWay;//новый путь
    vector<vector<int>> forTheWay(mapOfTheFloor->getFloorForTheWay());//массив для волнового алгоритма
    PathOfWay coordinatesOfCabinet = mapOfTheFloor->getCoordinatesOfCabinet(numberOfCabinet);
    Student whoWalks;
    whoWalks.SetPositions(xFrom, yFrom);
    myWay = whoWalks.MakeWay(coordinatesOfCabinet.X, coordinatesOfCabinet.Y, &forTheWay, true);//в myWay будет от путь от текущего положения человека до входа в кабинет
    //добавляем ещё один блок в пути, чтобы путь заканчивался в кабинете(1 шаг в него)
    PathOfWay lastOne = myWay[myWay.size()];
    PathOfWay preLastOne = myWay[myWay.size() - 1];
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
    return myWay;
}

vector<vector<PathOfWay>> Simulation::goToYourPlace(int xFrom, int yFrom)//человек уже в кабинете, так что номер известен
{

}
