#include "navigation.h"

Navigation::Navigation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation)
{
    ui->setupUi(this);

    mainwindow_pointer = qobject_cast<MainWindow*>(this->parent());



    // Get screen size, save to variables, scale window to fullscreen
    QScreen *screen;
    screen = qGuiApp->primaryScreen();
    QSize size = screen->size();
    int screenwidth = size.width();
    int screenheight = size.height();
    this->setGeometry(0,0,screenwidth,screenheight);
    this->repaint();


    // Create Buttons, set geometry and connect signals accordingly
    QFont *button_font = new QFont();
    button_font->setPointSize(26);

    accel_button = new QPushButton("Aceleração", this);
    accel_button->setFont(*button_font);
    accel_button->setGeometry(0,638,682,130);
    connect(accel_button, &QPushButton::clicked, this, &Navigation::Acceleration_clicked);
    
    mainmenu_button = new QPushButton("Menu Principal", this);
    mainmenu_button->setFont(*button_font);
    mainmenu_button->setGeometry(684,638,682,130);
    connect(mainmenu_button, &QPushButton::clicked, this, &Navigation::MainMenu_clicked);

    // Initiate, set geometry and variables of dialog widgets
    _compassDisplay = new DisplayPonteiro(this);
    _compassDisplay->setGeometry(1039,60,200,200);

    _latitude_lcd = new QLCDNumber(this);
    _latitude_lcd->setGeometry(150, 40, 260, 125);
    _latitude_lcd->setDigitCount(5);
    _latitude_lcd->setMode(QLCDNumber::Dec);
    _latitude_lcd->setSegmentStyle(QLCDNumber::Filled);

    _longitude_lcd = new QLCDNumber(this);
    _longitude_lcd->setGeometry(150, 165, 260, 125);
    _longitude_lcd->setDigitCount(5);
    _longitude_lcd->setMode(QLCDNumber::Dec);
    _longitude_lcd->setSegmentStyle(QLCDNumber::Filled);

    _vbat1_lcd = new QLCDNumber(this);
    _vbat1_lcd->setGeometry(660, 100, 141, 51);
    _vbat1_lcd->setDigitCount(5);
    _vbat1_lcd->setMode(QLCDNumber::Dec);
    _vbat1_lcd->setSegmentStyle(QLCDNumber::Filled);

    _vbat2_lcd = new QLCDNumber(this);
    _vbat2_lcd->setGeometry(660, 160, 141, 51);
    _vbat2_lcd->setDigitCount(5);
    _vbat2_lcd->setMode(QLCDNumber::Dec);
    _vbat2_lcd->setSegmentStyle(QLCDNumber::Filled);

    _vbat3_lcd = new QLCDNumber(this);
    _vbat3_lcd->setGeometry(660, 220, 141, 51);
    _vbat3_lcd->setDigitCount(5);
    _vbat3_lcd->setMode(QLCDNumber::Dec);
    _vbat3_lcd->setSegmentStyle(QLCDNumber::Filled);

    QFont *ClockFont = new QFont();
    ClockFont->setPointSize(24);
    _time_label = new QLabel(this);
    _time_label->setGeometry(510, 560, 400, 90);
    _time_label->setFont(*ClockFont);

    // Show said widgets
    _compassDisplay->show();
    _vbat1_lcd->show();
    _vbat2_lcd->show();
    _vbat3_lcd->show();
    _time_label->show();

}

void Navigation::SetPointers(ElectricData* electric, GPS* sensor_gps, Compass* sensor_compass)
{
    _electricdata_pointer = electric;
    _gps_pointer = sensor_gps;
    _compass_pointer = sensor_compass;
}

Navigation::~Navigation()
{
    delete ui;
}

void Navigation::NavWindowCall()
{
    this->showFullScreen();
    this->open();
}

void Navigation::MainMenu_clicked()
{
    mainwindow_pointer->CloseSecondaryWindows();
}


void Navigation::Acceleration_clicked()
{
    mainwindow_pointer->getAccDialog()->AccWindowCall();
}

void Navigation::UpdateWidgets(float lat, float lgt, float v1, float v2, float v3, float heading)
{
    /* Input values to data classes
     * In the future it will be done by can_check */
        _gps_pointer->SetCoordinates(lat, lgt);
        _electricdata_pointer->SetMainBankData(v1, 0, v2, 0, v3, 0);
        _compass_pointer->SetHeading(heading);
    //  These are private methods in data classes but Navigation Friendly (Planned CAN Friendly)

    // Update Widgets itself
    _latitude_lcd->display(_gps_pointer->GetLatitude());
    _longitude_lcd->display(_gps_pointer->GetLongitude());

    ElectricData::batterybank bbk = _electricdata_pointer->GetBBank();
    _vbat1_lcd->display(bbk._bat1volt);
    _vbat2_lcd->display(bbk._bat2volt);
    _vbat3_lcd->display(bbk._bat3volt);

    const QString & teste = _gps_pointer->GetTimeString();
    _time_label->setText(teste);

    _compassDisplay->RotateToValue(_compass_pointer->GetHeading());
}
