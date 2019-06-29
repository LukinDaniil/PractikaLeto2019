#include "painthelper.h"

PaintHelper::PaintHelper(QWidget *parent) : QScrollArea(parent)
{

}

void PaintHelper::draw()
{
    drawCells();
    drawObjects();
}

void PaintHelper::paintEvent(QPaintEvent */*event*/)
{
    QPainter paint(this);
    paint.drawPixmap(0, 0, *buffer);
}

void PaintHelper::setFloorPlan(class floorMap *floorMap)
{
    this->floorMap = floorMap;
    buffer = new QPixmap(floorMap->getWidth(), floorMap->getHeight());
    buffer->fill(Qt::white);
    painter = new QPainter(buffer);
}

void PaintHelper::drawCells()
{
    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);
     for(int i = 0; i < floorMap->getWidth(); i += BLOCK_WIDTH)
     {
         for(int j = 0; j < floorMap->getHeight(); j += BLOCK_WIDTH)
             painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
     }
}
