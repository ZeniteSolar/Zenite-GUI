#ifndef GPS_H
#define GPS_H

#include "main.h"

#include <time.h>

class GPS
{
public:
    GPS();
    float GetLatitude();
    float GetLongitude();
    struct tm GetTime();
    char* GetAscTime();

private:
    //friend class CAN;
    friend class Navigation;

    void SetCoordinates(float lat, float longi);
    //void SetTime(int sec, int min, int hour, int day, int mon, int year);
    void SetTime();

    struct tm _time_struct;
    float _latitude, _longitude;
};

#endif // GPS_H
