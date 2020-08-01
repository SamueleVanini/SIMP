#ifndef ENTITY_H
#define ENTITY_H

#include "model/header/selectable.h"
#include "model/header/drawable.h"
#include "model/header/trasformable.h"

#include "QColor"

class QPainter;
class Group;
class ActiveSelection;

class Entity : public Drawable, public Selectable, public Transformable
{
public:

    Entity(QColor lineColor = Qt::black, int lineThickness = 4, bool selected = false);

    virtual ~Entity();

    /**
     * @brief date delle coordinate dicono se quel punto appartiene all'oggetto
     * @param x coordinata ascissa
     * @param y coordinata ordinata
     * @return indicazione true/false
     */
    virtual bool contains(int x, int y) const = 0;

    /**
     * @brief setSelected cambia lo stato di selezione con val
     * @param val nuovo stato di selezione
     */
    void setSelected(bool state) override;

    /**
     * @brief toogleSelect trigghera un oggetto sullo stato di selezionato
     */
    void toogleSelect() override;

    /**
     * @brief isSelected ritorna se un oggetto è selezionato
     * @return indiazione se un oggetto è selezionato (true/false)
     */
    bool isSelected() const override;

    /**
     * @brief setLineColor setta il colore della linea di contorno dell'oggetto
     * @param color indica il colore da impostare
     */
    void setLineColor(const QColor &color);

    /**
     * @brief getLineColor ritorna il colore della linea di contorno dell'oggetto
     * @return QColor colore della linea
     */
    QColor getLineColor() const;

    /**
     * @brief setLineThickness setta lo spessore della linea di contorno dell'oggetto
     * @param thickness spessore della linea
     */
    void setLineThickness(int thickness);

    /**
     * @brief getLineThickness ritorna lo spessore della linea di contorno dell'oggetto
     * @return int spessore della linea
     */
    int getLineThickness() const;

protected:
    QColor _lineColor;
    int _lineThickness;
};

#endif // ENTITY_H
