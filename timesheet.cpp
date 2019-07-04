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
    //int NumCab[NumOfLessons];
    for (int i = 0; i < NumOfLessons; i++)
    {
        int NumOfTeachersName =  mersenne() % MAXTEACHERSNAMES;
        int NumOfLessonsName =  mersenne() % MAXLESSONSNAMES;
        int NumTime = 0;
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
void Timesheet::ReadTimesheet(QString WayToFile)
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QFile file(WayToFile);
    if(file.open(QIODevice::ReadOnly))
    {
        SchoolDay.clear();
        QString str="";
        str= file.readLine();
        int CountDay = str.toInt();
        for (int i = 0; i < CountDay; i++)
        {
            str= file.readLine();
            SchoolDay.push_back(*(new vector<Lesson>));
            int CountLessons = str.toInt();
            for(int j = 0; j < CountLessons; j++)
            {
                Lesson temp;
                str=  file.readLine();
                temp.NumCabinet =  str.toInt();
                str= QObject::trUtf8( file.readLine());
                temp.Name = str;
                str= QObject::trUtf8(file.readLine());
                temp.TeachersName = str;
                SchoolDay[i].push_back(temp);
            }
        }
        file.close();
    }
}

int Timesheet::getNumberOfCurrentLesson(MyTime currentTime)
{
    if(currentTime.GetHour() >= 8 && currentTime.GetHour() <= 9 && currentTime.GetMinute() >= 15 && currentTime.GetMinute() <= 45)
        return 0;
    if(currentTime.GetHour() >= 9 && currentTime.GetHour() <= 11 && currentTime.GetMinute() >= 45 && currentTime.GetMinute() <= 25)
        return 1;
    if(currentTime.GetHour() >= 11 && currentTime.GetHour() <= 13 && currentTime.GetMinute() >= 25 && currentTime.GetMinute() <= 5)
        return 2;
    if(currentTime.GetHour() >= 13 && currentTime.GetHour() <= 15 && currentTime.GetMinute() >= 5 && currentTime.GetMinute() <= 5)
        return 3;
    if(currentTime.GetHour() >= 15 && currentTime.GetHour() <= 16 && currentTime.GetMinute() >= 5 && currentTime.GetMinute() <= 45)
        return 3;
}
