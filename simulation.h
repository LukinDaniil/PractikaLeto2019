#ifndef SIMULATION_H
#define SIMULATION_H

#include <QMainWindow>
#include "floormap.h"
#include "painthelper2.h"
#include "QTimer"
namespace Ui
{
class Simulation;
}

class Simulation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = nullptr);
    ~Simulation();

private slots:
    void stepModel();

private:
    Ui::Simulation *ui;
    //FloorMap* floorMap;
    PaintHelper2* paintHelper;
    FloorMap* mapOfTheFloor;
    QTimer* timer = new QTimer();
    const int FPS = 30;
};

#endif // SIMULATION_H


/*
#ifndef SIMULATION_H
#define SIMULATION_H

#include <QMainWindow>
#include "floormap.h"
#include "painthelper.h"
namespace Ui
{
class Simulation;
}

class Simulation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = 0);
    ~Simulation();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Simulation *ui;
    floorMap* floorMap;
    PaintHelper* paintHelper;
};

#endif // SIMULATION_H
*/
