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


