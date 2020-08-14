#include "model/header/selectiontool.h"
#include "view/header/canvas.h"
#include <QMouseEvent>

SelectionTool::SelectionTool(Scene *scene, EnvStyle *style) : Tool(scene, style), _isMousePressed(false), _hasMoved(false)
{
    connect(_style, SIGNAL(lineColorChanged(QColor)), this, SLOT(changeLineColor(QColor)));
    connect(_style, SIGNAL(fillColorChanged(QColor)), this, SLOT(changeFillColor(QColor)));
    connect(_style, SIGNAL(thicknessChanged(int)), this, SLOT(changeLineThickness(int)));

}

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

    _lastEntity = _scene->getEntityFromPosition(event->pos().x(), event->pos().y());

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

void SelectionTool::changeLineColor(QColor color)
{
    Entity *e = getSelectedEntity();
    if(e)
    {
        e->setLineColor(color);
    }
}

void SelectionTool::changeFillColor(QColor color)
{
    Entity *e = getSelectedEntity();
    if(e)
    {
        e->setFillColor(color);
    }
}

void SelectionTool::changeLineThickness(int value)
{
    Entity *e = getSelectedEntity();
    if(e)
    {
        e->setLineThickness(value);
    }
}

Entity* SelectionTool::getSelectedEntity()
{
    return _scene->findSelectedEntity();
}
