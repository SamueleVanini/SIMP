#ifndef SCENE_H
#define SCENE_H

#include "model/header/entity.h"
#include <vector>

/**
 * @brief La class Scene rappresenta il contenitore in cui inserire le varie Entity
 *        create nel canvas. E' una risorsa comune, ovvero viene condivisa tra il canvas e tutti
 *        i tools, per questo viene inserita nel singleton
 */
class Scene
{
public:

    /**
     * @brief addEntity metodo per inserire una nuova entità nella scena
     * @param entity entità che si vuole inserire
     */
    void addEntity(Entity *entity);

    /**
     * @brief drawAllEntity disegna tutte le entity presenti nella scena
     * @param painter puntatore al painter con il quale effettuare il disegno,
     *        questo NON viene eliminato alla fine del disegno, è compito del
     *        chiamante gestire la memoria sullo HEAP di questo
     */
    void drawAllEntity(QPainter *painter);

    /**
     * @brief getLastInsertedEntity serve per avere l'ultima entità inserita nella scena
     *        utile per la business logic nei controller (triggerare lo stato di selezionato in una entity, ecc.)
     * @return Puntatore ad Entity
     */
    Entity* getLastInsertedEntity();

    /**
     * @brief getEntityFromPosition ritorna una entità data una posizione espressa in coordinate assolute rispetto al canvas
     * @param x ascissa della posizione
     * @param y ordinata della posizione
     * @return ritorna un puntatore alla Enitity ricercata o nullptr se questa non esiste
     */
    Entity* getEntityFromPosition(int x, int y);

    /**
     * @brief deleteEntityFromPosition elimina una entità data una posizione espressa in coordinate assolute rispetto al canvas
     * @param x ascissa della posizione
     * @param y ordinata della posizione
     */
    void deleteEntityFromPosition(int x, int y);

    /**
     * @brief findSelectedEntity ritorna l'entità che ha il campo selected = true
     * @return ritorna un puntatore alla Enitity ricercata o nullptr se questa non esiste
     */
    Entity* findSelectedEntity();

private:
    Scene();
    ~Scene();

    /* contenitore vero e proprio in cui vengono salvate le Entity, la gestione della memoria ed i vari metodi di accesso
     *  vengono lasciate alla libreria std
     */
    std::vector<Entity*> _scene;

    // necessario in modo che la classe Singleton (il manager delle risorse condivise) possa creare e gestire la scena
    friend class Singleton;
};

#endif // SCENE_H
