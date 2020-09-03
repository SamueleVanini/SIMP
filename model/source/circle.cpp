#include "model/header/circle.h"

#include <QPainter>

Circle::Circle(const QPoint &centre, int radius, const QColor& lineColor, const QColor& fillColor, int lineThickness, bool selected)
     : Entity(lineColor, fillColor, lineThickness, selected), _centre(centre), _radius(radius) {}

void Circle::draw(QPainter *painter) const
{
    QPen pen(getLineColor());
    QBrush brush(getFillColor());
    pen.setWidth(_lineThickness);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(_centre, _radius, _radius);


    if(_selected)
    {
        QBrush brush;
        QPen pen(Qt::DotLine);
        pen.setWidth(2);
        painter->setBrush(brush);
        pen.setColor(QColor(Qt::black));
        painter->setPen(pen);
        painter->drawRect(getBoundary());
    }
}

QRect Circle::getBoundary() const
{
    int rad = _radius + _lineThickness/2 + 3;

    int x = _centre.x() - rad;
    int y = _centre.y() - rad;
    int w = rad * 2;
    int h = w;

    return QRect(x, y, w, h);
}

bool Circle::contains(int x, int y) const
{
    int relX = x - _centre.x();
    int relY = y - _centre.y();
    int distanceFromOrigin = (relX * relX) + (relY * relY);

    // not quite sure why the offset is needed, but it clicks better...
    int rad = _radius + _lineThickness/2;

    return distanceFromOrigin <= (rad * rad);
}

void Circle::setPosition(const QPoint &pos)
{
    _centre = pos;
}

QPoint Circle::getPosition() const
{
    return _centre;
}

int Circle::getRadius() const
{
    return _radius;
}

void Circle::setRadius(int radius)
{
    _radius = radius;
}
