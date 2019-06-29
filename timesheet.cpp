#include "timesheet.h"
#include "iterator"
#include <random>
using namespace std;

void Timesheet::SetDay(int index, list<Lesson> NewLessons)
{
    SchoolDay[index].clear();
    list <Lesson> :: iterator it;
    for (it = NewLessons.begin(); it != NewLessons.end(); it++)
        SchoolDay[index].push_back((*it));
}
void Timesheet::SetRandomDay(int index)
{
    SchoolDay[index].clear();
    std::random_device rd;
    std::mt19937 mersenne(rd());
    int NumOfLessons = (mersenne() % MAXNUMLESSONSINDAY) + 1;
    int NumCab[NumOfLessons];
    for (int i = 0; i < NumOfLessons; i++)
    {
        int NumOfTeachersName =  mersenne() % MAXTEACHERSNAMES;
        int NumOfLessonsName =  mersenne() % MAXLESSONSNAMES;
        int NumTime = 0;
        bool CorrectTime = false;
        while (CorrectTime == false)
        {
            CorrectTime = true;

            NumTime = mersenne() %  COUNTTIMES + 1;
            list <Lesson> :: iterator it;
            for (it = SchoolDay[index].begin(); it != SchoolDay[index].end(); it++)
            {
                if (NumTime == (*it).NumTime)
                    CorrectTime = false;
            }
        }
        Lesson *les = new Lesson();
        les->Name = LessonsNames[NumOfLessonsName];
        les->TeachersName = TeachersNames[NumOfTeachersName];
        les->NumCabinet = 1;  // аудитория всегда одна пока что
        les->NumTime = NumTime;
        SchoolDay[index].push_back((*les));
    }
}
void Timesheet::SetRandomTimesheet()
{
    for(int i = 0; i < COUNTDAY; i++)
        SetRandomDay(i);
}

Timesheet::Timesheet()
{

}
