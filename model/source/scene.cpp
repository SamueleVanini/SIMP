#include "model/header/scene.h"


Scene::Scene()
{

}

Scene::~Scene()
{
    for(auto ci = _scene.begin(); ci != _scene.end(); ci++)
    {
        delete *ci;
        *ci = nullptr;
    }
}

Entity* Scene::getEntityFromPosition(int x, int y)
{
    for(auto cit = _scene.begin(); cit != _scene.end(); ++cit)
    {
        if((*cit)->contains(x,y))
        {
            return *cit;
        }
    }
    return nullptr;
}

void Scene::addEntity(Entity* entity)
{
    _scene.push_back(entity);
}

Entity* Scene::getLastInsertedEntity()
{
    Entity *last = nullptr;
    if(!_scene.empty())
        last = _scene.back();
    return last;
}

void Scene::drawAllEntity(QPainter *painter)
{
    for(auto cit = _scene.begin(); cit != _scene.end(); ++cit)
    {
        (*cit)->draw(painter);
    }
}

Entity* Scene::findSelectedEntity()
{
    for(auto cit = _scene.begin(); cit != _scene.end(); ++cit)
    {
        if((*cit)->isSelected())
        {
            return *cit;
        }
    }
    return nullptr;
}

