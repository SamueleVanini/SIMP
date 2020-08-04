#include "model/header/drawlinetool.h"
#include "view/header/canvas.h"
#include <QMouseEvent>

DrawLineTool::DrawLineTool(Canvas *canvas) : Tool(canvas), _clickPressed(false) {}

DrawLineTool::~DrawLineTool() {}

void DrawLineTool::mousePress(QMouseEvent *event)
{
    _clickPressed = true;
    _startPosition = event->pos();

    _line = new Line(_startPosition, _startPosition);
    _canvas->addEntity(_line);
}

void DrawLineTool::mouseMove(QMouseEvent *event)
{
    if (_clickPressed) {
        _line->setP2(event->pos());
    }
}

void DrawLineTool::mouseRelease(QMouseEvent *)
{
    _clickPressed = false;
    _line->setSelected(true);

    //DrawCommand *comm = new DrawCommand(m_line);
    //comm->addtoCommandStack();
}
