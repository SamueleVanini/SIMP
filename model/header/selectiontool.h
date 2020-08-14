#ifndef SELECTIONTOOL_H
#define SELECTIONTOOL_H

#include "model/header/tool.h"
#include "model/header/entity.h"
#include <QPoint>
#include <QObject>

class SelectionTool : public QObject, public Tool
{
    Q_OBJECT

public:
    SelectionTool(Scene *scene, EnvStyle *style);
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
    Entity* getSelectedEntity();
    bool _isMousePressed;
    bool _hasMoved;
};


#endif // SELECTIONTOOL_H
