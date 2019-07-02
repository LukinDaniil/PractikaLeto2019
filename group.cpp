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
