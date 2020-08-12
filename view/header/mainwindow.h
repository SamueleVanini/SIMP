#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "view/header/canvas.h"
#include "view/header/colorbutton.h"
#include "model/header/selectiontool.h"
#include "model/header/drawlinetool.h"

#include <QtWidgets>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QIcon>
#include <QColorDialog>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    //slot menu file
    void on_newAction_triggered();
    void on_openAction_triggered();
    void on_saveAction_triggered();
    void on_exitAction_triggered();
    //slot menu Edit
    void on_deleteAction_triggered();
    //slot menu Draw
    void on_selectAction_triggered();
    void on_drawLineAction_triggered();

    //azioni di supporto
    void on_pickColorAction_triggered();

private:
    void createMenu(); //crea il menu` superiore
    void createAction();//collega ogni action al suo corrispondente slot
    void createLeftToolbar();//crea la toolbar sinistra
    void uncheckAllToolbar();

    bool exitPrompt();

    Canvas *canvas;
    QMenu *menu;
    QToolBar *leftToolbar;
    colorButton *getLineColor;
    QColor lineColor; //colore della linea
    unsigned int lineWidth; //spessore della linea

    bool isDirty; //dirty bit per segnalare la presenza di modifiche non salvate

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *exitAction;
    QAction *deleteAction;
    QAction *selectAction;
    QAction *drawLineAction;

    SelectionTool *_selectionTool;
    DrawLineTool *_drawLineTool;
};


#endif // MAINWINDOW_H
