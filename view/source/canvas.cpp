#include "view/header/canvas.h"

#include "QPainter"
#include "QMouseEvent"

Canvas::Canvas(QWidget *parent, Scene *scene, Tool *activeTool) : QWidget(parent), _scene(scene), _activeTool(activeTool)
{
    setBackgroundColor(Qt::white);
}

Canvas::~Canvas()
{
    delete _activeTool;
}

void Canvas::setBackgroundColor(QColor color)
{
    QPalette Pal;
    Pal.setColor(QPalette::Background, color);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

void Canvas::setActiveTool(Tool *tool)
{
    _activeTool = tool;
}

void Canvas::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe)

    QPainter *painter = new QPainter(this);

    _scene->drawAllEntity(painter);

    delete painter;
}

bool Canvas::event(QEvent *event)
{
    if (event->type() == QEvent::Paint) {
        QPaintEvent *pe = reinterpret_cast<QPaintEvent *>(event);
        paintEvent(pe);
        return true;
    }

    bool result = _activeTool->handleEvent(event);

    repaint();

    return result;
}
