#ifndef ENVSTYLE_H
#define ENVSTYLE_H

#include "view/header/mainwindow.h"

#include <QColor>
#include <QObject>

class EnvStyle : public QObject
{
    Q_OBJECT

public:
    EnvStyle(MainWindow *ui, QColor lineColor = Qt::black, QColor fillColor = Qt::white, int thickness = 2);
    QColor getLineColor();
    QColor getFillColor();
    int getThickness();

public slots:
    void changeLineColor(QColor color);
    void changeFillColor(QColor color);
    void changeLineThikness(int value);

private:

    void setLineColor(QColor color);
    void setFillColor(QColor color);
    void setThickness(int value);

    MainWindow *_ui;
    QColor _lineColor;
    QColor _fillColor;
    int _thickness;
};

#endif // ENVSTYLE_H
