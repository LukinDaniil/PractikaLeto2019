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
Human::Human(int NewX, int NewY, int NewFullness, int NewNaturalNeeds)
{
    PositionX = NewX;
    PositionY = NewY;
    Fullness = NewFullness;
    NaturalNeeds = NewNaturalNeeds;
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
