#include "mytime.h"

MyTime::MyTime()
{
        Hour = 0;
        Minute = 0;
        Day = 0;
        CountDay = 5;
}
MyTime::MyTime(int NewHour, int NewMinute, int NewDay, int NewCountDay)
{
    Hour = NewHour;
    Minute = NewMinute;
    Day = NewDay;
    CountDay = NewCountDay;
}
void MyTime::SetMinute(int NewMinute)
{
    Minute = NewMinute;
}
int MyTime::GetMinute()
{
    return Minute;
}
void MyTime::SetHour(int NewHour)
{
    Hour = NewHour;
}
int MyTime::GetHour()
{
    return  Hour;
}
void MyTime::AddMinute(int Min)
{
    Minute += Min;
    if (Minute >= 60)
    {
        Hour += Minute / 60;
        Minute = Minute % 60;
    }
    if (Hour >= 24)
    {
        Day += Hour / 24;
        Hour = Hour % 24;
    }
    if (Day > CountDay)
        Day = Day % CountDay;
}
