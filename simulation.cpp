#include "simulation.h"
#include "ui_simulation.h"
//#include "painthelper.h"
#include "QWidget"
#include "qfile.h"
#include "floormap.h"
#include "vector"
Simulation::Simulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);


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

    group.addStudent(1, 1);
    paintHelper->changeMapAccordingWithHumans(group);
    paintHelper->draw();
    vector<PathOfWay> myWay;
    /*
    for(int i = 1; i <= 4; i ++)
    {
        PathOfWay newWay(i, 1);
        myWay.push_back(newWay);
    }
    */
    ///*
    vector<vector<int>> forTheWay(mapOfTheFloor->getFloorForTheWay());
    myWay = group.People[0].MakeWay(4, 1, &forTheWay);
    //*/
    group.DefineWay(myWay);
    //group.DefineWay(myWay);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(stepModel()));
    timer->start();
    ui->simulationTime->setText(currentTime.ToString());
}

Simulation::~Simulation()
{
    delete ui;
}

void Simulation::stepModel()
{

    //каждый шаг совершаются действия на карте, изменяется mapOfTheFloor, после этого карта опять рисуется для отображения изменений
    group.groupMakeStep();
    paintHelper->setKeepFloor(mapOfTheFloor);
    paintHelper->changeMapAccordingWithHumans(group);
    paintHelper->draw();
    currentTime.AddMinute(1);
    ui->simulationTime->setText(currentTime.ToString());
}

