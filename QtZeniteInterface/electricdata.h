#ifndef ELECTRICDATA_H
#define ELECTRICDATA_H

#include "main.h"

class ElectricData
{
public:
    ElectricData();

    struct batterybank {float _bat1volt, _bat1current, _bat2volt, _bat2current,
                        _bat3volt, _bat3current, _bankVoltage, _maxdeviation; };

    batterybank GetBBank();


private:
// TODO
    //friend class CAN;
    friend class Navigation;

    void SetMainBankData(float v1, float c1, float v2, float c2, float v3, float c3);
    void MeasureBank(batterybank bb);

    batterybank _mainbatterybank;
};

#endif // ELECTRICDATA_H


