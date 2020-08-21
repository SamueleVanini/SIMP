#include "controller/header/tool.h"

Tool::Tool(){}

Tool::~Tool()
{
}

bool Tool::handleEvent(QEvent *event)
{
    QMouseEvent *me;
    switch(event->type())
    {
        case QEvent::MouseButtonPress:
            me = reinterpret_cast<QMouseEvent *>(event);
            mousePress(me);
            return true;
        case QEvent::MouseMove:
            me = reinterpret_cast<QMouseEvent *>(event);
            mouseMove(me);
            return true;
        case QEvent::MouseButtonRelease:
            me = reinterpret_cast<QMouseEvent *>(event);
            mouseRelease(me);
            emit canvasModified();
            return true;
        default:
            return false;
    }
 }

Entity* Tool::_lastEntity = nullptr;
