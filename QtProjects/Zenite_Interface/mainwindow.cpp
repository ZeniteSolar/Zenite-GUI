#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "navigation.h"
#include "acceleration.h"

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLayout>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    labelzenite = new QLabel(this);
    QPixmap logoZenite;
    logoZenite.load("zenitesolar.png");
    labelzenite->setPixmap(logoZenite);
    labelzenite->setScaledContents(true);
    labelzenite->setGeometry(360,45,600,540);

    navi = new QPushButton("Navegação", this);
    navi->setGeometry(0,580,660,120);
    connect(navi, &QPushButton::clicked, this, &MainWindow::on_Navigation_clicked);

    accel = new QPushButton("Aceleração", this);
    accel->setGeometry(660,580,660,120);
    connect(accel, &QPushButton::clicked, this, &MainWindow::on_Acceleration_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Navigation_clicked()
{
    Navigation nav;
    nav.NavWindowCall();
}


void MainWindow::on_Acceleration_clicked()
{
    Acceleration acc;
    acc.AccWindowCall();
}

