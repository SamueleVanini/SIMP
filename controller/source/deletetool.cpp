#include "controller/header/deletetool.h"

#include "view/header/canvas.h"
#include <QMouseEvent>

DeleteTool::DeleteTool(){}

DeleteTool::~DeleteTool()
{
}

void DeleteTool::mousePress(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void DeleteTool::mouseMove(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void DeleteTool::mouseRelease(QMouseEvent *event)
{
    Singleton::getInstance()->getActualSceneInstance().deleteEntityFromPosition(event->pos().x(), event->pos().y());
}
