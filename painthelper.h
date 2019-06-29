#ifndef PAINTHELPER_H
#define PAINTHELPER_H
#include "QWidget"
#include "QPainter"
#include "floormap.h"
#include "QScrollArea"
class PaintHelper : public QScrollArea
{
    Q_OBJECT
private:
    QPixmap *buffer;
    floorMap* floorMap;
    const int BLOCK_WIDTH = 10;
    QPainter* painter;

public:
    explicit PaintHelper(QWidget *parent = nullptr);
    PaintHelper();
    void draw();
    void paintEvent(QPaintEvent* event);
    void setFloorPlan(class floorMap* floorMap);

    // QWidget interface
private:
    void drawCells();
    void drawObjects();
};

#endif // PAINTHELPER_H
