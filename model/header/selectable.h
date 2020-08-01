#ifndef SELECTABLE_H
#define SELECTABLE_H

#include "model/header/entity.h"

class Selectable
{
public:

    Selectable(bool selected = false) : _selected(selected) {}
    /**
     * @brief date delle coordinate dicono se quel punto appartiene all'oggetto
     * @param x coordinata ascissa
     * @param y coordinata ordinata
     * @return indicazione true/false
     */
    virtual bool contains(int x, int y) const = 0;

    /**
     * @brief cambia lo stato di selezione di un oggetto
     * @param val stato di selezione (true/false)
     */
    virtual void setSelected(bool val) = 0;

    /**
     * @brief triggera la modalità selezionato di un oggetto
     */
    virtual void toogleSelect() = 0;

    /**
     * @brief indica se un oggetto è stato selezionato
     * @return indicazione treu/false
     */
    virtual bool isSelected() const = 0;

    /**
     * @brief Distruttore della classe
     */
    virtual ~Selectable() {}

protected:
    bool _selected;
};

#endif // SELECTABLE_H
