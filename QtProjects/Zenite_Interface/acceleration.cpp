#include "acceleration.h"


Acceleration::Acceleration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Acceleration)
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
    navi->setGeometry(0,638,682,130);
    connect(navi, &QPushButton::clicked, this, &Acceleration::Navigation_clicked);

    mainmenu = new QPushButton("Menu Principal", this);
    mainmenu->setGeometry(684,638,682,130);
    connect(mainmenu, &QPushButton::clicked, this, &Acceleration::MainMenu_clicked);

}

Acceleration::~Acceleration()
{
    delete ui;
}

void Acceleration::AccWindowCall()
{
    this->showFullScreen();
    this->open();
}

void Acceleration::MainMenu_clicked()
{
    mainwindow_pointer->CloseSecondaryWindows();
}


void Acceleration::Navigation_clicked()
{
    mainwindow_pointer->getNavDialog()->NavWindowCall();
}


void Acceleration::on_yaw_dial_sliderMoved(int position)
{
    DisplayPonteiro *pointerdisp = this->_pitchDisplay;
    pointerdisp->RotateToValue(position);
}

