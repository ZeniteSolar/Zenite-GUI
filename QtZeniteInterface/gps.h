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

    tm GetTime();

private:
    //friend class CAN;
    friend class Navigation;

    void SetCoordinates(float lat, float longi);
    //void SetTime(int sec, int min, int hour, int day, int mon, int year);
    void SetTime();

    tm _time_struct;
    float _latitude, _longitude;
};

#endif // GPS_H
