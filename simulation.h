#ifndef SIMULATION_H
#define SIMULATION_H

#include <QMainWindow>

namespace Ui {
class Simulation;
}

class Simulation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Simulation(QWidget *parent = 0);
    ~Simulation();

private:
    Ui::Simulation *ui;
};

#endif // SIMULATION_H
