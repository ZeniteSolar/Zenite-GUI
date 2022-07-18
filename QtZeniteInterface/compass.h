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
    std::vector<float*> GetRaw();

private:
    const vector<float*> _mag_pointers {&_x_mag, &_y_mag, &_z_mag}; 
    float _x_mag, _y_mag, _z_mag;
    float _heading;

};

#endif // COMPASS_H
