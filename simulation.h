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
