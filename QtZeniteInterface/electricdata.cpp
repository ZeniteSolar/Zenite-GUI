#include "electricdata.h"

ElectricData::ElectricData()
{
    SetMainBankData(0, 0, 0, 0, 0, 0);
    MeasureBank(_mainbatterybank);

}

ElectricData::batterybank ElectricData::GetBBank()
{
    return _mainbatterybank;
}

void ElectricData::SetMainBankData(float v1, float c1, float v2, float c2, float v3, float c3)
{

    _mainbatterybank._bat1volt = v1;
    _mainbatterybank._bat2volt = v2;
    _mainbatterybank._bat3volt = v3;

    _mainbatterybank._bat1current = c1;
    _mainbatterybank._bat2current = c2;
    _mainbatterybank._bat3current = c3;
}

void ElectricData::MeasureBank(batterybank mybank)
{
    mybank._bankVoltage = mybank._bat1volt + mybank._bat2volt + mybank._bat3volt;
}
