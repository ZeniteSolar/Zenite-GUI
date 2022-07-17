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


    // Initiate, set geometry and show pointer type displays contained in window
    _compassDisplay = new DisplayPonteiro(this);
    _compassDisplay->setGeometry(1039,60,200,200);
    _compassDisplay->show();


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

// #### UI created, used for demonstration only #### //
void Navigation::on_compass_dial_sliderMoved(int position)
{
    DisplayPonteiro *pointerdisp = this->_compassDisplay;
    pointerdisp->RotateToValue(position);
}

