#ifndef TOOL_H
#define TOOL_H

#include "QEvent"
#include "model/header/singleton.h"

class QMouseEvent;
class Scene;
class Entity;
class QColor;

class Tool : public QObject
{
    Q_OBJECT

public:
    Tool();
    virtual ~Tool();

    /**
     * @brief handleEvent event handler per i tool, ogni volta che arriva un evento
     *        in base al tipo di quest'ultimo chiama il metodo corretto
     * @param event evento scatenato nel canvas che viene passato alla classe Tool
     * @return risultato se l'evento è stato accettato e quindi gestito o rifiutato
     */
    bool handleEvent(QEvent *event);

signals:
    void canvasModified();

protected:

    virtual void mousePress(QMouseEvent*) =0;
    virtual void mouseMove(QMouseEvent*) =0;
    virtual void mouseRelease(QMouseEvent*) =0;

    //ultima entità con cui ha interagito un tool
    static Entity *_lastEntity;
};

#endif // TOOL_H
