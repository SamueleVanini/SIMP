#ifndef TOOL_H
#define TOOL_H

#include "QEvent"
#include "model/header/singleton.h"

class QMouseEvent;
class Scene;
class Entity;
class QColor;

class Tool : public QObject
{
    Q_OBJECT

public:
    Tool();
    virtual ~Tool();
    bool handleEvent(QEvent *event);

signals:
    void canvasModified();

protected:

    virtual void mousePress(QMouseEvent*) =0;
    virtual void mouseMove(QMouseEvent*) =0;
    virtual void mouseRelease(QMouseEvent*) =0;

    static Entity *_lastEntity;
};

#endif // TOOL_H