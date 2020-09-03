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
    /**
     * @brief on_newAction_triggere salva le modifiche del progetto corrente e resetta il canvas per poter
     * cominciare un nuovo progetto
     */
    void on_newAction_triggered();
    /**
     * @brief on_saveAction_triggered gestisce il salvataggio facendo scegliere all'utente
     * il file di salvataggio o salvando automaticamente quando possibile
     */
    void on_saveAction_triggered();
    /**
     * @brief on_exitAction_triggered gestisce l' uscita dall'applicazione mediante close()
     */
    void on_exitAction_triggered();
    //slot menu Edit
    /**
     * @brief on_deleteAction_triggered attiva il tool per l'eliminazione
     */
    void on_deleteAction_triggered();
    /**
     * @brief on_deleteAllAction_triggered elimina ogni elemento dall canvas
     */
    void on_deleteAllAction_triggered();
    /**
     * @brief on_resizeAction_triggered viene chiamato quando viene ridimensionato il canvas.
     * Fa scegliere all'utente le nuove dimensioni del canvas e successivamente emette il
     * segnale canvasDimensionChanged
     */
    void on_resizeAction_triggered();
    //slot menu Draw
    /**
     * @brief on_selectAction_triggered attiva il tool per la selezione
     */
    void on_selectAction_triggered();
    /**
     * @brief on_drawLineAction_triggered attiva il tool per il disegno delle linee
     */
    void on_drawLineAction_triggered();
    /**
     * @brief on_drawCircleAction_triggered attiva il tool per il disegno dei cerchi
     */
    void on_drawCircleAction_triggered();
    /**
     * @brief on_drawRectangleAction_triggered attiva il tool per il disegno dei rettangoli
     */
    void on_drawRectangleAction_triggered();

    //slot di supporto
    /**
     * @brief on_pickColorAction_triggered permette la scelta del colore delle linee mediante
     *  QDialog
     */
    void on_pickColorAction_triggered();
    /**
     * @brief on_pickFillColorAction_triggered permette la scelta del colore di riempimento mediante QDialog
     */
    void on_pickFillColorAction_triggered();
    /**
     * @brief aggiorna lo stato del canvas in caso di modifiche
     */
    void on_canvasChanged();



protected:
    /**
    @brief gestisce la chiusura dell'applicazione*/
    void closeEvent(QCloseEvent *event) override;

private:
    /**
     * @brief createMenu crea il menu superiore
     */
    void createMenu();
    /**
     * @brief createAction collega ogni action al suo corrispondente slot
     */
    void createAction();
    /**
     * @brief createLeftToolbar crea la toolbar sinistra
     */
    void createLeftToolbar();
    /**
     * @brief createTools crea i vari tool
     */
    void createTools();
    /**
     * @brief createCentralWidget crea il widget centrale
     */
    void createCentralWidget();
    /**
     * @brief uncheckAllToolbar resetta la toolbar
     */
    void uncheckAllToolbar();
    /**
     * @brief canvasDimensionDialog permette all'utente di modificare le dimensioni del canvas
     */
    void canvasDimensionDialog();
    /**
     * @brief exitPrompt si occupa di gestire l'uscita sicura dall'applicazione. Se ci sono modifiche pendenti chiede
     * di salvarle prima di uscire, altrimenti evita l'uscita accidentale dall'applicazione
     * @return indicazione se l'utente ha deciso di uscire
     */
    bool exitPrompt();

    Canvas *canvas;
    unsigned int canvasWidth;
    unsigned int canvasHeight;

    QMenu *menu;
    QToolBar *leftToolbar;
    ColorButton *getLineColor;
    ColorButton *getFillColor;
    QColor lineColor;
    QColor fillColor;
    unsigned int lineWidth;

    bool isDirty;
    bool isCanvasDimensioned;
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

    std::shared_ptr<SelectionTool> _selectionTool;
    std::shared_ptr<DrawLineTool> _drawLineTool;
    std::shared_ptr<DeleteTool> _deleteTool;
    std::shared_ptr<DrawCircleTool> _drawCircleTool;
    std::shared_ptr<DrawRectangleTool> _drawRectangleTool;
    
};


#endif // MAINWINDOW_H
