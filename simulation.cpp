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
    }
    paintHelper = ui->mapWidget;
    paintHelper->draw(*mapOfTheFloor);
    //connect(timer, SIGNAL(timeout()), this, SLOT(stepModel()));
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


    paintHelper->draw();
    */
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

