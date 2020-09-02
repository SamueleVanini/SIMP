#ifndef SAVEIMAGE_H
#define SAVEIMAGE_H

#include "view/header/canvas.h"
#include <QObject>
#include <QString>

class SaveImage : public QObject
{
    Q_OBJECT

public:
    SaveImage() = default;
    virtual ~SaveImage() {}

public slots:
    void saveImage(const QString&, Canvas*);

};

#endif // SAVEIMAGE_H
