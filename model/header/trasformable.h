#ifndef TRASFORMABLE_H
#define TRASFORMABLE_H

#include <QPoint>

class Transformable
{
public:
    /**
     * @brief setPosition setta la nuova posizione di un oggetto (come l'oggetto
     * decide di posizionarsi è a descrizione dell'implementazione)
     * @param pos nuova posizione
     */
    virtual void setPosition(const QPoint &pos) = 0;

    /**
     * @brief getPosition ritorna la posizione dell'oggetto
     * @return QPoint
     */
    virtual QPoint getPosition() = 0;

    /**
     * @brief Distruttore
     */
    virtual ~Transformable() {}

};
#endif // TRASFORMABLE_H
