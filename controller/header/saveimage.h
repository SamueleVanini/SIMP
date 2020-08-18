#ifndef SAVEIMAGE_H
#define SAVEIMAGE_H

#include "model/header/scene.h"
#include <QImage>
#include <QString>

class SaveImage
{
public:
    SaveImage(Scene *scene, int width = 800, int height = 600);
    ~SaveImage();

    bool saveImage(const QString&);

private:
    Scene *_scene;
    QImage _image;
};

#endif // SAVEIMAGE_H
