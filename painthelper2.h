#ifndef PAINTHELPER2_H
#define PAINTHELPER2_H

#include <QWidget>
#include "QPainter"
#include "floormap.h"
#include "group.h"
#include "enums.h"
class PaintHelper2 : public QWidget
{
    Q_OBJECT
private:
    int floorWidth;
    int floorHeight;
    int** storedFloor;
    const int BLOCK_WIDTH = 10;
    QString pathToFile;
public:
    //FloorMap* tempFloorMap;//для хранения карты для последующего рисования
    explicit PaintHelper2(QWidget *parent = nullptr);
    PaintHelper2();
    void draw();
    void paintEvent(QPaintEvent* event);
    void setKeepFloor(FloorMap* newKeepMap);
    void setKeepFloor(FloorMap* newKeepMap, QString newPathToFile);
    void changeMapAccordingWithHumans(Group group);
    // QWidget interface
private:
    void drawCells();
    void drawObjects();
};

#endif // PAINTHELPER2_H
