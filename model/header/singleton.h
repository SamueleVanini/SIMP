#ifndef SINGLETON_H
#define SINGLETON_H

#include "model/header/scene.h"
#include "controller/header/envstyle.h"
#include <exception>
#include <string>

/**
 * @brief La classe Singleton svolge il compito di manager per le risorse uniche e condivise del programma
 *        per ulteriori dettagli vedi https://en.wikipedia.org/wiki/Singleton_pattern o https://refactoring.guru/design-patterns/singleton
 */
class Singleton
{
public:

    /**
     * @brief getInstance funzione statica per avere l'istanza del maneger (è unica e condivisa per tutti
     *        i controller del programma)
     * @param ui puntatore alla MainWindow, necessaria solo la prima volta in cui si chiama getInstance()
     *        per inizializzare EnvStyle (collegare signal e slot)
     * @return ritorna l'unica istanza del Singleton
     */
    static Singleton* getInstance(MainWindow *ui = nullptr);

    /**
     * @brief getActualSceneInstance ritorna l'istanza condivisa della scena
     * @return Reference a Scene
     */
    Scene& getActualSceneInstance();

    /**
     * @brief getActualStyleInstance ritorna l'istanza condivisa dello stile attuale
     * @return Reference a EnvStyle
     */
    EnvStyle& getActualStyleInstance();

    /**
     * @brief Singleton, eliminazione esplicita del costruttore di copia. Il Singleton è unico e non deve poter essere
     *        copiato (sintassi introdotta da c++11)
     */
    Singleton(const Singleton&) = delete;

    /**
     * @brief operator =, eliminazione esplicita dell'assegnazione. Il Singleton è unico e non deve poter essere
     *        copiato (sintassi introdotta da c++11)
     * @return non ritorna nulla
     */
    Singleton& operator=(const Singleton&) = delete;

private:

    /**
     * @brief Singleton costruttore privato, il Singleton non deve poter essere costruito da tutti in multiple copie,
     *        le logiche di costruzione sono interne a getInstance
     * @param ui puntatore alla MainWindow, necessaria per inizializzare EnvStyle (collegare signal e slot)
     */
    Singleton(MainWindow *ui);

    static Singleton *_singleton;
    Scene _scene;
    EnvStyle _style;
};

class SingletonException : public std::exception
{
public:

    SingletonException(std::string message) : _message(message) {}
    SingletonException(const SingletonException& s) : _message(s.what()) {}
    ~SingletonException(){}

    const char* what() const throw()
    {
        return _message.c_str();
    }
private:
    std::string _message;
};

#endif // SINGLETON_H
