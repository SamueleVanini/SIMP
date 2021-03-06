#include "view/header/canvas.h"
#include "model/header/singleton.h"

#include "QPainter"
#include "QMouseEvent"
#include <QScrollArea>
#include <QLayout>

Canvas::Canvas(QWidget *parent, const std::shared_ptr<Tool>& activeTool, int width, int height) : QWidget(parent), _activeTool(activeTool), _width(width), _height(height)
{
    setBackgroundColor(Qt::white);
}

Canvas::~Canvas()
{
}

void Canvas::setBackgroundColor(QColor color)
{
    QPalette Pal;
    Pal.setColor(QPalette::Background, color);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

void Canvas::setActiveTool(const std::shared_ptr<Tool>& tool)
{
    _activeTool = tool;
}

void Canvas::changeCanvasDimension(unsigned int width, unsigned int height) {
    setFixedSize(width, height);
    _width=width;
    _height=height;
    resizeEvent(nullptr);
}

void Canvas::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe)

    QPainter *painter = new QPainter(this);

    Singleton::getInstance(nullptr)->getActualSceneInstance().drawAllEntity(painter);

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

    update();

    return result;
}
