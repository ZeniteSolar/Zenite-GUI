#include "gyroscope.h"

Gyroscope::Gyroscope()
{
    SetGyroRaw(0, 0, 0, 0, 0, 0);
}

void Gyroscope::SetGyroRaw(float ax, float ay, float az, float gx, float gy, float gz)
{
    _my_gyro._accelX = ax;
    _my_gyro._accelY = ay;
    _my_gyro._accelZ = az;

    _my_gyro._gyroX = gx;
    _my_gyro._gyroY = gy;
    _my_gyro._gyroZ = gz;
}

Gyroscope::sensor_gyro Gyroscope::GetGyro()
{
    return _my_gyro;
}

//TODO:
void Gyroscope::CalculateYaw(sensor_gyro gyro_structure)
{

}
