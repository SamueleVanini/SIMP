#ifndef CANVAS_H
#define CANVAS_H

#include "model/header/entity.h"
#include "controller/header/tool.h"
#include "model/header/scene.h"

#include <memory>
#include "QWidget"

class Canvas : public QWidget
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = 0, const std::shared_ptr<Tool>& activeTool = nullptr, int width = 800, int height = 600);
    virtual ~Canvas();
    void setBackgroundColor(QColor color);
    void setActiveTool(const std::shared_ptr<Tool>& activeTool);
    void setCanvasDimension(int width, int height);

public slots:
    void changeCanvasDimension(unsigned int width, unsigned int height);

protected:
    void paintEvent(QPaintEvent *event) override;
    bool event(QEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

private:
    std::shared_ptr<Tool> _activeTool;
    int _width;
    int _height;
};

#endif // CANVAS_H
