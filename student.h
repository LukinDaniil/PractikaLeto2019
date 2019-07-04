#ifndef STUDENT_H
#define STUDENT_H
#include "human.h"

class Student : public Human
{
private:
    int Sleepiness; // 0-100
    int numberOfPlaceInTheCabinet;
public:
    virtual string ReturnStatus() override;
    void Sleeping(int time);
    void SetSleepiness(int value);
    int GetSleepiness();
    void DownSleepiness(int value);
    Student();
    Student(int NewX, int NewY, int NewFullness, int NewNaturalNeeds, int NewSleepiness, vector<PathOfWay> NewWay);
    int getNumberOfPlaceInTheCabinet();
    void setNumberOfPlaceInTheCabinet(int newNumber);
};


#endif // STUDENT_H
