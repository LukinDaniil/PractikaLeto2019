#include "floormap.h"
#include "qfile.h"
FloorMap::FloorMap()
{

}

FloorMap::FloorMap(int newWidth, int newHeight)
{
    width = newWidth;
    height = newHeight;
    floorForTheWay.resize(width, vector<int> (height, 0));
    floor = new int*[width];
    for(int i = 0; i < width; i++)
        floor[i] = new int[height];
    updateFloorMap();
}

void FloorMap::updateFloorMap()//считывает карту из файла и сохраняет информацию в полях
{
    QString fileName = "F:/Projects/PractikaLeto2019/Files/MainBuildingFloor.txt";
    QFile file(fileName);
    if(file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
            QString currentString;
            //можно в дальнейшем устанавливать в файле на 3 строку сразу
            currentString = in.readLine(50);
            currentString = in.readLine(50);
            int yCoordinate = 0;//y координата

            while(!in.atEnd())
            {
                //currentString = "";
                currentString=in.readLine(100);//считываю строку
                for(int xCoordinate = 0; xCoordinate < currentString.size(); xCoordinate++)//проходим по currentString
                {
                    //в дальнейшем заменить на case для спавна различных объектов

                    if(currentString[xCoordinate] == "0")
                    {
                        floor[xCoordinate][yCoordinate] = 0;
                    }

                    if(currentString[xCoordinate] == "1")
                    {
                        floor[xCoordinate][yCoordinate] = 1;
                        floorForTheWay[xCoordinate][yCoordinate] = -1;
                    }

                    if(currentString[xCoordinate] == "2")
                    {
                        floor[xCoordinate][yCoordinate] = 2;
                    }

                    if(currentString[xCoordinate] == "3")
                    {
                        floor[xCoordinate][yCoordinate] = 3;
                    }

                    if(currentString[xCoordinate] == "4")
                    {
                        floor[xCoordinate][yCoordinate] = 4;
                    }

                    if(currentString[xCoordinate] == "5")
                    {
                        floor[xCoordinate][yCoordinate] = 5;
                    }

                    if(currentString[xCoordinate] == "6")
                    {
                        floor[xCoordinate][yCoordinate] = 6;
                    }
                }
                yCoordinate++;//переходим на следующую строку
                //добавить обновление формы или найти иной сп
            }
            //во floor готовая карта
            /*
            0 - свободно
            1 - стена
            2 - парта
            3 - дорожка
            4 - свободное место для студента
            5 - свободное место для препода
            6 - вход в аудиторию
            */
    }
    file.close();
}
int** FloorMap::getFloorMap()
{
    int** temp = new int*[width];
    for(int i = 0; i < width; i++)
        temp[i] = new int[height];
    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j ++)
            temp[i][j] = floor[i][j];
    return temp;
}

vector<vector<int>> FloorMap::getFloorForTheWay()
{
    vector<vector<int>> temp(floorForTheWay);//копируем карту для построения пути
    return temp;
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

