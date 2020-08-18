#ifndef DELETETOOL_H
#define DELETETOOL_H

#include "model/header/tool.h"
#include "model/header/entity.h"
#include <QPoint>
#include <QObject>

class DeleteTool : public Tool
{

public:
    DeleteTool();
    ~DeleteTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent*) override;
    void mouseRelease(QMouseEvent *event) override;

};

#endif // DELETETOOL_H
