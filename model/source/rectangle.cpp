#include "model/header/rectangle.h"

#include <QPainter>

Rectangle::Rectangle(const QPoint &vertex, int width, int height, const QColor& lineColor, const QColor& fillColor, int lineThickness, bool selected)
     : Entity(lineColor, fillColor, lineThickness, selected), _topLeftVertex(vertex), _width(width), _height(height) {}

void Rectangle::draw(QPainter *painter) const
{
    QPen pen(getLineColor());
    QBrush brush(getFillColor());
    pen.setWidth(_lineThickness);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(_topLeftVertex.x(), _topLeftVertex.y(), _width, _height);

    if(_selected)
    {
        QBrush brush;
        QPen pen(Qt::DotLine);
        pen.setWidth(2);
        painter->setBrush(brush);
        pen.setColor(QColor(Qt::black));
        painter->setPen(pen);
        painter->drawRect(getBoundary().adjusted(-3, -3, 3, 3));
    }
}

QRect Rectangle::getBoundary() const
{
    int extra = _lineThickness / 2;
    return QRect(_topLeftVertex.x(), _topLeftVertex.y(), _width, _height).adjusted(-extra, -extra, extra, extra);
}

bool Rectangle::contains(int x, int y) const
{
    return QRect(_topLeftVertex.x(), _topLeftVertex.y(), _width, _height).contains(x, y);
}

void Rectangle::setPosition(const QPoint &pos)
{
    _topLeftVertex = pos;
}

QPoint Rectangle::getPosition() const
{
    return _topLeftVertex;
}

int Rectangle::getWidth() const
{
    return _width;
}

void Rectangle::setWidth(int width)
{
    _width = width;
}
int Rectangle::getHeight() const
{
    return _height;
}

void Rectangle::setHeight(int height)
{
    _height = height;
}
