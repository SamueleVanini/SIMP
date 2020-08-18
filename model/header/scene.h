#ifndef SCENE_H
#define SCENE_H

#include "model/header/entity.h"
#include <vector>

class Scene
{
public:
    void addEntity(Entity *entity);
    void drawAllEntity(QPainter *painter);
    Entity* getLastInsertedEntity();
    Entity* getEntityFromPosition(int x, int y);
    void deleteEntityFromPosition(int x, int y);
    Entity* findSelectedEntity();

private:
    Scene();
    ~Scene();
    std::vector<Entity*> _scene;

    friend class Singleton;
};

#endif // SCENE_H
