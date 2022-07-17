#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainw;
    mainw.showFullScreen();

    Navigation *nav = new Navigation(&mainw);
    mainw.setNavDialog(nav);

    Acceleration *acc = new Acceleration(&mainw);
    mainw.setAccDialog(acc);

    while(1){
        
    }
    return a.exec();
    /*
     * Sensor Init
     */
}
