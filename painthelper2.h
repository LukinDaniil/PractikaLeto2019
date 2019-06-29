#ifndef PAINTHELPER2_H
#define PAINTHELPER2_H

#include <QWidget>

#include "QPainter"
#include "floormap.h"
class PaintHelper2 : public QWidget
{
    Q_OBJECT
private:
    QPixmap *buffer;
    floorMap* floorMap;
    const int BLOCK_WIDTH = 10;
    //QPainter* painter;

public:
    explicit PaintHelper2(QWidget *parent = nullptr);
    PaintHelper2();
    void draw();
    void paintEvent(QPaintEvent* event);
    void setFloorPlan(class floorMap* floorMap);

    // QWidget interface
private:
    void drawCells();
    void drawObjects();
};

#endif // PAINTHELPER2_H
