#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QDialog>
#include <QPushButton>
#include <QScreen>
#include <QSize>
#include <QFont>
#include <QLCDNumber>

#include "main.h"

#include "ui_navigation.h"


class DisplayPonteiro;
class GPS;
class Compass;
class ElectricData;
class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class Navigation; }
QT_END_NAMESPACE

class Navigation : public QDialog
{
    Q_OBJECT

public:
    explicit Navigation(QWidget *parent = nullptr);
    DisplayPonteiro *_compassDisplay;
    QLCDNumber *_latitude_lcd, *_longitude_lcd, *_vbat1_lcd, *_vbat2_lcd, *_vbat3_lcd;
    void NavWindowCall();
    ~Navigation();
    void SetPointers(ElectricData* electric, GPS* sensor_pointer, Compass* sensor_compass);
    void UpdateWidgets(float lat, float lgt, float v1, float v2, float v3, float heading);

private slots:
    void MainMenu_clicked();

    void Acceleration_clicked();

private:
    Ui::Navigation *ui;
    MainWindow *mainwindow_pointer;
    QPushButton *accel_button, *mainmenu_button;
    ElectricData *_electricdata_pointer;
    GPS *_gps_pointer;
    Compass *_compass_pointer;
};

#endif // NAVIGATION_H
