#include "human.h"
PathOfWay::PathOfWay()
{
    X = 0;
    Y = 0;
}
PathOfWay::PathOfWay(int NewX, int NewY)
{
    X = NewX;
    Y = NewY;
}
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
void Human::MakeWay(int FinishX, int FinishY, vector<vector<int>> *map)
{
    Seach(PositionX, PositionY, FinishX, FinishY, 0, map);
    int CurX = FinishX;
    int CurY = FinishY;
    vector<PathOfWay> MakedWay;
    PathOfWay *path = new PathOfWay();
    path->X = CurX;
    path->Y = CurY;
    MakedWay.push_back(*path);
    int CurNum = (*map)[FinishX][FinishY];
    do
    {
        PathOfWay *NewBlock = new PathOfWay();
        if (CurX - 1 >= 0 && (*map)[CurX - 1][CurY] == CurNum - 1)
        {
            CurX--;
            CurNum--;
            NewBlock->X = CurX;
            NewBlock->Y = CurY;
            MakedWay.push_back(*NewBlock);
        }
        if (CurX + 1 < (*map)[0].size() && (*map)[CurX + 1][CurY] == CurNum - 1)
        {
            CurX++;
            CurNum--;
            NewBlock->X = CurX;
            NewBlock->Y = CurY;
            MakedWay.push_back(*NewBlock);
        }
        if (CurY - 1 >= 0 && (*map)[CurX][CurY - 1] == CurNum - 1)
        {
            CurY--;
            CurNum--;
            NewBlock->X = CurX;
            NewBlock->Y = CurY;
            MakedWay.push_back(*NewBlock);
        }
        if (CurY + 1 < (*map).size() && (*map)[CurX][CurY + 1] == CurNum - 1)
        {
            CurY++;
            CurNum--;
            NewBlock->X = CurX;
            NewBlock->Y = CurY;
            MakedWay.push_back(*NewBlock);
        }
    } while (CurNum != 0);
    // перевернуть путь блеать!
    SetWay(MakedWay);
}
void Human::Seach(int X, int Y, int FinishX, int FinishY, int Num, vector<vector<int>> *map)
{
    (*map)[X][Y] = Num;
    if (X == FinishX && Y == FinishY)
        return;
    if (X - 1 >= 0 && (*map)[X-1][Y] == 0)
        Seach(X - 1, Y,FinishX, FinishY, Num + 1, map);
    if (X + 1 < (*map)[0].size() &&  (*map)[X+1][Y] == 0)
        Seach(X + 1, Y,FinishX, FinishY, Num + 1, map);
    if (Y - 1 > 0 && (*map)[X][Y-1] == 0)
        Seach(X, Y - 1,FinishX, FinishY, Num + 1, map);
    if (Y + 1 < (*map).size() && (*map)[X][Y+1] == 0)
        Seach(X, Y + 1,FinishX, FinishY, Num + 1, map);


}
