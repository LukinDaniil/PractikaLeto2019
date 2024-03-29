#include "human.h"

int Human::GetPositionX()
{
    return  PositionX;
}
int Human::GetPositionY()
{
    return PositionY;
}
int Human::GetFullness()
{
    return  Fullness;
}
int Human::GetNaturalNeeds()
{
    return  NaturalNeeds;
}
void Human::SetPositionX(int NewX)
{
    PositionX = NewX;
}
void Human::SetPositionY(int NewY)
{
    PositionY = NewY;
}
void Human::SetPositions(int NewX, int NewY)
{
    PositionX = NewX;
    PositionY = NewY;
}
void Human::DownNaturalNeeds(int value)
{
    if (NaturalNeeds - value <= 0)
        NaturalNeeds = 0;
    else
        NaturalNeeds -= value;
}
void Human::DownFullness(int value)
{
    if (Fullness - value <= 0)
        Fullness = 0;
    else
        Fullness -= value;
}
Human::Human(int NewX, int NewY, int NewFullness, int NewNaturalNeeds, vector<PathOfWay> NewWay)
{
    PositionX = NewX;
    PositionY = NewY;
    Fullness = NewFullness;
    NaturalNeeds = NewNaturalNeeds;
    Way = NewWay;
}
Human::Human()
{
    PositionX = 0;
    PositionY = 0;
    Fullness = 100;
    NaturalNeeds = 100;
}
void Human::Toilet()
{
    ComeToilet();
    NaturalNeeds = 100;
}
void Human::Eat()
{
    ComeCanteen();
    Fullness = 100;
}
/////////// методы не определены
void Human::ComeToCabinet()
{
    return;
}
void Human::ComeToilet()
{
    return;
}
void Human::ComeCanteen()
{
    return;
}
void Human::MakeStep()
{
    if (Way.size() > 0)
    {
        SetPositions(Way[0].X,Way[0].Y);
        Way.erase(Way.begin());
    }
}

bool Human::isWayEmpty()
{
    if(Way.size() == 0)
        return true;
    else
        return false;
}

void Human::SetWay(vector<PathOfWay> NewWay)
{
    Way.clear();
    for (int i = 0; i < NewWay.size(); i++)
    {
        Way.push_back(NewWay[i]);
    }
}
vector<PathOfWay> Human::MakeWay(int FinishX, int FinishY, vector<vector<int>> *map, bool needToFillTheMap)
{
    if(needToFillTheMap)//если карту для волнового алгоритма необходимо заполнить, то вызываем метод Search, иначе map уже заполнена и ничего делать не нужно
    {
        vector<PathOfWay> queue;
        queue.push_back(*(new PathOfWay(PositionX, PositionY)));
        Search(queue, 0, map);
    }
    (*map)[PositionX][PositionY] = 0;
    int CurX = FinishX;
    int CurY = FinishY;
    vector<PathOfWay> MakedWay;
    MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
    int CurNum = (*map)[FinishX][FinishY];
    do
    {
        if (CurX - 1 >= 0 && (*map)[CurX - 1][CurY] == CurNum - 1 && CurNum != 0)
        {
            CurX--;
            CurNum--;
            MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
        }
        if (CurX + 1 < (*map)[0].size() && (*map)[CurX + 1][CurY] == CurNum - 1 && CurNum != 0)
        {
            CurX++;
            CurNum--;
            MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
        }
        if (CurY - 1 >= 0 && (*map)[CurX][CurY - 1] == CurNum - 1 && CurNum != 0)
        {
            CurY--;
            CurNum--;
            MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
        }
        if (CurY + 1 < (*map).size() && (*map)[CurX][CurY + 1] == CurNum - 1 && CurNum != 0)
        {
            CurY++;
            CurNum--;
            MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
        }
    } while (CurNum != 0);
    vector<PathOfWay> CorrectWay;
    for (int i = 0; i < MakedWay.size(); i++)
    {
        CorrectWay.push_back(*new PathOfWay(MakedWay[MakedWay.size() - i - 1].X, MakedWay[MakedWay.size() - i - 1].Y));
    }
    return (CorrectWay);
}

