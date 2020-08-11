#ifndef TOOL_H
#define TOOL_H

#include "QEvent"
class QMouseEvent;
class Canvas;
class EnvStyle;

class Tool
{
public:
    Tool(Canvas *canvas) : _canvas(canvas) {}
    virtual ~Tool() {}

    virtual bool handleEvent(QEvent *event)
    {
        QMouseEvent *me;
        switch(event->type())
        {
            case QEvent::MouseButtonPress:
                me = reinterpret_cast<QMouseEvent *>(event);
                mousePress(me);
                return true;
            case QEvent::MouseMove:
                me = reinterpret_cast<QMouseEvent *>(event);
                mouseMove(me);
                return true;
            case QEvent::MouseButtonRelease:
                me = reinterpret_cast<QMouseEvent *>(event);
                mouseRelease(me);
                return true;
            default:
                return false;
        }
     }

protected:

    virtual void mousePress(QMouseEvent*) =0;
    virtual void mouseMove(QMouseEvent*) =0;
    virtual void mouseRelease(QMouseEvent*) =0;

    Canvas *_canvas;
    EnvStyle *_style;
};

#endif // TOOL_H
