#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "view/header/canvas.h"
#include "view/header/colorbutton.h"
#include "model/header/scene.h"
#include "controller/header/selectiontool.h"
#include "controller/header/drawlinetool.h"
#include "controller/header/drawcircletool.h"
#include "model/header/singleton.h"
#include "controller/header/deletetool.h"
#include "controller/header/envstyle.h"

#include <memory>
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

signals:
    void lineColorChaneged(QColor color);
    void lineThicknessChanged(int value);

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
    void on_drawCircleAction_triggered();

    //azioni di supporto
    void on_pickColorAction_triggered();

private:
    void createMenu(); //crea il menu` superiore
    void createAction();//collega ogni action al suo corrispondente slot
    void createLeftToolbar();//crea la toolbar sinistra
    void uncheckAllToolbar();

    Singleton *singleton;
    Canvas *canvas;
    QMenu *menu;
    QToolBar *leftToolbar;
    colorButton *getLineColor;
    QColor lineColor; //colore della linea
    unsigned int lineWidth; //spessore della linea

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *exitAction;
    QAction *deleteAction;
    QAction *selectAction;
    QAction *drawLineAction;
    QAction *drawCircleAction;

    std::shared_ptr<SelectionTool> _selectionTool;
    std::shared_ptr<DrawLineTool> _drawLineTool;
    std::shared_ptr<DeleteTool> _deleteTool;
    std::shared_ptr<DrawCircleTool> _drawCircleTool;
};


#endif // MAINWINDOW_H