void Human::Search(vector<PathOfWay> queue, int Num, vector<vector<int>> *map)
{
    vector<PathOfWay> NewQueue;
    if (queue.size() == 0)
    {
        int f = 0;
        return;
    }

    while (queue.size() > 0)
    {
        int X = queue[0].X;
        int Y = queue[0].Y;
        if (X - 1 >= 0)
            if ((*map)[X - 1][Y] == 0)
                NewQueue.push_back(*(new PathOfWay(X - 1, Y)));
        if (X + 1 < (*map).size())
            if ((*map)[X + 1][Y] == 0)
                NewQueue.push_back(*(new PathOfWay(X + 1, Y)));
        if (Y - 1 >= 0)
            if ((*map)[X][Y - 1] == 0)
                NewQueue.push_back(*(new PathOfWay(X, Y - 1)));
        if (Y + 1 < (*map)[0].size())
            if ((*map)[X][Y + 1] == 0)
                NewQueue.push_back(*(new PathOfWay(X, Y + 1)));
        (*map)[X][Y] = Num;

        queue.erase(queue.begin());
    }
    for (int i = 0; i < NewQueue.size(); i++)
        for (int j = 0; j < NewQueue.size(); j++)
        {
            if (i != j)
            {
                if (NewQueue[i].X == NewQueue[j].X && NewQueue[i].Y == NewQueue[j].Y)
                {
                    NewQueue.erase(NewQueue.begin() + j);
                    j--;
                }
            }
        }
    Search(NewQueue, Num + 1, map);

}

