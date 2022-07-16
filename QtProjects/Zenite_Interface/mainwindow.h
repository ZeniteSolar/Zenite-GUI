#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

#include "main.h"

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
    void Exitbutton_clicked();

    void Navigation_clicked();

    void Acceleration_clicked();

private:
    Ui::MainWindow *ui;
    Navigation *navDialogPointer;
    Acceleration *accDialogPointer;
    QPushButton *navi, *accel, *exitbutton;
    QLabel *labelzenite;
    QWidget *mainwidget;
};
#endif // MAINWINDOW_H
