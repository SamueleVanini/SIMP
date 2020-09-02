#ifndef DRAWRECTANGLETOOL_H
#define DRAWRECTANGLETOOL_H

#include "controller/header/tool.h"
#include "model/header/rectangle.h"

#include <QMouseEvent>

class DrawRectangleTool : public Tool
{
public:
    DrawRectangleTool();
    virtual ~DrawRectangleTool();

protected:
    virtual void mousePress(QMouseEvent *event) override;
    virtual void mouseMove(QMouseEvent *event) override;
    virtual void mouseRelease(QMouseEvent *event) override;

private:
    Rectangle *_rectangle;
    bool _clickPressed;
};

#endif // DRAWRECTANGLETOOL_H
