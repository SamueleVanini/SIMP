#include "controller/header/selectiontool.h"
#include "view/header/canvas.h"
#include <QMouseEvent>

SelectionTool::SelectionTool() : _isMousePressed(false), _hasMoved(false)
{
    connect(&(Singleton::getInstance()->getActualStyleInstance()), SIGNAL(lineColorChanged(QColor)), this, SLOT(changeLineColor(QColor)));
    connect(&(Singleton::getInstance()->getActualStyleInstance()), SIGNAL(fillColorChanged(QColor)), this, SLOT(changeFillColor(QColor)));
    connect(&(Singleton::getInstance()->getActualStyleInstance()), SIGNAL(thicknessChanged(int)), this, SLOT(changeLineThickness(int)));

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

    //cerca la entity che si vuole selezionare per applicare lo stato di selezionata
    _lastEntity = Singleton::getInstance()->getActualSceneInstance().getEntityFromPosition(event->pos().x(), event->pos().y());

    if (_lastEntity != nullptr) {
        _lastEntity->toogleSelect();
    }
}

void SelectionTool::mouseMove(QMouseEvent *event)
{
    //sposta l'Entity selezionata
    if (_isMousePressed && _lastEntity) {
        _lastEntity->setPosition(event->pos());
        _hasMoved = true;
    }
}

void SelectionTool::mouseRelease(QMouseEvent *event)
{
    Q_UNUSED(event)
    _hasMoved = false;
    _isMousePressed = false;
}

void SelectionTool::changeLineColor(QColor color)
{
    Entity *e = Singleton::getInstance()->getActualSceneInstance().findSelectedEntity();
    if(e)
    {
        e->setLineColor(color);
    }
}

void SelectionTool::changeFillColor(QColor color)
{
    Entity *e = Singleton::getInstance()->getActualSceneInstance().findSelectedEntity();
    if(e)
    {
        e->setFillColor(color);
    }
}

void SelectionTool::changeLineThickness(int value)
{
    Entity *e = Singleton::getInstance()->getActualSceneInstance().findSelectedEntity();
    if(e)
    {
        e->setLineThickness(value);
    }
}