void Human::MakeWayInTheCabinet(vector<vector<int>> *map, FloorMap* mapOfTheFloor, /*Cabinet *currentCabinet*/ int numberOfTheCabinet)
{
    //int amountOfDesksInTheICabinet = mapOfTheFloor->getAmountOfDesksInTheICabinet(numberOfTheCabinet);
    vector<PathOfWay> queue;
    queue.push_back(*(new PathOfWay(PositionX, PositionY)));
    int** forCheck;
    int width = mapOfTheFloor->getWidth();
    int height = mapOfTheFloor->getHeight();

    forCheck = new int*[width];
    for(int i = 0; i < width; i++)
        forCheck[i] = new int[height];
    for (int i = 0; i < width; i ++)
        for(int j = 0; j < height; j ++)
            forCheck[i][j] = 0;
    SearchInTheCabinet(queue, 0, map, mapOfTheFloor, numberOfTheCabinet, forCheck);


    (*map)[PositionX][PositionY] = 0;
    int amountOfDesksInTheICabinet = mapOfTheFloor->getAmountOfDesksInTheICabinet(numberOfTheCabinet);
    for(int i = 0; i < amountOfDesksInTheICabinet; i ++)//проходим по всем партам
    {
        (*map)[PositionX][PositionY] = 0;
        PathOfWay deskCoordinates = mapOfTheFloor->getCoordinatesOfTheDeskInTheICabinet(i, numberOfTheCabinet);
        int FinishX = deskCoordinates.X;
        int FinishY = deskCoordinates.Y;
        int CurX = FinishX;
        int CurY = FinishY;
        vector<PathOfWay> MakedWay;
        MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
        int CurNum = (*map)[FinishX][FinishY];
        do
        {
            if (CurX - 1 >= 0 && (*map)[CurX - 1][CurY] == CurNum - 1 && CurNum != 0)
            {
                CurX--;
                CurNum--;
                MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
            }
            if (CurX + 1 < (*map)[0].size() && (*map)[CurX + 1][CurY] == CurNum - 1 && CurNum != 0)
            {
                CurX++;
                CurNum--;
                MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
            }
            if (CurY - 1 >= 0 && (*map)[CurX][CurY - 1] == CurNum - 1 && CurNum != 0)
            {
                CurY--;
                CurNum--;
                MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
            }
            if (CurY + 1 < (*map).size() && (*map)[CurX][CurY + 1] == CurNum - 1 && CurNum != 0)
            {
                CurY++;
                CurNum--;
                MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
            }
        } while (CurNum != 0);
        vector<PathOfWay> CorrectWay;
        for (int i = 0; i < MakedWay.size(); i++)
        {
            CorrectWay.push_back(*new PathOfWay(MakedWay[MakedWay.size() - i - 1].X, MakedWay[MakedWay.size() - i - 1].Y));
        }
        mapOfTheFloor->pushNewStudentWayInTheICabinet(numberOfTheCabinet, CorrectWay);
    }

    //теперь для преподавателя

    (*map)[PositionX][PositionY] = 0;
    PathOfWay teachersPlaceCoordinates = mapOfTheFloor->getCoordinatesOfTheTeachersPlaceInTheICabinet(numberOfTheCabinet);
    int FinishX = teachersPlaceCoordinates.X;
    int FinishY = teachersPlaceCoordinates.Y;
    int CurX = FinishX;
    int CurY = FinishY;
    vector<PathOfWay> MakedWay;
    MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
    int CurNum = (*map)[FinishX][FinishY];
    do
    {
        if (CurX - 1 >= 0 && (*map)[CurX - 1][CurY] == CurNum - 1 && CurNum != 0)
        {
            CurX--;
            CurNum--;
            MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
        }
        if (CurX + 1 < (*map)[0].size() && (*map)[CurX + 1][CurY] == CurNum - 1 && CurNum != 0)
        {
            CurX++;
            CurNum--;
            MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
        }
        if (CurY - 1 >= 0 && (*map)[CurX][CurY - 1] == CurNum - 1 && CurNum != 0)
        {
            CurY--;
            CurNum--;
            MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
        }
        if (CurY + 1 < (*map).size() && (*map)[CurX][CurY + 1] == CurNum - 1 && CurNum != 0)
        {
            CurY++;
            CurNum--;
            MakedWay.push_back(*(new PathOfWay(CurX, CurY)));
        }
    } while (CurNum != 0);
    vector<PathOfWay> CorrectWay;
    for (int i = 0; i < MakedWay.size(); i++)
    {
        CorrectWay.push_back(*new PathOfWay(MakedWay[MakedWay.size() - i - 1].X, MakedWay[MakedWay.size() - i - 1].Y));
    }
    mapOfTheFloor->pushNewTeachersWayInTheICabinet(numberOfTheCabinet, CorrectWay);

}

