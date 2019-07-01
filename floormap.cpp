#include "floormap.h"
#include "qfile.h"
#include "QTextStream"
FloorMap::FloorMap()
{

}

void FloorMap::createFloorMap()//считывает карту из файла и сохраняет информацию в полях
{
    QString fileName = "F:/Projects/PractikaLeto2019/Files/MainBuildingFloor.txt";
    QFile file(fileName);
    if(file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
            QString currentString;
            //можно в дальнейшем устанавливать в файле на 3 строку сразу
            currentString = in.readLine(50);
            width = currentString.toInt();
            currentString = in.readLine(50);
            height = currentString.toInt();
            int yCoordinate = 0;//y координата
            vector<vector<int>> tempFloor (width, vector<int> (height, 0));
            for(int i = 0; i < width; i ++)
                for(int j = 0; j < height; j ++)
                    tempFloor[i][j] = 0;

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
            //во floor готовая карта
            floor = tempFloor;//сохраняем в поле класса

    }
}
vector<vector<int>> FloorMap::getFloorMap()
{
    return floor;

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

