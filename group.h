#ifndef GROUP_H
#define GROUP_H
#include <vector>
#include "student.h"
#include "timesheet.h"

class Group
{
public:
    int numberOfCurrentCabinet;//номер кабинета, в котором группа должна находиться в данный момент
    int numberOfPreviousCabinet;//номер кабинета, в котором группа находилась занятием ранее
    int amountOfPeopleInTheCabinet;
    vector<Student> People;
    vector<PathOfWay> groupWay;
    Timesheet timeshet;
    void DefineWay(vector<PathOfWay> NewWay);
    vector<QString> ToString();
    Group();
    void addStudent(int X, int Y);
    void groupMakeStep();
};

#endif // GROUP_H
