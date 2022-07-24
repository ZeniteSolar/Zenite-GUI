#include "gps.h"

GPS::GPS()
{
    SetCoordinates(0, 0);
    SetTime()
}

float GPS::GetLatitude()
{
    return _latitude;
}

float GPS::GetLongitude()
{
    return _longitude;
}

GPS::tm GPS::GetTime()
{
    return _time_struct;
}

char* GetAscTime()
{
    return asctime(&_time_struct);
}

void GPS::SetCoordinates(float lat, float longi)
{
    _latitude = lat;
    _longitude = longi;
}

//void GPS::SetTime(int sec, int min, int hour, int day, int mon, int year)
void GPS::SetTime()
{
    time_t current_time;
    time(&current_time);

    _time_struct = localtime(&current_time);
}