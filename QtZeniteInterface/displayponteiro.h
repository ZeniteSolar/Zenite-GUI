#ifndef DISPLAYPONTEIRO_H
#define DISPLAYPONTEIRO_H

#include <QWidget>

class DisplayPonteiro : public QWidget
{
    Q_OBJECT
public:
    /*explicit*/ DisplayPonteiro(QWidget *parent = nullptr);
    DisplayPonteiro(QWidget *parent, float value);
    float _value;
    void AddRotValue(int value);
    void RotateToValue(int value);
    //~DisplayPonteiro();

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // DISPLAYPONTEIRO_H
