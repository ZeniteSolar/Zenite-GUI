#include "main.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainw;
    mainw.showFullScreen();

    Navigation *nav = new Navigation(&mainw);
    mainw.setNavDialog(nav);

    Acceleration *acc = new Acceleration(&mainw);
    mainw.setAccDialog(acc);

    FILE *fp = fopen("C:/logger_data.csv", "r");

    if (!fp) {
        perror("File not found\n");
        return 0;
    }
    int id;
    char texto[64];
    float time, latitude, longitude, voltage1, voltage2, voltage3, heading; //, yaw, pitch, row;

    fgets(texto, 64, fp);

    auto timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, &a, [&texto, &fp, &id, &nav, &acc, &time, &latitude, &longitude,
            &voltage1, &voltage2, &voltage3, &heading]{
                       //&yaw, &pitch, &row]{

        fgets(texto, 64, fp);

        fscanf(fp, "%d,%f,%f,%f,%f,%f,%f,%f", &id, &time, &latitude, &longitude,
              &voltage1, &voltage2, &voltage3, &heading);
           // nav->_latitude->display(latitude);
           // nav->_longitude->display(longitude);
            nav->_vbat1->display(voltage1);
            nav->_vbat2->display(voltage2);
            nav->_vbat3->display(voltage3);
           // nav->_compassDisplay->RotateToValue(heading);
    });

    timer->start(1);

    return a.exec();
    /*
     * Sensor Init
     */
}
