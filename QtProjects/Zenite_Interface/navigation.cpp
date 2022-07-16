#include "navigation.h"

Navigation::Navigation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation)
{
    ui->setupUi(this);

    mainwindow_pointer = qobject_cast<MainWindow*>(this->parent());

    QScreen *screen;
    screen = qGuiApp->primaryScreen();
    QSize size = screen->size();
    int screenwidth = size.width();
    int screenheight = size.height();
    this->setGeometry(0,0,screenwidth,screenheight);
    this->repaint();

    // Inicialização dos displays estilo ponteiro
    _compassDisplay = new DisplayPonteiro(this);
    _compassDisplay->setGeometry(1039,60,200,200);
    _compassDisplay->show();

    accel = new QPushButton("Aceleração", this);
    accel->setGeometry(0,638,682,130);
    connect(accel, &QPushButton::clicked, this, &Navigation::Acceleration_clicked);

    mainmenu = new QPushButton("Menu Principal", this);
    mainmenu->setGeometry(684,638,682,130);
    connect(mainmenu, &QPushButton::clicked, this, &Navigation::MainMenu_clicked);

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


void Navigation::on_compass_dial_sliderMoved(int position)
{
    DisplayPonteiro *pointerdisp = this->_compassDisplay;
    pointerdisp->RotateToValue(position);
}

