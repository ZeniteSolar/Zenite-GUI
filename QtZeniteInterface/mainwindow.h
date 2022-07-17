#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLayout>
#include <QPixmap>
#include <QScreen>

#include "main.h"
#include <math.h>

#include "./ui_mainwindow.h"

class Navigation;
class Acceleration;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setNavDialog(Navigation *p);
    void setAccDialog(Acceleration *p);
    Navigation* getNavDialog();
    Acceleration* getAccDialog();

    void CloseSecondaryWindows();

private slots:
    void Exit_button_clicked();

    void Navigation_clicked();

    void Acceleration_clicked();

private:
    Ui::MainWindow *ui;
    Navigation *navDialogPointer;
    Acceleration *accDialogPointer;
    QPushButton *navig_button, *accel_button, *exit_button;
    QLabel *labelzenite;
    QWidget *mainwidget;
};
#endif // MAINWINDOW_H
