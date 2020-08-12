#include "model/header/selectiontool.h"
#include "view/header/canvas.h"
#include <QMouseEvent>

SelectionTool::SelectionTool(Canvas *canvas, EnvStyle *style) : Tool(canvas, style), _entityClicked(nullptr), _isMousePressed(false), _hasMoved(false) {}

SelectionTool::~SelectionTool()
{

}

void SelectionTool::mousePress(QMouseEvent *event)
{
    _isMousePressed = true;
    _mousePressedLoc = event->pos();

    _entityClicked = _canvas->getEntityFromPosition(event->pos().x(), event->pos().y());

    if (_entityClicked != nullptr) {
        _entityClicked->toogleSelect();
    }
}

void SelectionTool::mouseMove(QMouseEvent *event)
{
    if (_isMousePressed && _entityClicked) {
        _entityClicked->setPosition(event->pos());
        _hasMoved = true;
    }
}

void SelectionTool::mouseRelease(QMouseEvent *event)
{
    if(_entityClicked == nullptr)
    {
        Entity *lastInsertedEntity = _canvas->getLastInsertedEntity();
        if(lastInsertedEntity)
            lastInsertedEntity->setSelected(false);
    }
    _hasMoved = false;
    _isMousePressed = false;
}

