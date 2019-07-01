#ifndef PAINTHELPER2_H
#define PAINTHELPER2_H

#include <QWidget>
#include "QPainter"
#include "floormap.h"
class PaintHelper2 : public QWidget
{
    Q_OBJECT
private:
    FloorMap keepFloor;
    const int BLOCK_WIDTH = 10;

public:
    //FloorMap* tempFloorMap;//для хранения карты для последующего рисования
    explicit PaintHelper2(QWidget *parent = nullptr);
    PaintHelper2();
    void draw(FloorMap mapForDrawing);
    void paintEvent(QPaintEvent* event);


    // QWidget interface
private:
    void drawCells();
    void drawObjects();
};

#endif // PAINTHELPER2_H
