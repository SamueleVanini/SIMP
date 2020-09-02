#include "controller/header/drawrectangletool.h"
#include "model/header/singleton.h"

DrawRectangleTool::DrawRectangleTool() : _rectangle(nullptr), _clickPressed(false) {}

DrawRectangleTool::~DrawRectangleTool()
{
    delete _rectangle;
}

void DrawRectangleTool::mousePress(QMouseEvent *event)
{
    _clickPressed = true;

    _rectangle = new Rectangle(event->pos());
    _rectangle->setLineColor(Singleton::getInstance(nullptr)->getActualStyleInstance().getLineColor());
    _rectangle->setLineThickness(Singleton::getInstance(nullptr)->getActualStyleInstance().getThickness());
    _rectangle->setFillColor(Singleton::getInstance(nullptr)->getActualStyleInstance().getFillColor());
    //Se inserisco una nuova shape l'ultima inserta nella scena va deselezionata
    if(_lastEntity)
        _lastEntity->setSelected(false);
    _lastEntity = _rectangle;
    Singleton::getInstance(nullptr)->getActualSceneInstance().addEntity(_rectangle);
}

void DrawRectangleTool::mouseMove(QMouseEvent *event)
{
    if (_clickPressed)
    {
        QPoint vertex = _rectangle->getPosition();
        _rectangle->setWidth(event->pos().x() - vertex.x());
        _rectangle->setHeight(event->pos().y() - vertex.y());
    }
}

void DrawRectangleTool::mouseRelease(QMouseEvent *)
{
    _clickPressed = false;
    _rectangle->setSelected(true);
}
