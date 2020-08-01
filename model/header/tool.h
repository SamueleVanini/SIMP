#ifndef TOOL_H
#define TOOL_H

class QEvent;
class QMouseEvent;
class Canvas;

class Tool
{
public:
    virtual ~Tool();

    virtual bool handleEvent(QEvent *event) =0;

protected:

    Tool(Canvas *canvas) : _canvas(canvas) {}

    virtual void mousePress(QMouseEvent*) =0;
    virtual void mouseMove(QMouseEvent*) =0;
    virtual void mouseRelease(QMouseEvent*) =0;

    Canvas *_canvas;
};

#endif // TOOL_H
