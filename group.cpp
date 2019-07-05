#include "group.h"

void Group::DefineWay(vector<PathOfWay> NewWay)
{
    for (int i = 0; i < People.size(); i++)
    {
        People[i].SetWay(NewWay);
    }
}
Group::Group()
{
    numberOfPreviousCabinet = -1;
    amountOfPeopleInTheCabinet = 0;
    numberOfCurrentCabinet = -1;
}

void Group::addStudent(int X, int Y)
{
    Student newOne;
    newOne.SetPositions(X, Y);
    People.push_back(newOne);
}
void Group::groupMakeStep()
{
    for (int i = 0; i < People.size(); i++)
    {
        People[i].MakeStep();
    }
}
vector<QString> Group::ToString()
{
    vector<QString> rez;
    for (int i = 0; i < People.size(); i++)
    {
        QString str = "";
        str = "( ";
        str += People[i].GetPositionX();
        str += " , ";
        str += People[i].GetPositionY();
        str += " ) ; ";
        str += People[i].GetFullness();
        str += " ; ";
        str += People[i].GetSleepiness();
        rez.push_back(str);
    }
    return rez;
}
