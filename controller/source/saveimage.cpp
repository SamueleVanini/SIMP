#include "controller/header/saveimage.h"

void SaveImage::saveImage(const QString &filePathName, Canvas *canvas)
{
    (canvas->grab().save(filePathName));
}
