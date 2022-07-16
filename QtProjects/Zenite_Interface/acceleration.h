#ifndef ACCELERATION_H
#define ACCELERATION_H

#include <QDialog>
#include <QPushButton>
#include <QSize>
#include <QScreen>

#include "main.h"

#include "ui_acceleration.h"

class DisplayPonteiro;
class MainWindow;

namespace Ui {
class Acceleration;
}

class Acceleration : public QDialog
{
    Q_OBJECT

public:
    explicit Acceleration(QWidget *parent = nullptr);
    DisplayPonteiro *_yawDisplay, *_pitchDisplay, *_rowDisplay;
    void AccWindowCall();
    ~Acceleration();

private slots:
    void MainMenu_clicked();

    void Navigation_clicked();

    void on_yaw_dial_sliderMoved(int position); //

private:
    Ui::Acceleration *ui;
    MainWindow *mainwindow_pointer;
    QPushButton *navi, *mainmenu;
};

#endif // ACCELERATION_H
