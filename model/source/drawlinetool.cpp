#include "model/header/drawlinetool.h"
#include "model/header/tool.h"
#include "view/header/canvas.h"
#include "controller/header/envstyle.h"
#include <QMouseEvent>


DrawLineTool::DrawLineTool() : _clickPressed(false) {}

DrawLineTool::~DrawLineTool()
{
    delete _line;
}

void DrawLineTool::mousePress(QMouseEvent *event)
{
    _clickPressed = true;

    _line = new Line(event->pos(), event->pos());
    _line->setLineColor(Singleton::getInstance(nullptr)->getActualStyleInstance().getLineColor());
    _line->setLineThickness(Singleton::getInstance(nullptr)->getActualStyleInstance().getThickness());
    //Se inserisco una nuova shape l'ultima inserta nella scena va deselezionata
    if(_lastEntity)
        _lastEntity->setSelected(false);
    _lastEntity = _line;
    Singleton::getInstance(nullptr)->getActualSceneInstance().addEntity(_line);
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

