#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "view/header/canvas.h"
#include "view/header/colorbutton.h"
#include "controller/header/selectiontool.h"
#include "controller/header/drawlinetool.h"
#include "controller/header/drawcircletool.h"
#include "controller/header/drawrectangletool.h"
#include "model/header/singleton.h"
#include "controller/header/deletetool.h"
#include "controller/header/saveimage.h"

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
    void lineColorChanged(QColor color);
    void fillColorChanged(QColor color);
    void lineThicknessChanged(int value);
    void canvasDimensionChanged(unsigned int width, unsigned int height);
    void saveImageSignal(const QString&, Canvas*);


private slots:
    //slot menu file
    void on_newAction_triggered();
    void on_saveAction_triggered();
    void on_exitAction_triggered();
    //slot menu Edit
    void on_deleteAction_triggered();
    void on_deleteAllAction_triggered();
    void on_resizeAction_triggered();
    //slot menu Draw
    void on_selectAction_triggered();
    void on_drawLineAction_triggered();
    void on_drawCircleAction_triggered();
    void on_drawRectangleAction_triggered();

    //azioni di supporto
    void on_pickColorAction_triggered();
    void on_pickFillColorAction_triggered();
    void on_canvasChanged();



protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void createMenu(); //crea il menu` superiore
    void createAction();//collega ogni action al suo corrispondente slot
    void createLeftToolbar();//crea la toolbar sinistra
    void createTools();//crea i vari tool
    void createCentralWidget(); //crea il widget centrale
    void uncheckAllToolbar();
    void canvasDimensionDialog();
    bool exitPrompt();

    Singleton *singleton;

    Canvas *canvas;
    unsigned int canvasWidth;
    unsigned int canvasHeight;

    QMenu *menu;
    QToolBar *leftToolbar;
    ColorButton *getLineColor;
    ColorButton *getFillColor;
    QColor lineColor; //colore della linea
    QColor fillColor;
    unsigned int lineWidth; //spessore della linea

    bool isDirty; //dirty bit per segnalare la presenza di modifiche non salvate
    bool isCanvasDimensioned;//fornisce l' informazione se il canvas e` gia` stato dimensionato definitivamente
    QString saveFile;
    SaveImage _saveImageTool;

    QScrollArea *scrollArea;

    QAction *newAction;
    QAction *saveAction;
    QAction *exitAction;
    QAction *deleteAction;
    QAction *deleteAllAction;
    QAction *resizeAction;
    QAction *selectAction;
    QAction *drawLineAction;
    QAction *drawCircleAction;
    QAction *drawRectangleAction;


    //ho appena realizzato che serve uno slot tipo on_lineDrawn_triggered per modificare il valore di isDirty

    std::shared_ptr<SelectionTool> _selectionTool;
    std::shared_ptr<DrawLineTool> _drawLineTool;
    std::shared_ptr<DeleteTool> _deleteTool;
    std::shared_ptr<DrawCircleTool> _drawCircleTool;
    std::shared_ptr<DrawRectangleTool> _drawRectangleTool;
    
};


#endif // MAINWINDOW_H
