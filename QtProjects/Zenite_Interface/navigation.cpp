#include "navigation.h"

#include "ui_navigation.h"
#include "mainwindow.h"
#include "acceleration.h"
#include "displayponteiro.h"

#include <QPushButton>
#include <QScreen>
#include <QSize>

Navigation::Navigation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation)
{
    ui->setupUi(this);

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
    MainWindow* mainw= qobject_cast<MainWindow*>(this->parent());
    Acceleration* accel = mainw->getAccDialog();
    accel->close();
    this->setModal(false);
    this->close();
}


void Navigation::Acceleration_clicked()
{
    MainWindow* mainw= qobject_cast<MainWindow*>(this->parent());
    Acceleration* accel = mainw->getAccDialog();
    accel->AccWindowCall();
}


void Navigation::on_compass_dial_sliderMoved(int position)
{
    DisplayPonteiro *pointerdisp = this->_compassDisplay;
    pointerdisp->RotateToValue(position);
}

