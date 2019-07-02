#ifndef SIMULATION_H
#define SIMULATION_H

#include <QMainWindow>
#include "floormap.h"
#include "painthelper2.h"
#include "QTimer"
#include "QTextStream"
#include "timesheet.h"
#include "teacher.h"
#include "student.h"
#include "group.h"
#include <vector>
#include "enums.h"
#include "mytime.h"
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
    PaintHelper2* paintHelper;
    FloorMap* mapOfTheFloor;
    vector<vector<int>> mapForTheWay;
    vector <Teacher> teachers;
    Group group;
    QTimer* timer = new QTimer();
    MyTime currentTime;
    const int FPS = 30;
};

#endif // SIMULATION_H


