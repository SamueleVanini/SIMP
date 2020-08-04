#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "view/header/canvas.h"
#include <QMenu>
#include <QMenuBar>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //slot menu file
    void on_newAction_triggered();
    void on_openAction_triggered();
    void on_saveAction_triggered();
    void on_exitAction_triggered();
    //slot menu Edit
    void on_undoAction_triggered();
    void on_redoAction_triggered();
    void on_deleteAction_triggered();
    //slot menu arrange
    void on_bringToFrontAction_triggered();
    void on_sendToBackAction_triggered();
    void on_bringForwardAction_triggered();
    void on_sendBackwardAction_triggered();
    //slot menu Draw
    void on_drawLineAction_triggered();

    //azioni di supporto

private:
    void createMenu(); //crea il menu` superiore
    void createAction();
    QMenu *menu;

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *exitAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *deleteAction;
    QAction *bringToFrontAction;
    QAction *sendToBackAction;
    QAction *bringForwardAction;
    QAction *sendBackwardAction;
    QAction *drawLineAction;
};


#endif // MAINWINDOW_H
