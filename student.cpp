#include "student.h"
#include "human.h"
string Student::ReturnStatus()
{
    string str = "Student";
    return str;
}
void Student::SetSleepiness(int value)
{
    if (value > 100)
        Sleepiness = 100;
    else
    {
        Sleepiness = value;
    }
}
void Student::Sleeping(int time)
{
    if (time + Sleepiness > 100)
        Sleepiness = 100;
    else {
        Sleepiness += time;
    }
}
void Student::DownSleepiness(int value)
{
    if (Sleepiness - value < 0)
        Sleepiness = 0;
    else {
        Sleepiness -= value;
    }
}
int Student::GetSleepiness()
{
    return  Sleepiness;
}
Student::Student() : Human ()
{
    Sleepiness = 100;
}
Student::Student(int NewX, int NewY, int NewFullness, int NewNaturalNeeds, int NewSleepiness) :
    Human (NewX, NewY, NewFullness, NewNaturalNeeds)
{
    Sleepiness = NewSleepiness;
}

