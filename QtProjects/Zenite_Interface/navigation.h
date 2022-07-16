#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QDialog>
#include <QPushButton>
#include <QScreen>
#include <QSize>

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
    void NavWindowCall();
    ~Navigation();

private slots:
    void MainMenu_clicked();

    void Acceleration_clicked();

    void on_compass_dial_sliderMoved(int position);

private:
    Ui::Navigation *ui;
    MainWindow *mainwindow_pointer;
    QPushButton *accel, *mainmenu;
};

#endif // NAVIGATION_H
