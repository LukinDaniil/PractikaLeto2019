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
    for(int i = 0; i < /*floorMap->getWidth()*/41*BLOCK_WIDTH; i += BLOCK_WIDTH)
    {
        for(int j = 0; j < /*floorMap->getHeight()*/33*BLOCK_WIDTH; j += BLOCK_WIDTH)
            painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
    }

    //painter->drawLine(0, 0, /*floorMap->getWidth()*/16*BLOCK_WIDTH, 0);
    //painter->drawLine(0, 0, 0, /*floorMap->getHeight()*/8*BLOCK_WIDTH);
    //painter->drawLine(0, /*floorMap->getHeight()*/8*BLOCK_WIDTH, /*floorMap->getWidth()*/16*BLOCK_WIDTH - 1*BLOCK_WIDTH, /*floorMap->getHeight()*/8*BLOCK_WIDTH - 1*BLOCK_WIDTH);
    //painter->drawLine(/*floorMap->getWidth()*/16*BLOCK_WIDTH, 0, /*floorMap->getWidth()*/16*BLOCK_WIDTH - 1*BLOCK_WIDTH, /*floorMap->getHeight()*/8*BLOCK_WIDTH - 1*BLOCK_WIDTH);
    //int width = floorMap->getWidth() / BLOCK_WIDTH;
    //int height = floorMap->getHeight() / BLOCK_WIDTH;


    //QFile file("F:\\Projects\\PractikaLeto2019\\Files\\MainBuildingFloor");//открываем файл с картой этажа
    //QFile file("MainBuildingFloor.txt");//открываем файл с картой этажа
    QString fileName = "F:/Projects/PractikaLeto2019/Files/MainBuildingFloor.txt";
    QFile file(fileName);
    if(file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
    //if (file.exists())
    //{
        //if (file.exists())
        //{
            QString currentString;
            //можно в дальнейшем устанавливать в файле на 3 строку сразу
            currentString = in.readLine(50);
            int width = currentString.toInt();
            currentString = in.readLine(50);
            int height = currentString.toInt();
            int yCoordinate = 0;//y координата
            vector<vector<int>> floor (width, vector<int> (height, 0));
            //floor.resize(width*height);
            for(int i = 0; i < width; i ++)
                for(int j = 0; j < height; j ++)
                    floor[i][j] = 0;
            while(!in.atEnd())
            {
                //currentString = "";
                currentString=in.readLine(50);//считываю строку
                for(int xCoordinate = 0; xCoordinate < currentString.size(); xCoordinate++)//проходим по currentString
                {
                    //в дальнейшем заменить на case для спавна различных объектов

                    if(currentString[xCoordinate] == "0")//если в файле в данном месте стоит 1, то там создаём блок
                    {
                        floor[xCoordinate][yCoordinate] = 0;
                    }

                    if(currentString[xCoordinate] == "1")//если в файле в данном месте стоит 1, то там создаём блок
                    {
                        floor[xCoordinate][yCoordinate] = 1;
                    }

                    if(currentString[xCoordinate] == "2")//если в файле в данном месте стоит 1, то там создаём блок
                    {
                        floor[xCoordinate][yCoordinate] = 2;
                    }

                    if(currentString[xCoordinate] == "3")//если в файле в данном месте стоит 1, то там создаём блок
                    {
                        floor[xCoordinate][yCoordinate] = 3;
                    }

                    if(currentString[xCoordinate] == "4")//если в файле в данном месте стоит 1, то там создаём блок
                    {
                        floor[xCoordinate][yCoordinate] = 4;
                    }

                    if(currentString[xCoordinate] == "5")//если в файле в данном месте стоит 1, то там создаём блок
                    {
                        floor[xCoordinate][yCoordinate] = 5;
                    }

                    if(currentString[xCoordinate] == "6")//если в файле в данном месте стоит 1, то там создаём блок
                    {
                        floor[xCoordinate][yCoordinate] = 6;
                    }
                }
                yCoordinate++;//переходим на следующую строку
                //добавить обновление формы или найти иной сп
            }
        //}



        /*
            0 - свободно
            1 - стена
            2 - парта
            3 - дорожка
            4 - свободное место для студента
            5 - свободное место для препода
            6 - вход в аудиторию
        */
        painter->setBrush(Qt::blue);
        int indexI = 0, indexJ = 0;
        for(int i = 0; i < width*BLOCK_WIDTH; i += BLOCK_WIDTH)
        {
            indexJ = 0;
            for(int j = 0; j < height*BLOCK_WIDTH; j += BLOCK_WIDTH)
            {
                if(floor[indexI][indexJ] == 1)
                {
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
                    painter->setBrush(Qt::blue);
                }
                if(floor[indexI][indexJ] == 2)
                {
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
                    painter->setBrush(Qt::yellow);
                }
                if(floor[indexI][indexJ] == 3)
                {
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
                    painter->setBrush(Qt::red);
                }
                if(floor[indexI][indexJ] == 4)
                {
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
                    painter->setBrush(Qt::lightGray);
                }
                if(floor[indexI][indexJ] == 5)
                {
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
                    painter->setBrush(Qt::gray);
                }
                if(floor[indexI][indexJ] == 6)
                {
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
                    painter->setBrush(Qt::green);
                }
                indexJ++;
            }
            indexI++;
        }
    //}
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
