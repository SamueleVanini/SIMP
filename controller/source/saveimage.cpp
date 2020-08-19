#include "controller/header/saveimage.h"
#include "model/header/singleton.h"

#include <QPainter>

SaveImage::SaveImage(int width, int height) : _image(QSize(width, height), QImage::Format_RGB32) {}

SaveImage::~SaveImage()
{
}

bool SaveImage::saveImage(const QString &filePath)
{
    QPainter painter(&_image);
    Singleton::getInstance(nullptr)->getActualSceneInstance()
            .drawAllEntity(&painter);
    return _image.save(filePath);
}
