#include "model/header/entity.h"

#include <QPainter>

Entity::Entity(QColor lineColor, int lineThickness, bool selected)
    : Selectable(selected), _lineColor(lineColor), _lineThickness(lineThickness) {}

Entity::~Entity()
{
    setSelected(false);
}

/**
 * @brief setSelected cambia lo stato di selezione con val
 * @param val nuovo stato di selezione
 */
void Entity::setSelected(bool state)
{
    _selected = state;
}

/**
 * @brief toogleSelect trigghera un oggetto sullo stato di selezionato
 */
void Entity::toogleSelect()
{
    _selected = true;
}

/**
 * @brief isSelected ritorna se un oggetto è selezionato
 * @return indiazione se un oggetto è selezionato (true/false)
 */
bool Entity::isSelected() const
{
    return _selected;
}

/**
 * @brief setLineColor setta il colore della linea di contorno dell'oggetto
 * @param color indica il colore da impostare
 */
void Entity::setLineColor(const QColor &color)
{
    _lineColor = color;
}

/**
 * @brief getLineColor ritorna il colore della linea di contorno dell'oggetto
 * @return QColor colore della linea
 */
QColor Entity::getLineColor() const
{
    return _lineColor;
}

/**
 * @brief setLineThickness setta lo spessore della linea di contorno dell'oggetto
 * @param thickness spessore della linea
 */
void Entity::setLineThickness(int thickness)
{
    _lineThickness = thickness;
}

/**
 * @brief getLineThickness ritorna lo spessore della linea di contorno dell'oggetto
 * @return int spessore della linea
 */
int Entity::getLineThickness() const
{
    return _lineThickness;
}
