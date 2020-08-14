#ifndef CANVAS_H
#define CANVAS_H

#include "model/header/entity.h"
#include "model/header/tool.h"
#include "model/header/scene.h"

#include "QWidget"

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = 0, Scene *scene = nullptr, Tool *activeTool = nullptr);
    virtual ~Canvas();
    void setBackgroundColor(QColor color);
    void addEntity(Entity *entity);
    Entity* getLastInsertedEntity();
    void setActiveTool(Tool *tool);

protected:
    void paintEvent(QPaintEvent *event) override;
    bool event(QEvent *event) override;

private:
    Scene *_scene;
    Tool *_activeTool;
};

#endif // CANVAS_H
