#include "controller/header/drawcircletool.h"
#include "model/header/singleton.h"

DrawCircleTool::DrawCircleTool() : _circle(nullptr), _clickPressed(false) {}

DrawCircleTool::~DrawCircleTool()
{
    delete _circle;
}

void DrawCircleTool::mousePress(QMouseEvent *event)
{
    _clickPressed = true;

    _circle = new Circle(event->pos());
    _circle->setLineColor(Singleton::getInstance()->getActualStyleInstance().getLineColor());
    _circle->setLineThickness(Singleton::getInstance()->getActualStyleInstance().getThickness());
    _circle->setFillColor(Singleton::getInstance()->getActualStyleInstance().getFillColor());
    //Se inserisco una nuova shape l'ultima inserta nella scena va deselezionata
    if(_lastEntity)
        _lastEntity->setSelected(false);
    _lastEntity = _circle;
    Singleton::getInstance()->getActualSceneInstance().addEntity(_circle);
}

void DrawCircleTool::mouseMove(QMouseEvent *event)
{
    if (_clickPressed)
    {
        QPoint centre = _circle->getPosition();
        _circle->setRadius((centre - event->pos()).manhattanLength());
    }
}

void DrawCircleTool::mouseRelease(QMouseEvent *)
{
    _clickPressed = false;
    _circle->setSelected(true);
}
