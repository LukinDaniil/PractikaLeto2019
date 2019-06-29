#include "simulation.h"
#include "ui_simulation.h"

Simulation::Simulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);
}

Simulation::~Simulation()
{
    delete ui;
}

void Simulation::on_pushButton_clicked()
{

}
