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
    /**
     * @brief setBackgroundColor imposta lo sfondo del canvas
     * @param color colore di sfondo del canvas
     */
    void setBackgroundColor(QColor color);
    /**
     * @brief setActiveTool imposta il tool attivo
     * @param activeTool puntatore polimorfo al tool attivo
     */
    void setActiveTool(const std::shared_ptr<Tool>& activeTool);

public slots:
    /**
     * @brief changeCanvasDimension ridimensiona il canvas
     * @param width nuova largezza
     * @param height nuova altezza
     */
    void changeCanvasDimension(unsigned int width, unsigned int height);

protected:
    /**
     * @brief paintEvent aggiorna il canvas
     * @param event evento che provoca l'aggiornamento del canvas
     */
    void paintEvent(QPaintEvent *event) override;
    /**
     * @brief event discrimina l'aggiornamento del canvas dagli altri eventi
     * @param event evento da gestire
     * @return indicazione se l'evento $event e` stato gestito
     */
    bool event(QEvent *event) override;

private:
    std::shared_ptr<Tool> _activeTool;
    int _width;
    int _height;
};

#endif // CANVAS_H
