#include "gps.h"

GPS::GPS()
{
    SetCoordinates(0, 0);
    SetTime();
}

float GPS::GetLatitude()
{
    return _latitude;
}

float GPS::GetLongitude()
{
    return _longitude;
}

tm GPS::GetTime()
{
    return _time_struct;
}

const QString GPS::GetTimeString()
{
    time_t current_time;
    time(&current_time);
    const QString timestring = QString(ctime(&current_time));
    return timestring;
}

void GPS::SetCoordinates(float lat, float longi)
{
    _latitude = lat;
    _longitude = longi;
}

//void GPS::SetTime(int sec, int min, int hour, int day, int mon, int year)
void GPS::SetTime()
{
    // TODO set time via CAN
    time_t current_time;
    current_time = time(&current_time); // Returns *time_t with current calendar time

    tm* tpoint;
    tpoint = localtime(&current_time);
    _time_struct.tm_sec = tpoint->tm_sec;
    _time_struct.tm_min = tpoint->tm_min;
    _time_struct.tm_hour = tpoint->tm_hour;
    _time_struct.tm_mday = tpoint->tm_mday;
    _time_struct.tm_mon = tpoint->tm_mon;

}
