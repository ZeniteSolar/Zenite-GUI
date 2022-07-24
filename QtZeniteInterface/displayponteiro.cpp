#include "displayponteiro.h"
#include "acceleration.h"
#include "QPainter"
#include "QString"
#include "QPointF"

DisplayPonteiro::DisplayPonteiro(QWidget *parent)
    : QWidget(parent)
{
    this->_value = 0;
}

DisplayPonteiro::DisplayPonteiro(QWidget *parent, float value)
    : QWidget(parent)
{
    this->_value = value;
}

void DisplayPonteiro::paintEvent(QPaintEvent *)
{
    static const QPoint pointerHand[3] = {
        QPoint(8, 8),
        QPoint(-8, 8),
        QPoint(0, -80)
    };

    QColor painterColor(0, 0, 0);

    int side = qMin(width(), height());

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(painterColor);

    painter.save();
    painter.rotate(-DisplayPonteiro::_value);       // Increasing angle now rotates anti-clockwise
    painter.drawConvexPolygon(pointerHand, 3);
    painter.restore();

    painter.setPen(painterColor);

    for (int i = 0; i < 24; ++i) {
        painter.drawLine(88, 0, 96, 0);
        painter.rotate(15.0);
    }

    DisplayPonteiro::update();

}

void DisplayPonteiro::AddRotValue(float value){
    this->_value += value;
}

void DisplayPonteiro::RotateToValue(float value){
    this->_value = value;
}
