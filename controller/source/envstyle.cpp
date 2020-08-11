#include "controller/header/envstyle.h"

EnvStyle::EnvStyle(QColor lineColor, QColor fillColor, int thickness): _lineColor(lineColor), _fillColor(fillColor), _thickness(thickness)
{

}

QColor EnvStyle::getLineColor()
{
    return _lineColor;
}

QColor EnvStyle::getFillColor()
{
    return _fillColor;
}

int EnvStyle::getThickness()
{
    return _thickness;
}

void EnvStyle::changeLineColor(QColor color)
{
    setLineColor(color);
}

void EnvStyle::changeFillColor(QColor color)
{
    setFillColor(color);
}


void EnvStyle::changeLineThikness(int value)
{
    setThickness(value);
}

void EnvStyle::setLineColor(QColor color)
{
    _lineColor = color;
}

void EnvStyle::setFillColor(QColor color)
{
    _fillColor = color;
}

void EnvStyle::setThickness(int value)
{
    _thickness = value;
}
