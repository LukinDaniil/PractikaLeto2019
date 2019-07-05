#include "floormap.h"
#include "qfile.h"
#define N 100
FloorMap::FloorMap()
{

}

FloorMap::FloorMap(int newWidth, int newHeight, QString newPath)
{
    pathToFile = newPath;
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
    //QString fileName = "F:/Projects/PractikaLeto2019/Files/MainBuildingFloor.txt";
    //QString fileName = "C:/Users/aleks/Documents/PractikaLeto2019/MainBuildingFloor.txt";
    QFile file(pathToFile);
    if(file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
            QString currentString;
            //можно в дальнейшем устанавливать в файле на 3 строку сразу
            currentString = in.readLine(N);
            currentString = in.readLine(N);
            int yCoordinate = 0;//y координата
            int cabinetCount = 0;
            while(!in.atEnd())
            {
                //currentString = "";
                currentString=in.readLine(N);//считываю строку
                Enums e;
                for(int xCoordinate = 0; xCoordinate < currentString.size(); xCoordinate++)//проходим по currentString
                {
                    //в дальнейшем заменить на case для спавна различных объектов

                    if(currentString[xCoordinate] == "0")
                    {
                        floor[xCoordinate][yCoordinate] = e.FreeBlock;
                    }

                    if(currentString[xCoordinate] == "1")
                    {
                        floor[xCoordinate][yCoordinate] = e.Wall;
                        floorForTheWay[xCoordinate][yCoordinate] = -1;
                    }

                    if(currentString[xCoordinate] == "2")
                    {
                        floor[xCoordinate][yCoordinate] = e.Desk;
                        floorForTheWay[xCoordinate][yCoordinate] = -1;
                    }
                    /*
                    if(currentString[xCoordinate] == "3")
                    {
                        floor[xCoordinate][yCoordinate] = e.EntranceToTheUniversity;
                        entranceToTheUniversity.X = xCoordinate;
                        entranceToTheUniversity.Y = yCoordinate;
                    }
                    */
                    if(currentString[xCoordinate] == "4")
                    {
                        floor[xCoordinate][yCoordinate] = e.FreeForStudent;

                    }

                    if(currentString[xCoordinate] == "5")
                    {
                        floor[xCoordinate][yCoordinate] = e.FreeForTeacher;
                    }

                    if(currentString[xCoordinate] == "6")
                    {
                        floor[xCoordinate][yCoordinate] = e.EntranceToTheClassroom;
                        PathOfWay newExit(xCoordinate, yCoordinate);
                        Cabinet newCabinet(cabinetCount, newExit);//номер кабинета от 0, а не от 1!
                        cabinets.push_back(newCabinet);
                        cabinetCount ++;//у следующего кабинета на 1 больше номер

                    }

                    if(currentString[xCoordinate] == "7")
                    {
                        floor[xCoordinate][yCoordinate] = e.EntranceToTheCanteen;
                    }
                    if(currentString[xCoordinate] == "8")
                    {
                        floor[xCoordinate][yCoordinate] = e.EntranceToTheToilet;
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
            7 - вход в столовую
            8 - вход в туалет
            */
    }
    file.close();
}

QString FloorMap::getPathToFile()
{
    return pathToFile;
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

int FloorMap::getAmountOfCabinets()
{
    return cabinets.size();
}

int FloorMap::getAmountOfDesksInTheICabinet(int i)
{
    return cabinets[i].CountOfStudentPlace;
    //return cabinets[i].desks.capacity();
    //int size = cabinets[i].desks.size();
    //return cabinets[i].desks.size();
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

PathOfWay FloorMap::getCoordinatesOfCabinet(int numberOfCabinet)
{
    return cabinets[numberOfCabinet].ExitOfCabinet;//возвращаю координаты входа в кабинет
}

Cabinet* FloorMap::getICabinet(int i)//возвращает ссылку на i-ый кабинет
{
    return &cabinets[i];
}


void FloorMap::pushDeskIntoICabinet(int i, PathOfWay newDesk)
{
    cabinets[i].pushDesk(newDesk);
}

PathOfWay FloorMap::getCoordinatesOfTheDeskInTheICabinet(int numberOfTheDesk, int i)
{
    PathOfWay coordinatesOfTheDesk(cabinets[i].desks[numberOfTheDesk].X, cabinets[i].desks[numberOfTheDesk].Y);
    return coordinatesOfTheDesk;
}

void FloorMap::pushNewStudentWayInTheICabinet(int i, vector<PathOfWay> newWay)
{
    cabinets[i].Ways.push_back(newWay);
}

PathOfWay FloorMap::getCoordinatesOfTheTeachersPlaceInTheICabinet(int i)
{
    PathOfWay coordinatesOfTheTeachersPlace(cabinets[i].TeachersPlace.X, cabinets[i].TeachersPlace.Y);
    return coordinatesOfTheTeachersPlace;
}

void FloorMap::pushNewTeachersWayInTheICabinet(int i, vector<PathOfWay> newWay)
{
    cabinets[i].TeachersWay = newWay;
}

void FloorMap::pushTeachersPlaceIntoICabinet(int i, PathOfWay newTeachersPlace)
{
    cabinets[i].TeachersPlace = newTeachersPlace;
}

vector<PathOfWay> FloorMap::getDesksOfICabinet(int i)
{
    return cabinets[i].desks;
}

vector<Cabinet>* FloorMap::getAllCabinets()
{
    return &cabinets;
}
