#include "floormap.h"
#include "qfile.h"
floorMap::floorMap()
{
    floor.resize(100);//потом задефайнить или посчитать исходя из ширины и высоты
    QFile file("F:\\Projects\\PractikaLeto2019\\Files\\MainBuildingFloor");//открываем файл с картой этажа
        if (file.exists())
        {
            QString currentString;
            //считывание и запись ширины и высоты карты
            currentString = file.readLine();
            width = currentString.toInt();
            currentString = file.readLine();
            height = currentString.toInt();
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

int floorMap::getWidth()
{
    return width;
}

int floorMap::getHeight()
{
    return height;
}
