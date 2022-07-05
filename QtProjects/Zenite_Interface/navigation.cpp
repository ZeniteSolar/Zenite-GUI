#include "navigation.h"

#include "ui_navigation.h"
#include "acceleration.h"
#include "displayponteiro.h"

#include <QPushButton>

Navigation::Navigation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Navigation)
{
    ui->setupUi(this);

    // Inicialização dos displays estilo ponteiro
    _compassDisplay = new DisplayPonteiro(this);
    _compassDisplay->setGeometry(1039,60,200,200);
    _compassDisplay->show();

    accel = new QPushButton("Aceleração", this);
    accel->setGeometry(0,580,660,120);
    connect(accel, &QPushButton::clicked, this, &Navigation::on_Acceleration_clicked);

    mainmenu = new QPushButton("Menu Principal", this);
    mainmenu->setGeometry(660,580,660,120);
    connect(mainmenu, &QPushButton::clicked, this, &Navigation::on_MainMenu_clicked);
}

Navigation::~Navigation()
{
    delete ui;
}

void Navigation::NavWindowCall()
{
    this->setModal(true);
    this->exec();
}

void Navigation::on_MainMenu_clicked()
{
    this->close();
}


void Navigation::on_Acceleration_clicked()
{
    this->close();
    Acceleration acc;
    acc.AccWindowCall();
}


void Navigation::on_compass_dial_sliderMoved(int position)
{
    DisplayPonteiro *pointerdisp = this->_compassDisplay;
    pointerdisp->RotateToValue(position);
}

