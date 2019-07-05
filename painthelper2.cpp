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
void PaintHelper2::changeMapAccordingWithHumans(Group group)
{
    Enums e;
    for (int i = 0; i < group.People.size(); i++)
    {
        storedFloor[group.People[i].GetPositionX()][group.People[i].GetPositionY()] = e.Student;
    }
}

void PaintHelper2::setKeepFloor(FloorMap* newKeepMap, QString newPathToFile)
{
    pathToFile = newPathToFile;
    floorWidth = newKeepMap->getWidth();
    floorHeight = newKeepMap->getHeight();
    storedFloor = newKeepMap->getFloorMap();
}

void PaintHelper2::setKeepFloor(FloorMap* newKeepMap)
{
    floorWidth = newKeepMap->getWidth();
    floorHeight = newKeepMap->getHeight();
    storedFloor = newKeepMap->getFloorMap();
}

void PaintHelper2::draw()
{
    repaint();
}

void PaintHelper2::paintEvent(QPaintEvent *e)
{
    //QPainter paint(this);
    //paint.drawPixmap(0, 0, *buffer);




    //painter->drawLine(0, 0, /*floorMap->getWidth()*/16*BLOCK_WIDTH, 0);
    //painter->drawLine(0, 0, 0, /*floorMap->getHeight()*/8*BLOCK_WIDTH);
    //painter->drawLine(0, /*floorMap->getHeight()*/8*BLOCK_WIDTH, /*floorMap->getWidth()*/16*BLOCK_WIDTH - 1*BLOCK_WIDTH, /*floorMap->getHeight()*/8*BLOCK_WIDTH - 1*BLOCK_WIDTH);
    //painter->drawLine(/*floorMap->getWidth()*/16*BLOCK_WIDTH, 0, /*floorMap->getWidth()*/16*BLOCK_WIDTH - 1*BLOCK_WIDTH, /*floorMap->getHeight()*/8*BLOCK_WIDTH - 1*BLOCK_WIDTH);
    //int width = floorMap->getWidth() / BLOCK_WIDTH;
    //int height = floorMap->getHeight() / BLOCK_WIDTH;


    //QFile file("F:\\Projects\\PractikaLeto2019\\Files\\MainBuildingFloor");//открываем файл с картой этажа
    //QFile file("MainBuildingFloor.txt");//открываем файл с картой этажа
    //QString fileName = "C:/Users/aleks/Documents/PractikaLeto2019/MainBuildingFloor.txt";
    //QString fileName = "F:/Projects/PractikaLeto2019/Files/MainBuildingFloor.txt";
    QFile file(pathToFile);
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
            currentString = in.readLine(50);
            QPainter* painter = new QPainter(this);
            painter->setPen(Qt::black);
            painter->setBrush(Qt::white);
            //int widthOfMap = keepFloor->getWidth();
            //int heightOfMap = keepFloor->getHeight();
            for(int i = 0; i < /*widthOfMap*/floorWidth*BLOCK_WIDTH; i += BLOCK_WIDTH)
            {
                for(int j = 0; j < /*heightOfMap*/floorHeight*BLOCK_WIDTH; j += BLOCK_WIDTH)
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);
            }

        /*

        */
        int indexI = 0, indexJ = 0;
        for(int i = 0; i < /*widthOfMap*/floorWidth*BLOCK_WIDTH; i += BLOCK_WIDTH)
        {
            indexJ = 0;
            Enums e;
            for(int j = 0; j < /*heightOfMap*/floorHeight*BLOCK_WIDTH; j += BLOCK_WIDTH)
            {
                if(storedFloor[indexI][indexJ] == e.Wall)
                {
                    painter->setBrush(Qt::black);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(storedFloor[indexI][indexJ] == e.Desk)
                {
                    painter->setBrush(Qt::yellow);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(storedFloor[indexI][indexJ] == e.EntranceToTheUniversity)
                {
                    painter->setBrush(Qt::red);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(storedFloor[indexI][indexJ] == e.FreeForStudent)
                {
                    painter->setBrush(Qt::magenta);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(storedFloor[indexI][indexJ] == e.FreeForTeacher)
                {
                    painter->setBrush(Qt::gray);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(storedFloor[indexI][indexJ] == e.EntranceToTheClassroom)
                {
                    painter->setBrush(Qt::green);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                if(storedFloor[indexI][indexJ] == e.Student)//ЗДЕСЬ ЧЕЛОВЕК, мы толерантные поэтому он чёрный
                {
                    painter->setBrush(Qt::blue);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }

                if(storedFloor[indexI][indexJ] == e.Teacher)//ЗДЕСЬ ЧЕЛОВЕК, мы толерантные поэтому он чёрный
                {
                    painter->setBrush(Qt::darkGray);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }

                if(storedFloor[indexI][indexJ] == e.EntranceToTheCanteen)//ЗДЕСЬ ЧЕЛОВЕК, мы толерантные поэтому он чёрный
                {
                    painter->setBrush(Qt::cyan);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }

                if(storedFloor[indexI][indexJ] == e.EntranceToTheToilet)//ЗДЕСЬ ЧЕЛОВЕК, мы толерантные поэтому он чёрный
                {
                    painter->setBrush(Qt::darkCyan);
                    painter->drawRect(i, j, BLOCK_WIDTH, BLOCK_WIDTH);

                }
                indexJ++;
            }
            indexI++;
        }

    }
    file.close();
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
