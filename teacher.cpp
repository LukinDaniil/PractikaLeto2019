#include "teacher.h"

 string Teacher::ReturnStatus()
{
    return "Teacher";
}

Teacher::Teacher() : Human ()
{

}
Teacher::Teacher(int NewX, int NewY, int NewFullness, int NewNaturalNeeds)
    : Human (NewX, NewY, NewFullness, NewNaturalNeeds)
{

}

void Teacher::ChangeTimesheet()
{

}
