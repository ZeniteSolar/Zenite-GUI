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
    float latitude, longitude, voltage1, voltage2, voltage3, heading; //, yaw, pitch, row;

    fgets(texto, 64, fp);

    QTimer::singleShot(0, &a, [&texto, &fp, &id, &nav, &acc, &latitude, &longitude,
                       &voltage1, &voltage2, &voltage3, &heading]{
                       //&yaw, &pitch, &row]{

        fgets(texto, 64, fp);

        while(fscanf(fp, "%d,%f,%f,%f,%f,%f,%f,%f", &latitude, &longitude,
              &voltage1, &voltage2, &voltage3, &heading) == 8) {

        }

        /*QFile Data_CSV("C:/Users/gabri/OneDrive/Área de Trabalho/Barco/Zenite-Interface-PRG22107/QtZeniteInterface/logger_data.csv");
        if(Data_CSV.open(QIODevice::ReadOnly)) {

            int lineindex = 0;                     // file line counter
            QTextStream in(&Data_CSV);                 // read to text stream

            while (!in.atEnd()) {

                // read one line from textstream(separated by "\n")
                QString fileLine = in.readLine();

                // parse the read line into separate pieces(tokens) with "," as the delimiter
                QStringList lineToken = fileLine.split(",", QString::SkipEmptyParts);

                // load parsed data to model accordingly
                for (int j = 0; j < lineToken.size(); j++) {
                    nav->_compassDisplay->RotateToValue(lineToken.at(0));
                }

                lineindex++;
            }

        }*/
        fclose(fp);
    });

    return a.exec();
    /*
     * Sensor Init
     */
}
