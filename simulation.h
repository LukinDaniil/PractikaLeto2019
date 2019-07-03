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
    vector<PathOfWay> goTowardsCabinet(int numberOfCabinet, int xFrom, int yFrom);//метод ищет путь от места за пределами аудитории, до места, на шаг дальше входа в аудиторию
private slots:
    void stepModel();

    void on_loadMapButton_clicked();

private: signals:
    void FilePath(const QString &str);

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


