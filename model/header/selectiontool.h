#ifndef SELECTIONTOOL_H
#define SELECTIONTOOL_H

#pragma once

#include "model/header/tool.h"
#include "model/header/entity.h"
#include <QPoint>

class Group;
class ActiveSelection;
class GlobalDrawProperties;
class MoveSelectionCommand;
class VisualEntity;

class SelectionTool : public Tool
{
public:
    SelectionTool(Canvas *canvas);
    ~SelectionTool();

protected:
    void mousePress(QMouseEvent *event) override;
    void mouseMove(QMouseEvent*) override;
    void mouseRelease(QMouseEvent *event) override;

private:
    Entity *_entityClicked;
    bool _isMousePressed;
    bool _hasMoved;
    QPoint _mousePressedLoc;
    QPoint _p;
};


#endif // SELECTIONTOOL_H
