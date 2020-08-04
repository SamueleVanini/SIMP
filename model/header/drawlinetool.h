#ifndef DRAWLINETOOL_H
#define DRAWLINETOOL_H

#include "model/header/line.h"
#include "model/header/tool.h"

#include <QPoint>

class DrawLineTool : public Tool
{
public:
    DrawLineTool(Canvas *canvas);
    virtual ~DrawLineTool();

protected:
    virtual void mousePress(QMouseEvent *event) override;
    virtual void mouseMove(QMouseEvent *event) override;
    virtual void mouseRelease(QMouseEvent *event) override;

private:
    Line *_line;
    bool _clickPressed;
    QPoint _startPosition;
};

#endif // DRAWLINETOOL_H