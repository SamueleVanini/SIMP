#ifndef SINGLETON_H
#define SINGLETON_H

#include "model/header/scene.h"
#include "controller/header/envstyle.h"

class Singleton
{
public:

    static Singleton* getInstance(MainWindow *ui);

    Scene& getActualSceneInstance();
    EnvStyle& getActualStyleInstance();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    Singleton(MainWindow *ui);

    static Singleton *_singleton;
    Scene _scene;
    EnvStyle _style;
};

#endif // SINGLETON_H
