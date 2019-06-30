#include "simulation.h"
#include "ui_simulation.h"
//#include "painthelper.h"
#include "QWidget"
#include "qfile.h"
#include "floormap.h"
Simulation::Simulation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulation)
{
    ui->setupUi(this);

    PaintHelper2 *paintHelper;
    paintHelper = ui->mapWidget;
    //paintHelper->setFloorPlan(floorMap);//считывание и запись ширины и высоты карты
    /*
    QFile file("F:\\Projects\\PractikaLeto2019\\Files\\MainBuildingFloor");//открываем файл с картой этажа
    if (file.exists())
    {
        QString currentString;
        currentString = file.readLine();
        int newWidth = currentString.toInt();
        currentString = file.readLine();
        int newHeight = currentString.toInt();
        FloorMap* newFloor = new FloorMap(newWidth, newHeight);
        newFloor->createFloorMap();//добавить передачу пути/имени файла
        paintHelper->tempFloorMap = newFloor;//перегрузить, чтобы копировались поля а не ссылка

    }
    */
    paintHelper->draw();
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

