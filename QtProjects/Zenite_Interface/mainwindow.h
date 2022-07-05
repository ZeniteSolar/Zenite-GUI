#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Navigation_clicked();

    void on_Acceleration_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton *navi, *accel;
    QLabel *labelzenite;
};
#endif // MAINWINDOW_H
