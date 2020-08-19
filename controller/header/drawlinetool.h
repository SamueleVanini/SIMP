#ifndef DRAWLINETOOL_H
#define DRAWLINETOOL_H

#include "model/header/line.h"
#include "controller/header/tool.h"

#include <QPoint>

class DrawLineTool : public Tool
{
public:
    DrawLineTool();
    virtual ~DrawLineTool();

protected:
    virtual void mousePress(QMouseEvent *event) override;
    virtual void mouseMove(QMouseEvent *event) override;
    virtual void mouseRelease(QMouseEvent *event) override;

private:
    Line *_line;
    bool _clickPressed;    
};

#endif // DRAWLINETOOL_H
