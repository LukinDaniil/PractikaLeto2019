#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class PathOfWay
{
public:
    int X;
    int Y;
    PathOfWay();
    PathOfWay(int NewX, int NewY);
};

class Human
{
protected:
    int PositionX;    // позиция по горизонтали
    int PositionY;    // позиция по вертикали
    int Fullness;     // сытость (0-100)
    int NaturalNeeds; // естественные нужды 0-100
    vector<PathOfWay> Way; // путь
    void Seach(int FinishX, int FinishY, vector<PathOfWay> queue, int Num, vector<vector<int>> *map);
    void ComeCanteen();
    void ComeToilet();
public:
    void MakeStep();
    vector<PathOfWay> MakeWay(int FinishX, int FinishY, vector<vector<int>> *map); // map - это карта, где стены -1, а 0 - свободно
    void SetWay(vector<PathOfWay> NewWay);
    void Eat();
    void Toilet();
    void ComeToCabinet();
    int GetPositionX();
    int GetPositionY();
    int GetFullness();
    int GetNaturalNeeds();
    void SetPositionX(int NewX);
    void SetPositionY(int NewY);
    void SetPositions(int NewX, int NewY);
    void DownFullness(int value);
    void DownNaturalNeeds(int value);
    virtual string ReturnStatus() = 0;
    Human();
    Human(int NewX, int NewY, int NewFullness, int NewNaturalNeeds, vector<PathOfWay> NewWay);
};
#endif // HUMAN_H
