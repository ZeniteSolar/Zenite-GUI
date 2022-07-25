#ifndef GYROSCOPE_H
#define GYROSCOPE_H


class Gyroscope
{
public:
    Gyroscope();

    struct sensor_gyro { float _accelX, _accelY, _accelZ, 
                            _gyroX, _gyroY, _gyroZ, 
                            _yaw, _pitch, _row; };

    sensor_gyro GetGyro();

private:
    // Planned friend class CAN
    friend class Acceleration;
    sensor_gyro _my_gyro;

    void SetGyroRaw(float ax, float ay, float az, float gx, float gy, float gz);
    
    //TODO:
    void CalculateYaw(sensor_gyro gyro_structure);
};

#endif // GYROSCOPE_H
