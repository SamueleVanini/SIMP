#include "view/header/canvas.h"

#include "QPainter"
#include "QMouseEvent"

#include <iostream>

Canvas::Canvas(QWidget *parent, Scene *scene, Tool *activeTool, int width, int height) : QWidget(parent), _scene(scene), _activeTool(activeTool), _width(width), _height(height)
{
    setBackgroundColor(Qt::white);
}

Canvas::~Canvas()
{
    delete _scene;
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

void Canvas::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    std::cout << width() << " " << height();
}
