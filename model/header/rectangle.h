#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "model/header/entity.h"

class Rectangle : public Entity
{
public:
    Rectangle(const QPoint &vertex, int width = 1, int height = 1, QColor lineColor = Qt::black, int lineThickness = 4, bool selected = false);

    /**
     * @brief draw metodo impiegato per disegnare il cerchio
     * @param painter oggetto della libreria Qt che andrà a disegnare il cerchio
     */
    virtual void draw(QPainter *painter) const override;

    /**
     * @brief getBoundary metodo impiegato per avere il rettangolo che circonda il cerchio
     * @return QRect rettangolo della libreria Qt che circonda il cerchio
     */
    virtual QRect getBoundary() const override;

    /**
     * @brief date delle coordinate dicono se quel punto appartiene al cerchio
     * @param x coordinata ascissa
     * @param y coordinata ordinata
     * @return indicazione true/false
     */
    virtual bool contains(int x, int y) const override;

    /**
     * @brief setPosition setta la nuova posizione del cerchio
     * @param pos nuova posizione del cerchio
     */
    virtual void setPosition(const QPoint &pos) override;

    /**
     * @brief getPosition ritorna la posizione del cerchio
     * @return QPoint posizione del cerchio
     */
    virtual QPoint getPosition() const override;

    /**
     * @brief getCentre ritorna il centro del cerchio
     * @return QPoint centro del cerchio
     */
    QPoint getTopLeftVertex() const;

    /**
     * @brief setCentre setta il nuovo centro del cerchio
     * @param p punto QPoint
     */
    void setTopLeftVertex(const QPoint &p);

    /**
     * @brief getRadius ritorna il raggio del cerchio
     * @return int raggio del cerchio
     */
    int getWidth() const;

    /**
     * @brief setRadius setta il nuovo raggio del cerchio
     * @param radius raggio del cerchio
     */
    void setWidth(int width);

    /**
     * @brief getRadius ritorna il raggio del cerchio
     * @return int raggio del cerchio
     */
    int getHeight() const;

    /**
     * @brief setRadius setta il nuovo raggio del cerchio
     * @param radius raggio del cerchio
     */
    void setHeight(int height);



private:
    QPoint _topLeftVertex;
    int _width;
    int _height;
};

#endif // RECTANGLE_H
