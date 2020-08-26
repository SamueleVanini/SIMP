#include "model/header/scene.h"


Scene::Scene()
{

}

Scene::~Scene()
{
    bool isSceneEmpty = _scene.empty();
    if(!isSceneEmpty)
    {
        for(auto ci = _scene.begin(); ci != _scene.end(); ci++)
        {
            delete *ci;
            *ci = nullptr;
        }
        _scene.clear();
    }
}

Entity* Scene::getEntityFromPosition(int x, int y)
{
    //for(auto cit = _scene.begin(); cit != _scene.end(); ++cit)
    for(unsigned i=_scene.size(); i-- >0;)
    {
        if((_scene[i])->contains(x,y))
        {
            return _scene[i];
        }
    }
    return nullptr;
}

void Scene::deleteEntityFromPosition(int x, int y)
{
    for(auto it = _scene.begin(); it != _scene.end(); ++it)
    {
        if((*it)->contains(x,y))
        {
            _scene.erase(it);
            return;
        }
    }
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

void Scene::deleteAll()
{
   _scene.erase(_scene.begin(), _scene.end());
}
