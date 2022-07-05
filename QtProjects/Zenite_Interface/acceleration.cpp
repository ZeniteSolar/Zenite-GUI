#include "acceleration.h"
#include "ui_acceleration.h"
#include "navigation.h"
#include "displayponteiro.h"

#include <QPushButton>

Acceleration::Acceleration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acceleration)
{
    ui->setupUi(this);

    // Inicialização dos displays estilo ponteiro
    DisplayPonteiro *yawdisp, *pitchdisp, *rowdisp;

    yawdisp = new DisplayPonteiro(this);
    pitchdisp = new DisplayPonteiro(this);
    rowdisp = new DisplayPonteiro(this);

    this->_yawDisplay= yawdisp;
    this->_pitchDisplay= pitchdisp;
    this->_rowDisplay= rowdisp;

    _yawDisplay->setGeometry(100,98,300,300);
    _pitchDisplay->setGeometry(520,98,300,300);
    _rowDisplay->setGeometry(940,98,300,300);

    _yawDisplay->show();
    _pitchDisplay->show();
    _rowDisplay->show();

    navi = new QPushButton("Navegação", this);
    navi->setGeometry(0,580,660,120);
    connect(navi, &QPushButton::clicked, this, &Acceleration::on_Navigation_clicked);

    mainmenu = new QPushButton("Menu Principal", this);
    mainmenu->setGeometry(660,580,660,120);
    connect(mainmenu, &QPushButton::clicked, this, &Acceleration::on_MainMenu_clicked);

}

Acceleration::~Acceleration()
{
    delete ui;
}

void Acceleration::AccWindowCall()
{
    this->setModal(true);
    this->exec();
}

void Acceleration::on_MainMenu_clicked()
{
    this->close();
}


void Acceleration::on_Navigation_clicked()
{
    this->close();
    Navigation nav;
    nav.NavWindowCall();
}


void Acceleration::on_yaw_dial_sliderMoved(int position)
{
    DisplayPonteiro *pointerdisp = this->_pitchDisplay;
    pointerdisp->RotateToValue(position);
}

