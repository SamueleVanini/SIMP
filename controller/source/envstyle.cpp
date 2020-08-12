#include "controller/header/envstyle.h"

// PUBLIC

EnvStyle::EnvStyle(MainWindow *ui, QColor lineColor, QColor fillColor, int thickness): _ui(ui), _lineColor(lineColor), _fillColor(fillColor), _thickness(thickness)
{
    connect(_ui, SIGNAL(lineColorChaneged(QColor)), this, SLOT(changeLineColor(QColor)));
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

// END PUBLIC

// SLOT

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

// END SLOT

// PRIVATE

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

// END PRIVATE
