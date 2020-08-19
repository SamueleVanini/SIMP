#ifndef LINE_H
#define LINE_H

#include "model/header/entity.h"

class Line : public Entity
{
public:

    Line(const QPoint &p1, const QPoint &p2, QColor lineColor = Qt::black, int lineThickness = 4, bool selected = false);

    /**
     * @brief draw metodo impiegato per disegnare la linea
     * @param painter oggetto della libreria Qt che andrà a disegnare la linea
     */
    virtual void draw(QPainter *painter) const override;

    /**
     * @brief getBoundary metodo impiegato per avere il rettangolo che circonda la linea
     * @return QRect rettangolo della libreria Qt che circonda la linea
     */
    virtual QRect getBoundary() const override;

    /**
     * @brief date delle coordinate dicono se quel punto appartiene alla linea
     * @param x coordinata ascissa
     * @param y coordinata ordinata
     * @return indicazione true/false
     */
    virtual bool contains(int x, int y) const override;

    /**
     * @brief setPosition setta la nuova posizione della linea
     * @param pos nuova posizione della linea
     */
    virtual void setPosition(const QPoint &pos) override;

    /**
     * @brief getPosition ritorna la posizione della linea
     * @return QPoint posizione della linea
     */
    virtual QPoint getPosition() const override;

    /**
     * @brief getP1 ritorna il primo punto che forma la linea
     * @return QPoint primo punto
     */
    QPoint getP1() const;

    /**
     * @brief setP1 setta il nuovo primo punto della linea
     * @param p punto QPoint
     */
    void setP1(const QPoint &p);

    /**
     * @brief getP2 ritorna il secondo punto che forma la linea
     * @return QPoint secondo punto
     */
    QPoint getP2() const;

    /**
     * @brief setP2 setta il nuovo secondo punto della linea
     * @param p punto QPoint
     */
    void setP2(const QPoint &p);


private:
    QPoint _p1;
    QPoint _p2;
};

#endif // LINE_H
