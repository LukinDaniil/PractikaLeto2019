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
void Human::SetWay(vector<PathOfWay> NewWay)
{
    Way.clear();
    for (int i = 0; i < NewWay.size(); i++)
    {
        Way.push_back(NewWay[i]);
    }
}
vector<PathOfWay> Human::MakeWay(int FinishX, int FinishY, vector<vector<int>> *map)
{
    vector<PathOfWay> queue;
    queue.push_back(*(new PathOfWay(PositionX, PositionY)));
    Search(queue, 0, map);
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
        return;

    while (queue.size() > 0)
    {
        int X = queue[0].X;
        int Y = queue[0].Y;
        if (X - 1 >= 0)
            if ((*map)[X - 1][Y] == 0)
                NewQueue.push_back(*(new PathOfWay(X - 1, Y)));
        if (X + 1 < (*map)[0].size())
            if ((*map)[X + 1][Y] == 0)
                NewQueue.push_back(*(new PathOfWay(X + 1, Y)));
        if (Y - 1 >= 0)
            if ((*map)[X][Y - 1] == 0)
                NewQueue.push_back(*(new PathOfWay(X, Y - 1)));
        if (Y + 1 < (*map).size())
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

void Human::MakeWayInTheCabinet(vector<vector<int>> *map, FloorMap* mapOfTheFloor , Cabinet *currentCabinet)
{
    vector<PathOfWay> queue;
    queue.push_back(*(new PathOfWay(PositionX, PositionY)));
    SearchInTheCabinet(queue, 0, map, mapOfTheFloor, currentCabinet);
    (*map)[PositionX][PositionY] = 0;
    for(int i = 0; i < currentCabinet->desks.size(); i ++)//проходим по всем партам
    {
        (*map)[PositionX][PositionY] = 0;
        int FinishX = currentCabinet->desks[i].X;
        int FinishY = currentCabinet->desks[i].Y;
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
        currentCabinet->Ways.push_back(CorrectWay);
    }

    //теперь для преподователя

    (*map)[PositionX][PositionY] = 0;
    int FinishX = currentCabinet->TeachersPlace.X;
    int FinishY = currentCabinet->TeachersPlace.Y;
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
    currentCabinet->TeachersWay = CorrectWay;

}

void Human::SearchInTheCabinet(vector<PathOfWay> queue, int Num, vector<vector<int>> *map, FloorMap* mapOfTheFloor , Cabinet *currentCabinet)
{
    vector<PathOfWay> NewQueue;
    if (queue.size() == 0)
        return;

    while (queue.size() > 0)
    {
        int X = queue[0].X;
        int Y = queue[0].Y;
        if (X - 1 >= 0)
            if ((*map)[X - 1][Y] == 0)
                NewQueue.push_back(*(new PathOfWay(X - 1, Y)));
        if (X + 1 < (*map)[0].size())
            if ((*map)[X + 1][Y] == 0)
                NewQueue.push_back(*(new PathOfWay(X + 1, Y)));
        if (Y - 1 >= 0)
            if ((*map)[X][Y - 1] == 0)
                NewQueue.push_back(*(new PathOfWay(X, Y - 1)));
        if (Y + 1 < (*map).size())
            if ((*map)[X][Y + 1] == 0)
                NewQueue.push_back(*(new PathOfWay(X, Y + 1)));
        (*map)[X][Y] = Num;
        Enums e;

        if(mapOfTheFloor->getIJFloorMap(X, Y) == e.FreeForStudent)
        {
            PathOfWay newDesk(X, Y);
            currentCabinet->pushDesk(newDesk);//добавили
        }

        if(mapOfTheFloor->getIJFloorMap(X, Y) == e.FreeForTeacher)
        {
            PathOfWay newTeachersPlace(X, Y);
            currentCabinet->pushTeachersPlace(newTeachersPlace);
        }

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
