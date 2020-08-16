#ifndef SCENE_H
#define SCENE_H

#include "model/header/entity.h"
#include <vector>

class Scene
{
public:
    Scene();
    ~Scene();
    void addEntity(Entity *entity);
    void drawAllEntity(QPainter *painter);
    Entity* getLastInsertedEntity();
    Entity* getEntityFromPosition(int x, int y);
    void deleteEntityFromPosition(int x, int y);
    Entity* findSelectedEntity();

private:
    std::vector<Entity*> _scene;
};

#endif // SCENE_H
