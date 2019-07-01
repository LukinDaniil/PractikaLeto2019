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

    paintHelper;
    paintHelper = ui->mapWidget;
    mapOfTheFloor.createFloorMap();
    paintHelper->draw(mapOfTheFloor);
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

