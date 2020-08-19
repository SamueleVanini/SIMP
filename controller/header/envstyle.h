#ifndef ENVSTYLE_H
#define ENVSTYLE_H

class MainWindow;

#include <QColor>
#include <QObject>

class EnvStyle : public QObject
{
    Q_OBJECT

public:
    QColor getLineColor();
    QColor getFillColor();
    int getThickness();

public slots:
    void changeLineColor(QColor color);
    void changeFillColor(QColor color);
    void changeLineThickness(int value);

signals:
    void lineColorChanged(QColor);
    void fillColorChanged(QColor);
    void thicknessChanged(int);

private:
    EnvStyle(MainWindow *ui, QColor lineColor = Qt::black, QColor fillColor = Qt::white, int thickness = 2);
    //EnvStyle(const EnvStyle&);
    void setLineColor(QColor color);
    void setFillColor(QColor color);
    void setThickness(int value);

    MainWindow *_ui;
    QColor _lineColor;
    QColor _fillColor;
    int _thickness;

    friend class Singleton;
};

#endif // ENVSTYLE_H
