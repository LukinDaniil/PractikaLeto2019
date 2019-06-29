#include "painthelper2.h"

PaintHelper2::PaintHelper2(QWidget *parent) : QWidget(parent)
{

}

PaintHelper2::PaintHelper2()
{

}

void PaintHelper2::draw()
{
    repaint();
}

void PaintHelper2::paintEvent(QPaintEvent *e)
{
    //QPainter paint(this);
    //paint.drawPixmap(0, 0, *buffer);


    QPainter* painter = new QPainter(this);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);
    for(int i = 0; i < floorMap->getWidth(); i += BLOCK_WIDTH)
    {
        for(int j = 0; j < floorMap->getHeight(); j += BLOCK_WIDTH)
            painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
    }

    painter->drawLine(0, 0, floorMap->getWidth(), 0);
    painter->drawLine(0, 0, 0, floorMap->getHeight());
    painter->drawLine(0, floorMap->getHeight(), floorMap->getWidth() - 1, floorMap->getHeight() - 1);
    painter->drawLine(floorMap->getWidth(), 0, floorMap->getWidth() - 1, floorMap->getHeight() - 1);
    int width = floorMap->getWidth() / BLOCK_WIDTH;
    int height = floorMap->getHeight() / BLOCK_WIDTH;

    painter->setBrush(Qt::blue);
    /*for(int i = 0; i < width; i += BLOCK_WIDTH)
    {
        for(int j = 0; j < height; j += BLOCK_WIDTH)
            if(floor[i][j] == 1)
                painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
    }*/
}

void PaintHelper2::setFloorPlan(class floorMap *floorMap)
{
    /*
    this->floorMap = floorMap;
    buffer = new QPixmap(floorMap->getWidth(), floorMap->getHeight());
    buffer->fill(Qt::white);
    painter = new QPainter(buffer);
    */
}

void PaintHelper2::drawCells()
{
    /*
    painter->setPen(Qt::black);
    painter->setBrush(Qt::white);
    for(int i = 0; i < floorMap->getWidth(); i += BLOCK_WIDTH)
    {
        for(int j = 0; j < floorMap->getHeight(); j += BLOCK_WIDTH)
            painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
    }
    repaint();
    */
}

void PaintHelper2::drawObjects()
{

}
