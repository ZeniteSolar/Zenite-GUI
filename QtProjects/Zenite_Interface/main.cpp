#include "mainwindow.h"
#include "navigation.h"
#include "acceleration.h"

#include <QMainWindow>
#include <QGuiApplication>
#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainw;
    mainw.showFullScreen();

    Navigation *nav = new Navigation(&mainw);
    mainw.setNavDialog(nav);

    Acceleration *acc = new Acceleration(&mainw);
    mainw.setAccDialog(acc);


    return a.exec();
    /*
     * Sensor Init
     */
}
