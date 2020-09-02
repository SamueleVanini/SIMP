#include "controller/header/envstyle.h"
#include "view/header/mainwindow.h"

// PUBLIC

EnvStyle::EnvStyle(MainWindow *ui, QColor lineColor, QColor fillColor, int thickness): _ui(ui), _lineColor(lineColor), _fillColor(fillColor), _thickness(thickness)
{
    connect(_ui, SIGNAL(lineColorChanged(QColor)), this, SLOT(changeLineColor(QColor)));
    connect(_ui, SIGNAL(lineThicknessChanged(int)), this, SLOT(changeLineThickness(int)));
    connect(_ui, SIGNAL(fillColorChanged(QColor)), this, SLOT(changeFillColor(QColor)));
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
    emit lineColorChanged(color);
}

void EnvStyle::changeFillColor(QColor color)
{
    setFillColor(color);
    emit fillColorChanged(color);
}


void EnvStyle::changeLineThickness(int value)
{
    setThickness(value);
    emit thicknessChanged(value);
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
