#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "navigation.h"
#include "acceleration.h"

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLayout>
#include <QPixmap>
#include <QScreen>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

// Interface Setup
    QScreen *screen;
    screen = qGuiApp->primaryScreen();
    QSize size = screen->size();
    int screenwidth = size.width();
    int screenheight = size.height();

    centralWidget()->setGeometry(0,0,screenwidth,screenheight);
    this->repaint();

// Image Setup
    labelzenite = new QLabel(this);
    QPixmap logoZenite;
    logoZenite.load("zenitesolar.png");
    labelzenite->setPixmap(logoZenite);
    labelzenite->setScaledContents(true);
    labelzenite->setGeometry(round(screenwidth/4), 45, round(screenwidth/2), round(screenheight/1.33333));
    labelzenite->repaint();

    // Active Widget Setup
    QFont *button_font = new QFont();
    button_font->setPointSize(28);

    exit_button = new QPushButton("X", this);
    exit_button->setFont(*button_font);
    exit_button->setGeometry(1333,0,33,33);
    connect(exit_button, &QPushButton::clicked, this, &MainWindow::Exit_button_clicked);

    navig_button = new QPushButton("Navegação", this);
    navig_button->setFont(*button_font);
    navig_button->setGeometry(0,638,682,130);
    connect(navig_button, &QPushButton::clicked, this, &MainWindow::Navigation_clicked);

    accel_button = new QPushButton("Aceleração", this);
    accel_button->setFont(*button_font);
    accel_button->setGeometry(684,638,682,130);
    connect(accel_button, &QPushButton::clicked, this, &MainWindow::Acceleration_clicked);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::CloseSecondaryWindows()
{
    navDialogPointer->close();
    accDialogPointer->close();
}

void MainWindow::setNavDialog(Navigation *p)
{
   navDialogPointer=p;
}

void MainWindow::setAccDialog(Acceleration *p)
{
   accDialogPointer=p;
}

Navigation* MainWindow::getNavDialog()
{
    return navDialogPointer;
}

Acceleration* MainWindow::getAccDialog()
{
    return accDialogPointer;
}

void MainWindow::Exit_button_clicked()
{
    this->close();
}

void MainWindow::Navigation_clicked()
{
    navDialogPointer->NavWindowCall();
}

void MainWindow::Acceleration_clicked()
{
    accDialogPointer->AccWindowCall();
}


