#ifndef TEACHER_H
#define TEACHER_H
#include "human.h"

class Teacher : public Human
{
public:
    Teacher();
    Teacher(int NewX, int NewY, int NewFullness, int NewNaturalNeeds, vector<PathOfWay> NewWay);
    void ChangeTimesheet(); // изменить расписание
    virtual string ReturnStatus() override;
};

#endif // TEACHER_H
