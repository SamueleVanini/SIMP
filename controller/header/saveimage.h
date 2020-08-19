#ifndef SAVEIMAGE_H
#define SAVEIMAGE_H

#include <QImage>
#include <QString>

class SaveImage
{
public:
    SaveImage(int width = 800, int height = 600);
    ~SaveImage();

    bool saveImage(const QString&);

private:
    QImage _image;
};

#endif // SAVEIMAGE_H
