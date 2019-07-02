#include "mytime.h"

Time::Time()
{
        Hour = 0;
        Minute = 0;
        Day = 0;
        CountDay = 5;
}
Time::Time(int NewHour, int NewMinute, int NewDay, int NewCountDay)
{
    Hour = NewHour;
    Minute = NewMinute;
    Day = NewDay;
    CountDay = NewCountDay;
}
void Time::SetMinute(int NewMinute)
{
    Minute = NewMinute;
}
int Time::GetMinute()
{
    return Minute;
}
void Time::SetHour(int NewHour)
{
    Hour = NewHour;
}
int Time::GetHour()
{
    return  Hour;
}
void Time::AddMinute(int Min)
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
