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

    std::vector<time_t*> GetTimeToday();
    struct GetTimeCalendar();
    ReadTime();
    ReadPosition();

private:
    struct tm _time_struct;
    float latitude, longitude;
};

#endif // GPS_H
