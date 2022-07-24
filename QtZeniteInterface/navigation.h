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
    QLCDNumber *_latitude, *_longitude, *_vbat1, *_vbat2, *_vbat3;
    void NavWindowCall();
    ~Navigation();

private slots:
    void MainMenu_clicked();

    void Acceleration_clicked();

private:
    Ui::Navigation *ui;
    MainWindow *mainwindow_pointer;
    QPushButton *accel_button, *mainmenu_button;
};

#endif // NAVIGATION_H
