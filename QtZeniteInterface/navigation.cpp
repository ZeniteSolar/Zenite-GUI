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


    // Initiate, set geometry and variables of this window's widgets
    _compassDisplay = new DisplayPonteiro(this);
    _compassDisplay->setGeometry(1039,60,200,200);

    _latitude = new QLCDNumber(this);
    _latitude->setGeometry(150, 40, 260, 125);
    _latitude->setDigitCount(5);
    _latitude->setMode(QLCDNumber::Dec);
    _latitude->setSegmentStyle(QLCDNumber::Filled);

    _longitude = new QLCDNumber(this);
    _longitude->setGeometry(150, 165, 260, 125);
    _longitude->setDigitCount(5);
    _longitude->setMode(QLCDNumber::Dec);
    _longitude->setSegmentStyle(QLCDNumber::Filled);

    _vbat1 = new QLCDNumber(this);
    _vbat1->setGeometry(660, 100, 141, 51);
    _vbat1->setDigitCount(5);
    _vbat1->setMode(QLCDNumber::Dec);
    _vbat1->setSegmentStyle(QLCDNumber::Filled);

    _vbat2 = new QLCDNumber(this);
    _vbat2->setGeometry(660, 160, 141, 51);
    _vbat2->setDigitCount(5);
    _vbat2->setMode(QLCDNumber::Dec);
    _vbat2->setSegmentStyle(QLCDNumber::Filled);

    _vbat3 = new QLCDNumber(this);
    _vbat3->setGeometry(660, 220, 141, 51);
    _vbat3->setDigitCount(5);
    _vbat3->setMode(QLCDNumber::Dec);
    _vbat3->setSegmentStyle(QLCDNumber::Filled);


    // Show said widgets
    _compassDisplay->show();
    _vbat1->show();
    _vbat2->show();
    _vbat3->show();




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

    // Create frames used for data display organization
    


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

