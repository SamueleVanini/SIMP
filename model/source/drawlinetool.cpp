#include "model/header/drawlinetool.h"
#include "model/header/tool.h"
#include "view/header/canvas.h"
#include "controller/header/envstyle.h"
#include <QMouseEvent>


DrawLineTool::DrawLineTool(Canvas *canvas, EnvStyle *style) : Tool(canvas, style), _clickPressed(false) {}

DrawLineTool::~DrawLineTool() {}

void DrawLineTool::mousePress(QMouseEvent *event)
{
    _clickPressed = true;
    _startPosition = event->pos();

    _line = new Line(_startPosition, _startPosition);
    _line->setLineColor(_style->getLineColor());
    _line->setLineThickness(_style->getThickness());
    //Se inserisco una nuova shape l'ultima inserta nel canvas va deselezionata
    Entity *lastInsertedEntity = _canvas->getLastInsertedEntity();
    if(lastInsertedEntity)
        lastInsertedEntity->setSelected(false);
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
}

