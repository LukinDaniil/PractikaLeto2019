#include "floormap.h"
#include "qfile.h"
void FloorMap::createFloorMap()
{

    QFile file("F:\\Projects\\PractikaLeto2019\\Files\\MainBuildingFloor");//открываем файл с картой этажа
        if (file.exists())
        {
            QString currentString;
            //можно в дальнейшем устанавливать в файле на 3 строку сразу
            currentString = file.readLine();
            currentString = file.readLine();
            int yCoordinate = 0;//y координата
            while(!file.atEnd())
            {
                currentString = "";
                currentString=currentString+file.readLine();//считываю строку
                for(int xCoordinate = 0; xCoordinate < currentString.size(); xCoordinate++)//проходим по currentString
                {
                    //в дальнейшем заменить на case для спавна различных объектов
                    if(currentString[xCoordinate] == "1")//если в файле в данном месте стоит 1, то там создаём блок
                    {
                        floor[xCoordinate][yCoordinate] = 1;
                    }

                    if(currentString[xCoordinate] == "0")//если в файле в данном месте стоит 1, то там создаём блок
                    {
                        floor[xCoordinate][yCoordinate] = 0;
                    }
                }
                yCoordinate++;//переходим на следующую строку
                //добавить обновление формы или найти иной сп
            }
        }

}


FloorMap::FloorMap(int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;
    floor.resize(width*height);
}

int FloorMap::getWidth()
{
    return width;
}

int FloorMap::getHeight()
{
    return height;
}

int FloorMap::getIJFloorMap(int i, int j)
{
    return floor[i][j];
}
