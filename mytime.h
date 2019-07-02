#ifndef MYTIME_H
#define MYTIME_H

class Time
{
private:
    int Hour;
    int Minute;
    int Day;
    int CountDay;
public:
    void SetHour(int NewHour);
    void SetMinute(int NewMinute);
    int GetHour();
    int GetMinute();
    void AddMinute(int Min);
    Time();
    Time(int NewHour, int NewMinute, int NewDay, int NewCountDay);
};



#endif // MYTIME_H
