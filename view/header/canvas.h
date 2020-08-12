#ifndef CANVAS_H
#define CANVAS_H

#include "model/header/entity.h"
#include "model/header/tool.h"

#include "QWidget"
#include <vector>

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = 0, Tool *activeTool = nullptr);
    virtual ~Canvas();
    Entity* getEntityFromPosition(int x, int y);
    void setBackgroundColor(QColor color);
    void addEntity(Entity *entity);
    Entity* getLastInsertedEntity();
    void setActiveTool(Tool *tool);

protected:
    void paintEvent(QPaintEvent *event) override;
    bool event(QEvent *event) override;

private:
    std::vector<Entity*> scene;
    Tool *_activeTool;
};

#endif // CANVAS_H
