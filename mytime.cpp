#include "mytime.h"

MyTime::MyTime()
{
        Hour = 8;
        Minute = 15;
        Day = 1;
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

QString MyTime::ToString()
{
    QString dayStr;
    switch(Day % CountDay)
    {
        case 1: dayStr = "Понедельник "; break;
        case 2: dayStr = "Вторник "; break;
        case 3: dayStr = "Среда "; break;
        case 4: dayStr = "Четверг "; break;
        case 0: dayStr = "Пятница "; break;
    }
    QString hourStr;
    if(Hour < 10)//если часы - однозначное число
        hourStr = "0" + QString::number(Hour);
    else {
        hourStr = QString::number(Hour);
    }
    QString minuteStr;
    if(Minute < 10)//если часы - однозначное число
        minuteStr = "0" + QString::number(Minute);
    else {
        minuteStr = QString::number(Minute);
    }

    QString str = dayStr + hourStr + ":" + minuteStr;
    return str;
}
