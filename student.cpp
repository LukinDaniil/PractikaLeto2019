#include "student.h"
#include "human.h"
#include "floormap.h"
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
    numberOfPlaceInTheCabinet = -1;//то есть не сидит
}
Student::Student(int NewX, int NewY, int NewFullness, int NewNaturalNeeds, int NewSleepiness, vector<PathOfWay> NewWay) :
    Human (NewX, NewY, NewFullness, NewNaturalNeeds, NewWay)
{
    Sleepiness = NewSleepiness;
}

int Student::getNumberOfPlaceInTheCabinet()
{
    return numberOfPlaceInTheCabinet;
}
void Student::setNumberOfPlaceInTheCabinet(int newNumber)
{
    numberOfPlaceInTheCabinet = newNumber;
}

