#ifndef COLORBUTTON_H
#define COLORBUTTON_H


#include <QAction>
#include <QPushButton>

class ColorButton : public QPushButton
{
    Q_OBJECT
private:
    QAction *_action = nullptr;

public:

    explicit ColorButton(QWidget *parent = nullptr);
    /**
     * @brief setAction associa l'azione $aaction al pulsante
     * @param action azione da associare
     */
    void setAction(QAction *action);
    /**
     * @brief setColor cambia il testo ed il colore di sfondo del pulsante con $color
     * @param color nuovo colore di sfondo
     */
    void setColor(QColor color);

public slots:
    /**
     * @brief updateButtonStatusFromAction aggiorna lo stato del bottone in base
     * allo stato dell'azione
     */
    void updateButtonStatusFromAction();
};

#endif // COLORBUTTON_H
