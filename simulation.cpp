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

    /*
    QString fileName = "F:/Projects/PractikaLeto2019/Files/MainBuildingFloor.txt";
    //QString fileName = "C:/Users/aleks/Documents/PractikaLeto2019/MainBuildingFloor.txt";
    QFile file(fileName);
    if(file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString currentString;
        currentString = in.readLine(50);
        int width = currentString.toInt();
        currentString = in.readLine(50);
        int height = currentString.toInt();
        file.close();
        FloorMap* newMap = new FloorMap(width, height);
        mapOfTheFloor = newMap;
        paintHelper = ui->mapWidget;
        //paintHelper->setKeepFloor(newMap);
        paintHelper->setKeepFloor(mapOfTheFloor);
        paintHelper->draw();
    }
    */
    /*
    group.addStudent(1, 1);
    paintHelper->changeMapAccordingWithHumans(group);
    paintHelper->draw();
    vector<PathOfWay> myWay;
    vector<vector<int>> forTheWay(mapOfTheFloor->getFloorForTheWay());
    myWay = group.People[0].MakeWay(4, 1, &forTheWay);
    group.DefineWay(myWay);

    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(stepModel()));
    timer->start();
    ui->simulationTime->setText(currentTime.ToString());
    */
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
    myWay = whoWalks.MakeWay(coordinatesOfCabinet.X, coordinatesOfCabinet.Y, &forTheWay);//в myWay будет от путь от текущего положения человека до входа в кабинет
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

