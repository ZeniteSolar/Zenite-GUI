#include "compass.h"

Compass::Compass()
{
    _x_mag = 0;
    _x_mag = 0;
    _x_mag = 0;
    _heading = 0;
}

void Compass::SetHeading(float heading_angle)
{
    _heading = heading_angle;
}
void Compass::SetRaw(float x, float y, float z)
{
    _x_mag = x;
    _y_mag = y;
    _z_mag = z;
}
float Compass::GetHeading()
{
    return _heading;
}
vector<float*> Compass::GetRaw()
{
    return _mag_pointers;
}
