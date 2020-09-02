#ifndef CIRCLE_H
#define CIRCLE_H

#include "model/header/entity.h"

class Circle : public Entity
{
public:

    Circle(const QPoint &p1, int _radius = 1, QColor lineColor = Qt::black, QColor fillColor = Qt::white, int lineThickness = 4, bool selected = false);

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
    QPoint getCentre() const;

    /**
     * @brief setCentre setta il nuovo centro del cerchio
     * @param p punto QPoint
     */
    void setCentre(const QPoint &p);

    /**
     * @brief getRadius ritorna il raggio del cerchio
     * @return int raggio del cerchio
     */
    int getRadius() const;

    /**
     * @brief setRadius setta il nuovo raggio del cerchio
     * @param radius raggio del cerchio
     */
    void setRadius(int radius);


private:
    QPoint _centre;
    int _radius;
};

#endif // CIRCLE_H
