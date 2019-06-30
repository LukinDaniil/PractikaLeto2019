#ifndef HUMAN_H
#define HUMAN_H
#include <string>
#include <vector>
using namespace std;
class PathOfWay
{
public:
    int X;
    int Y;
};

class Human
{
protected:
    int PositionX;    // позиция по горизонтали
    int PositionY;    // позиция по вертикали
    int Fullness;     // сытость (0-100)
    int NaturalNeeds; // естественные нужды 0-100
    vector<PathOfWay> Way; // путь
    void ComeCanteen();
    void ComeToilet();
public:
    void MakeStep();
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
