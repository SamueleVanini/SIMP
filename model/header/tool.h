#ifndef TOOL_H
#define TOOL_H

#include "QEvent"
class QMouseEvent;
class Canvas;
class EnvStyle;
class Entity;

class Tool
{
public:
    Tool(Canvas *canvas, EnvStyle *style);
    virtual ~Tool();
    bool handleEvent(QEvent *event);

protected:

    virtual void mousePress(QMouseEvent*) =0;
    virtual void mouseMove(QMouseEvent*) =0;
    virtual void mouseRelease(QMouseEvent*) =0;

    Canvas *_canvas;
    EnvStyle *_style;

    static Entity *_lastEntity;
};

#endif // TOOL_H
