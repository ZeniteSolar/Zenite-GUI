#include "compass.h"

Compass::Compass()
{
    this->_x_mag = 0;
    this->_x_mag = 0;
    this->_x_mag = 0;
    this->heading = 0;
}

void Compass::SetHeading(heading_angle)
{
    this->_heading = heading_angle;
}
void Compass::SetRaw(float x, float y, float z)
{
    this->_x_mag = x;
    this->_y_mag = y;
    this->_z_mag = z;
}
float Compass::GetHeading()
{
    return _heading;
}
vector<float*> Compass::GetRaw()
{
    return _mag_pointers;
}