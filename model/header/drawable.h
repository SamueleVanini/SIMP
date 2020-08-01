#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QRect>

class QPainter;

class Drawable
{
public:
    /**
     * @brief draw metodo impiegato per disegnare un oggetto
     * @param painter oggetto della libreria Qt che andrà a disegnare l'oggetto
     */
    virtual void draw(QPainter *painter) const = 0;

    /**
     * @brief getBoundary metodo impiegato per avere il rettangolo che circonda un oggetto disegnabile
     * @return QRect rettangolo della libreria Qt che circonda l'oggetto disegnabile
     */
    virtual QRect getBoundary() const = 0;

    /**
     * @brief Distruttore
     */
    virtual ~Drawable() {}
};

#endif
