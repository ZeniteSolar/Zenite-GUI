#ifndef GPS_H
#define GPS_H

#include "main.h"

#include <time.h>

#include <QString>

class GPS
{
public:
    GPS();

    // TODO: get position to string, so it includes cardinals, degrees ° and  minutes "
    float GetLatitude();
    float GetLongitude();

    // Used for demonstration
    const QString GetTimeString();

    // TODO: iterative filter with acceleration data (from gyro)

    tm GetTime();

private:
    //friend class CAN;
    friend class Navigation;

    void SetCoordinates(float lat, float longi);

    // TODO: Set time via can
    void SetTime();

    tm _time_struct;
    float _latitude, _longitude;
};

#endif // GPS_H
