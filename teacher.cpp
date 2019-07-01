#include "teacher.h"

 string Teacher::ReturnStatus()
{
    return "Teacher";
}

Teacher::Teacher() : Human ()
{

}
Teacher::Teacher(int NewX, int NewY, int NewFullness, int NewNaturalNeeds, vector<PathOfWay> NewWay)
    : Human (NewX, NewY, NewFullness, NewNaturalNeeds, NewWay)
{

}

void Teacher::ChangeTimesheet()
{

}
