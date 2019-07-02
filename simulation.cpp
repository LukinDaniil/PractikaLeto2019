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
    QFile file(fileName);
    if(file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString currentString;
        currentString = in.readLine(50);
        int width = currentString.toInt();
        currentString = in.readLine(50);
        int height = currentString.toInt();
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
    for(int i = 1; i <= 4; i ++)
    {
        PathOfWay newWay(i, 1);
        myWay.push_back(newWay);
    }
    group.DefineWay(myWay);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(stepModel()));
    timer->start();
}

Simulation::~Simulation()
{
    delete ui;
}

void Simulation::stepModel()
{
    /*
    int chance = rand() % 100;
    if(chance >= 95)
    {

    }
    //каждый шаг совершаются действия на карте, изменяется mapOfTheFloor, после этого карта опять рисуется для отображения изменений
    */
    group.groupMakeStep();
    paintHelper->setKeepFloor(mapOfTheFloor);
    paintHelper->changeMapAccordingWithHumans(group);
    paintHelper->draw();

}


/*
#include "simulation.h"
#include "ui_simulation.h"
#include "painthelper.h"
Simulation::Simulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);
    PaintHelper *paintHelper;
    paintHelper = ui->scrollArea;
    paintHelper->setFloorPlan(floorMap);
    paintHelper->draw();

}

Simulation::~Simulation()
{
    delete ui;
}
*/

