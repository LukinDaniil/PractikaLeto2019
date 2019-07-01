#include "painthelper2.h"
#include "simulation.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
PaintHelper2::PaintHelper2(QWidget *parent) : QWidget(parent)
{

}

PaintHelper2::PaintHelper2()
{

}



void PaintHelper2::draw(FloorMap* mapForDrawing)
{

    repaint();
}

void PaintHelper2::paintEvent(QPaintEvent *e)
{
            QPainter* painter = new QPainter(this);
            painter->setPen(Qt::black);
            painter->setBrush(Qt::white);
            int widthOfMap = keepFloor.getWidth();
            int heightOfMap = keepFloor.getHeight();
            for(int i = 0; i < widthOfMap*BLOCK_WIDTH; i += BLOCK_WIDTH)
            {
                for(int j = 0; j < heightOfMap*BLOCK_WIDTH; j += BLOCK_WIDTH)
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
            }

        /*
            0 - свободно
            1 - стена
            2 - парта
            3 - дорожка
            4 - свободное место для студента
            5 - свободное место для препода
            6 - вход в аудиторию
        */
        int indexI = 0, indexJ = 0;
        for(int i = 0; i < widthOfMap*BLOCK_WIDTH; i += BLOCK_WIDTH)
        {
            indexJ = 0;
            for(int j = 0; j < heightOfMap*BLOCK_WIDTH; j += BLOCK_WIDTH)
            {
                if(keepFloor.getIJFloorMap(i, j) == 1)
                {
                    painter->setBrush(Qt::blue);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(keepFloor.getIJFloorMap(i, j) == 2)
                {
                    painter->setBrush(Qt::yellow);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(keepFloor.getIJFloorMap(i, j) == 3)
                {
                    painter->setBrush(Qt::red);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(keepFloor.getIJFloorMap(i, j) == 4)
                {
                    painter->setBrush(Qt::magenta);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(keepFloor.getIJFloorMap(i, j) == 5)
                {
                    painter->setBrush(Qt::gray);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(keepFloor.getIJFloorMap(i, j) == 6)
                {
                    painter->setBrush(Qt::green);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                indexJ++;
            }
            indexI++;
        }

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
