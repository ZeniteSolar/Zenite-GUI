#ifndef COMPASS_H
#define COMPASS_H

#include "main.h"

#include <vector>

using namespace std;

class Compass
{
public:
    Compass();

    void SetHeading(float heading_angle);
    void SetRaw(float x, float y, float z);
    float GetHeading();
    struct GetRaw();

private:
    struct { float _x_mag, _y_mag, _z_mag; } _mag_struct;
    float _heading;

};

#endif // COMPASS_H
