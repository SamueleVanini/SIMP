#include "view/header/canvas.h"

#include "QPainter"
#include "QMouseEvent"

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
    setBackgroundColor(Qt::white);
}

Canvas::~Canvas()
{
}

Entity* Canvas::getEntityFromPosition(int x, int y)
{
    for(auto cit = scene.begin(); cit != scene.end(); ++cit)
    {
        if((*cit)->contains(x,y))
        {
            return *cit;
        }
    }
    return nullptr;
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

void Canvas::addEntity(Entity* entity)
{
    scene.push_back(entity);
}

Entity* Canvas::getLastInsertedEntity()
{
    return scene.back();
}

void Canvas::paintEvent(QPaintEvent *pe)
{
    QPainter *painter = new QPainter(this);

    for(auto cit = scene.begin(); cit != scene.end(); ++cit)
    {
        (*cit)->draw(painter);
    }

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
