#ifndef DRAWCIRCLETOOL_H
#define DRAWCIRCLETOOL_H

#include "model/header/circle.h"
#include "controller/header/tool.h"
#include <QMouseEvent>

class DrawCircleTool : public Tool
{
public:
    DrawCircleTool();
    virtual ~DrawCircleTool();

protected:
    virtual void mousePress(QMouseEvent *event) override;
    virtual void mouseMove(QMouseEvent *event) override;
    virtual void mouseRelease(QMouseEvent *event) override;

private:
    Circle *_circle;
    bool _clickPressed;
};

#endif // DRAWCIRCLETOOL_H
