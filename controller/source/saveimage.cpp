#include "controller/header/saveimage.h"

#include <QPainter>

SaveImage::SaveImage(Scene *scene, int width, int height) : _scene(scene), _image(QSize(width, height), QImage::Format_RGB32) {}

SaveImage::~SaveImage()
{
    delete _scene;
}

bool SaveImage::saveImage(const QString &filePath)
{
    QPainter painter(&_image);
    _scene->drawAllEntity(&painter);
    return _image.save(filePath);
}
