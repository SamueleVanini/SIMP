#include "controller/header/deletetool.h"

#include "model/header/selectiontool.h"
#include "view/header/canvas.h"
#include <QMouseEvent>

DeleteTool::DeleteTool(Scene *scene, EnvStyle *style) : Tool(scene, style) {}

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
    _scene->deleteEntityFromPosition(event->pos().x(), event->pos().y());
}