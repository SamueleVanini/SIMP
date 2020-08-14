#ifndef TOOL_H
#define TOOL_H

#include "QEvent"
#include "model/header/scene.h"
#include "controller/header/envstyle.h"

class QMouseEvent;
class Scene;
class Entity;
class QColor;

class Tool
{
public:
    Tool(Scene *scene, EnvStyle *style);
    virtual ~Tool();
    bool handleEvent(QEvent *event);

protected:

    virtual void mousePress(QMouseEvent*) =0;
    virtual void mouseMove(QMouseEvent*) =0;
    virtual void mouseRelease(QMouseEvent*) =0;

    Scene *_scene;
    EnvStyle *_style;

    static Entity *_lastEntity;
};

#endif // TOOL_H
