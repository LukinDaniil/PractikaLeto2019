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
