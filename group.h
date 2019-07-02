#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include "student.h"
#include "timesheet.h"

class Group
{
public:
    vector<Student> People;
    Timesheet timeshet;
    void DefineWay(vector<PathOfWay> NewWay);
    Group();
    void addStudent(int X, int Y);
    void groupMakeStep();
};

#endif // GROUP_H