void Human::SearchInTheCabinet(vector<PathOfWay> queue, int Num, vector<vector<int>> *map, FloorMap* mapOfTheFloor , /*Cabinet *currentCabinet*/ int numberOfTheCabinet, int** forCheck)
{
    vector<PathOfWay> NewQueue;
    if (queue.size() == 0)
        return;

    while (queue.size() > 0)
    {
        int X = queue[0].X;
        int Y = queue[0].Y;
        Enums e;

        if (X - 1 >= 0)
        {
            if ((*map)[X - 1][Y] == 0)
                NewQueue.push_back(*(new PathOfWay(X - 1, Y)));
            if(mapOfTheFloor->getIJFloorMap(X - 1, Y) == e.FreeForStudent && forCheck[X - 1][Y] == 0)
            {
                forCheck[X - 1][Y] = 1;
                PathOfWay newDesk(X - 1, Y);
                //currentCabinet->pushDesk(newDesk);//добавили парту
                mapOfTheFloor->pushDeskIntoICabinet(numberOfTheCabinet, newDesk);
            }

            if(mapOfTheFloor->getIJFloorMap(X - 1, Y) == e.FreeForTeacher && forCheck[X - 1][Y] == 0)
            {
                forCheck[X - 1][Y] = 1;
                PathOfWay newTeachersPlace(X - 1, Y);
                //currentCabinet->pushTeachersPlace(newTeachersPlace);
                mapOfTheFloor->pushTeachersPlaceIntoICabinet(numberOfTheCabinet, newTeachersPlace);
            }
        }
        if (X + 1 < (*map)[0].size())
        {
            if ((*map)[X + 1][Y] == 0)
                NewQueue.push_back(*(new PathOfWay(X + 1, Y)));
            if(mapOfTheFloor->getIJFloorMap(X + 1, Y) == e.FreeForStudent && forCheck[X + 1][Y] == 0)
            {
                forCheck[X + 1][Y] = 1;
                PathOfWay newDesk(X + 1, Y);
                //currentCabinet->pushDesk(newDesk);//добавили парту
                mapOfTheFloor->pushDeskIntoICabinet(numberOfTheCabinet, newDesk);
            }

            if(mapOfTheFloor->getIJFloorMap(X + 1, Y) == e.FreeForTeacher && forCheck[X + 1][Y] == 0)
            {
                forCheck[X + 1][Y] = 1;
                PathOfWay newTeachersPlace(X + 1, Y);
                //currentCabinet->pushTeachersPlace(newTeachersPlace);
                mapOfTheFloor->pushTeachersPlaceIntoICabinet(numberOfTheCabinet, newTeachersPlace);
            }
        }
        if (Y - 1 >= 0)
        {
            if ((*map)[X][Y - 1] == 0)
                NewQueue.push_back(*(new PathOfWay(X, Y - 1)));
            if(mapOfTheFloor->getIJFloorMap(X, Y - 1) == e.FreeForStudent && forCheck[X][Y - 1] == 0)
            {
                forCheck[X][Y - 1] = 1;
                PathOfWay newDesk(X, Y - 1);
                //currentCabinet->pushDesk(newDesk);//добавили парту
                mapOfTheFloor->pushDeskIntoICabinet(numberOfTheCabinet, newDesk);
            }

            if(mapOfTheFloor->getIJFloorMap(X, Y - 1) == e.FreeForTeacher && forCheck[X][Y - 1] == 0)
            {
                forCheck[X][Y - 1] = 1;
                PathOfWay newTeachersPlace(X, Y - 1);
                //currentCabinet->pushTeachersPlace(newTeachersPlace);
                mapOfTheFloor->pushTeachersPlaceIntoICabinet(numberOfTheCabinet, newTeachersPlace);
            }
        }
        if (Y + 1 < (*map).size())
        {
            if ((*map)[X][Y + 1] == 0)
                NewQueue.push_back(*(new PathOfWay(X, Y + 1)));
            if(mapOfTheFloor->getIJFloorMap(X, Y + 1) == e.FreeForStudent && forCheck[X][Y + 1] == 0)
            {
                forCheck[X][Y + 1] = 1;
                PathOfWay newDesk(X, Y + 1);
                //currentCabinet->pushDesk(newDesk);//добавили парту
                mapOfTheFloor->pushDeskIntoICabinet(numberOfTheCabinet, newDesk);
            }

            if(mapOfTheFloor->getIJFloorMap(X, Y + 1) == e.FreeForTeacher && forCheck[X][Y + 1] == 0)
            {
                forCheck[X][Y + 1] = 1;
                PathOfWay newTeachersPlace(X, Y + 1);
                //currentCabinet->pushTeachersPlace(newTeachersPlace);
                mapOfTheFloor->pushTeachersPlaceIntoICabinet(numberOfTheCabinet, newTeachersPlace);
            }
        }
        (*map)[X][Y] = Num;


        queue.erase(queue.begin());
    }
    for (int i = 0; i < NewQueue.size(); i++)
        for (int j = 0; j < NewQueue.size(); j++)
        {
            if (i != j)
            {
                if (NewQueue[i].X == NewQueue[j].X && NewQueue[i].Y == NewQueue[j].Y)
                {
                    NewQueue.erase(NewQueue.begin() + j);
                    j--;
                }
            }
        }




    int p = 0;



    SearchInTheCabinet(NewQueue, Num + 1, map, mapOfTheFloor, numberOfTheCabinet, forCheck);
}
