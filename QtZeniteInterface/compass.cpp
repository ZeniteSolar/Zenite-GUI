#include "compass.h"

Compass::Compass()
{
    SetRaw(0, 0, 0);
    SetHeading(0);
}

void Compass::SetHeading(float heading_angle)
{
    _heading = heading_angle;
}
void Compass::SetRaw(float x, float y, float z)
{
    _mag_struct._x_mag = x;
    _mag_struct._y_mag = y;
    _mag_struct._z_mag = z;
}

float Compass::GetHeading()
{
    return _heading;
}

Compass::magnitude Compass::GetRaw()
{
    return _mag_struct;
}
