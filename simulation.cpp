#include "simulation.h"
#include "ui_simulation.h"
#include "painthelper.h"
#include "QWidget"
Simulation::Simulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);
    PaintHelper2 *paintHelper;
    paintHelper = ui->mapWidget;
    //paintHelper->setFloorPlan(floorMap);
    paintHelper->draw();

    connect(timer, SIGNAL(timeout()), this, SLOT(stepModel()));
}

Simulation::~Simulation()
{
    delete ui;
}

void Simulation::stepModel()
{
    int chance = rand() % 100;
    if(chance >= 95)
    {

    }
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



