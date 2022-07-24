#ifndef COMPASS_H
#define COMPASS_H

#include "main.h"

#include <vector>

using namespace std;

class Compass
{
public:
    Compass();

    float GetHeading();

    struct magnitude { float _x_mag, _y_mag, _z_mag; };

    magnitude GetRaw();

private:
    //friend class CAN;
    friend class Navigation;
    
    void SetHeading(float heading_angle);
    void SetRaw(float x, float y, float z);
    
    magnitude _mag_struct;
    float _heading;

};

#endif // COMPASS_H
