#include "model/header/selectiontool.h"
#include "view/header/canvas.h"
#include <QMouseEvent>

SelectionTool::SelectionTool(Canvas *canvas, EnvStyle *style) : Tool(canvas, style), _isMousePressed(false), _hasMoved(false) {}

SelectionTool::~SelectionTool()
{
}

void SelectionTool::mousePress(QMouseEvent *event)
{
    _isMousePressed = true;
    //_mousePressedLoc = event->pos();

    //deseleziona l'ultima entità selezionata prima di selezionare quella nuova
    if (_lastEntity != nullptr) {
        _lastEntity->setSelected(false);
    }

    _lastEntity = _canvas->getEntityFromPosition(event->pos().x(), event->pos().y());

    if (_lastEntity != nullptr) {
        _lastEntity->toogleSelect();
    }
}

void SelectionTool::mouseMove(QMouseEvent *event)
{
    if (_isMousePressed && _lastEntity) {
        _lastEntity->setPosition(event->pos());
        _hasMoved = true;
    }
}

void SelectionTool::mouseRelease(QMouseEvent *event)
{
    Q_UNUSED(event)
    if(_lastEntity == nullptr)
    {
        if(_lastEntity)
            _lastEntity->setSelected(false);
    }
    _hasMoved = false;
    _isMousePressed = false;
}

