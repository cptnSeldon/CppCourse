#include <iostream>

#include "time.h"

using namespace std;

#pragma region CONSTRUCTORS
Time::Time() : hour(0), minute(0), second(0) { }
//Time::Time() : Time(0, 0, 0) {}

Time::Time(int hour, int minute, int second)
{
    this->adjust(0,0,0);
    this->adjust(hour, minute, second);
}

Time::Time(int second)
{
    this->adjust(0,0,0);
    this->setSecond(second);
}

Time::Time(const Time & timeToCopy)
{
    //*this = timeToCopy;
    this->setHour(timeToCopy.getHour());
    this->setMinute(timeToCopy.getMinute());
    this->setSecond(timeToCopy.getSecond());
}
#pragma endregion CONSTRUCTORS

#pragma region SETTERS
void Time::setHour(int hour)
{
    if(hour >= 0)
    {
        this->hour = hour % 24;
    }
}
void Time::setMinute(int minute)
{
    if(minute >= 0)
    {
        this->minute = minute % 60;

        this->hour += minute / 60;

        setHour(this->hour);
    }
}
void Time::setSecond(int second)
{
    if(second >= 0)
    {
        this->second = second % 60;

        this->minute += second / 60;

        setMinute(this->minute);
    }
}
#pragma endregion SETTERS

#pragma region MISC FUNCTIONS
void Time::adjust(int hour, int minute, int second)
{
    this->setHour(hour);
    this->setMinute(minute);
    this->setSecond(second);
}

void Time::show()
{
    cout << this->hour << ":" << this->minute << ":" << this->second << endl;
}
Time Time::add(const Time & time) const
{
    Time t;

    t.setHour(this->hour + time.hour);
    t.setMinute(this->minute + time.minute);
    t.setSecond(this->second + time.second);

    return t;
}
#pragma endregion MISC FUNCTIONS