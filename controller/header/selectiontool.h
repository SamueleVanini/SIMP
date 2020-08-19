#ifndef SELECTIONTOOL_H
#define SELECTIONTOOL_H

#include "controller/header/tool.h"
#include "model/header/entity.h"
#include <QPoint>
#include <QObject>

class SelectionTool : public Tool
{
    Q_OBJECT

public:
    SelectionTool();
    ~SelectionTool();

public slots:
    void changeLineColor(QColor color);
    void changeFillColor(QColor color);
    void changeLineThickness(int value);

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent*) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    bool _isMousePressed;
    bool _hasMoved;
};


#endif // SELECTIONTOOL_H
