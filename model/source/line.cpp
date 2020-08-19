#include "model/header/line.h"
#include <QPainter>
#include <cmath>

Line::Line(const QPoint &p1, const QPoint &p2, QColor lineColor, int lineThickness, bool selected)
    : Entity(lineColor, Qt::black, lineThickness, selected), _p1(p1), _p2(p2) {}

void Line::draw(QPainter *painter) const
{
    QPen pen(getLineColor());
    pen.setWidth(_lineThickness);

    painter->setPen(pen);

    painter->drawLine(_p1, _p2);

    if(_selected)
    {
        QBrush brush;
        QPen pen(Qt::DotLine);
        pen.setWidth(2);
        painter->setBrush(brush);
        pen.setColor(QColor(250, 150, 150));
        painter->setPen(pen);
        painter->drawRect(getBoundary());
    }
}

/**
 * @brief date delle coordinate dicono se quel punto appartiene alla linea
 * @param x coordinata ascissa
 * @param y coordinata ordinata
 * @return indicazione true/false
 */
bool Line::contains(int x, int y) const
{
    float r = _lineThickness <= 4 ? 4 : _lineThickness; // impact margin

    if (!getBoundary().contains(x, y)) return false;

    // calculate whether line is clicked using circle-line intersection:
    float A, B, C, m, f, discriminant;

    float dx = _p2.x() - _p1.x();
    if (dx == 0) return true;

    // convert points m_p1 and m_p2 to the equation of the line y = mx + f
    m = float(_p2.y() - _p1.y()) / dx;
    f = _p1.y() - m * _p1.x();

    A = m*m + 1;
    B = 2 * (m*f - m*y - x);
    C = y*y - r*r + x*x - 2*f*y + f*f;

    discriminant = B*B - 4*A*C;

    return discriminant >= 0;
}

QRect Line::getBoundary() const
{
    int margin = _lineThickness <= 4 ? 4 : _lineThickness/2+2;

    int x = _p1.x() < _p2.x() ? _p1.x() : _p2.x();
    int y  = _p1.y() < _p2.y() ? _p1.y() : _p2.y();
    int w = std::abs(_p1.x() - _p2.x());
    int h = std::abs(_p1.y() - _p2.y());

    return QRect(x-margin, y-margin, w+margin*2, h+margin*2);;
}

void Line::setPosition(const QPoint &pos)
{
    QPoint diff = pos - getPosition();
    _p1 += diff;
    _p2 += diff;
}

QPoint Line::getPosition() const
{
    return QPoint((_p1.x() + _p2.x())/2,
                  (_p1.y() + _p2.y())/2);
}
QPoint Line::getP1() const
{
    return _p1;
}

void Line::setP1(const QPoint &p)
{
    _p1 = p;
}
QPoint Line::getP2() const
{
    return _p2;
}

void Line::setP2(const QPoint &p)
{
    _p2 = p;
}
