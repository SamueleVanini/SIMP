#include "model/header/singleton.h"

Singleton* Singleton::_singleton = nullptr;

Singleton* Singleton::getInstance(MainWindow *ui)
{
    if(_singleton == nullptr)
    {

        if(!ui)
        {
            throw SingletonException("Singleton istanziato la prima volta senza MainWindow");
        }
        else
        {
            _singleton = new Singleton(ui);
        }
    }
    return _singleton;
}

Scene& Singleton::getActualSceneInstance()
{
    return _scene;
}

EnvStyle& Singleton::getActualStyleInstance()
{
    return _style;
}

Singleton::Singleton(MainWindow *ui) : _scene(), _style{ui} {}
