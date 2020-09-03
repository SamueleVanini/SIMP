#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "model/header/entity.h"

class Rectangle : public Entity
{
public:
    Rectangle(const QPoint &vertex, int width = 1, int height = 1, const QColor& lineColor = Qt::black, const QColor& fillColor = Qt::white, int lineThickness = 4, bool selected = false);

    /**
     * @brief draw metodo impiegato per disegnare il rettangolo
     * @param painter oggetto della libreria Qt che andrà a disegnare il rettangolo
     */
    virtual void draw(QPainter *painter) const override;

    /**
     * @brief getBoundary metodo impiegato per avere il rettangolo che circonda il rettangolo
     * @return QRect rettangolo della libreria Qt che circonda il rettangolo
     */
    virtual QRect getBoundary() const override;

    /**
     * @brief date delle coordinate dicono se quel punto appartiene al rettangolo
     * @param x coordinata ascissa
     * @param y coordinata ordinata
     * @return indicazione true/false
     */
    virtual bool contains(int x, int y) const override;

    /**
     * @brief setPosition setta la nuova posizione del rettangolo
     * @param pos nuova posizione del rettangolo
     */
    virtual void setPosition(const QPoint &pos) override;

    /**
     * @brief getPosition ritorna la posizione del cerchio
     * @return QPoint posizione del cerchio
     */
    virtual QPoint getPosition() const override;

    /**
     * @brief getTopLeftVertex ritorna il vertice in alto a sinistra del rettangolo
     * @return QPoint centro del cerchio
     */
    QPoint getTopLeftVertex() const;

    /**
     * @brief setTopLeftVertex setta il nuovo vertice in alto a sinistra del rettangolo
     * @param p punto QPoint
     */
    void setTopLeftVertex(const QPoint &p);

    /**
     * @brief getWidth ritorna la larghezza del rettangolo
     * @return int larghezza del rettangolo
     */
    int getWidth() const;

    /**
     * @brief setWidth setta la nuova larghezza del rettangolo
     * @param width larghezza del rettangolo
     */
    void setWidth(int width);

    /**
     * @brief getHeight ritorna l'altezza del rettangolo
     * @return int altezza del rettangolo
     */
    int getHeight() const;

    /**
     * @brief setHeight setta la nuova altezza del rettangolo
     * @param height altezza del rettangolo
     */
    void setHeight(int height);



private:
    QPoint _topLeftVertex;
    int _width;
    int _height;
};

#endif // RECTANGLE_H
