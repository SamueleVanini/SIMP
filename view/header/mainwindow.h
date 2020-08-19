#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define STD_CANVAS_LENGHT 600
#define STD_CANVAS_HEIGHT 300

#include "view/header/canvas.h"
#include "view/header/colorbutton.h"
#include "model/header/scene.h"
#include "model/header/selectiontool.h"
#include "model/header/drawlinetool.h"
#include "controller/header/envstyle.h"

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
#include <QActionGroup>
#include <QInputDialog>
#include <QScrollArea>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void lineColorChaneged(QColor color);
    void lineThicknessChanged(int value);


private slots:
    //slot menu file
    void on_newAction_triggered();
    void on_saveAction_triggered();
    void on_exitAction_triggered();
    //slot menu Edit
    void on_deleteAction_triggered();
    //slot menu Draw
    void on_selectAction_triggered();
    void on_drawLineAction_triggered();

    //azioni di supporto
    void on_pickColorAction_triggered();
    void on_canvasChanged();


protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void createMenu(); //crea il menu` superiore
    void createAction();//collega ogni action al suo corrispondente slot
    void createLeftToolbar();//crea la toolbar sinistra
    void uncheckAllToolbar();
    void canvasDimensionDialog();
    bool exitPrompt();

    Canvas *canvas;

    unsigned int canvasWidth;
    unsigned int canvasHeight;

    Scene *scene;
    QMenu *menu;
    QToolBar *leftToolbar;
    colorButton *getLineColor;
    colorButton *getFillColor;
    QColor lineColor; //colore della linea
    QColor fillColor;
    unsigned int lineWidth; //spessore della linea

    bool isDirty; //dirty bit per segnalare la presenza di modifiche non salvate
    bool isCanvasDimensioned;//fornisce l' informazione se il canvas e` gia` stato dimensionato definitivamente

    QAction *newAction;
    QAction *saveAction;
    QAction *exitAction;
    QAction *deleteAction;
    QAction *selectAction;
    QAction *drawLineAction;

    //ho appena realizzato che serve uno slot tipo on_lineDrawn_triggered per modificare il valore di isDirty

    SelectionTool *_selectionTool;
    DrawLineTool *_drawLineTool;
};


#endif // MAINWINDOW_H
