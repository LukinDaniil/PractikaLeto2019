#ifndef HUMAN_H
#define HUMAN_H
#include <string>
using namespace std;
class Human
{
protected:
    int PositionX;    // позиция по горизонтали
    int PositionY;    // позиция по вертикали
    int Fullness;     // сытость (0-100)
    int NaturalNeeds; // естественные нужды 0-100
    void ComeCanteen();
    void ComeToilet();
public:
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
    Human(int NewX, int NewY, int NewFullness, int NewNaturalNeeds);
};
#endif // HUMAN_H
