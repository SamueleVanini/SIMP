#include "view/header/mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), lineColor(Qt::black), lineWidth(2), isDirty(false)
{
    QMainWindow::setMinimumSize(600, 300);
    MainWindow::saveDialog();
    createAction();
    createMenu();
    createLeftToolbar();
    scene = new Scene();
    canvas = new Canvas(this, scene);
    auto style = new EnvStyle(this);
    _selectionTool = new SelectionTool(scene, style);
    _drawLineTool = new DrawLineTool(scene, style);
    canvas->setActiveTool(_selectionTool);
    setCentralWidget(canvas);
}

MainWindow::~MainWindow()
{

}


void MainWindow::saveDialog() {
    /*QWidget *welcomeDialog = new QWidget(this);
    welcomeDialog->setText("Before saving you need to enter canvas resolution. Default resolution is 600x300");
    unsigned int widthRatio = 2;
    unsigned int heightRatio = 1;
    unsigned int size = STD_CANVAS_HEIGHT;
    unsigned int xSize;
    unsigned int ySize;



    QAbstractButton *ok= exitDialog->addButton("Set Resolution and Save", QMessageBox::AcceptRole);
    QAbstractButton *cancel = exitDialog->addButton("Cancel", QMessageBox::RejectRole);
    exitDialog->exec();
    if (exitDialog->clickedButton()== ok)
        on_saveAction_triggered();*/
    return;
}


//ritorna vero se esce, falso altrimenti
bool MainWindow::exitPrompt()
{
    if (isDirty) {

        QMessageBox *exitDialog = new QMessageBox(this);
        exitDialog->setText("There are unsaved changes. Do you want to save before exit?");
        QAbstractButton *save = exitDialog->addButton("Exit and save", QMessageBox::AcceptRole);
        QAbstractButton *cancel = exitDialog->addButton("Cancel", QMessageBox::RejectRole);
        exitDialog->addButton("Exit whitout saving", QMessageBox::DestructiveRole);
        exitDialog->exec();
        if (exitDialog->clickedButton()== cancel)
            return false;
        if (exitDialog->clickedButton()== save)
        {
            on_saveAction_triggered();
            return true;
        }
    }
    return true;
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    if (exitPrompt() == false)
        event->ignore();

}

void MainWindow::createLeftToolbar()
{
    leftToolbar=new QToolBar();
    QMainWindow::addToolBar(Qt::LeftToolBarArea, leftToolbar);
    leftToolbar->setOrientation(Qt::Vertical);
    QActionGroup *group = new QActionGroup(leftToolbar);

    QAction* select = new QAction("select", group);
    select->setCheckable(true);
    select->setChecked(true);
    select->setIcon(QIcon(":/rec/Icons/CursorIcon.png"));
    connect(select, &QAction::triggered, this, &MainWindow::on_selectAction_triggered);

    QAction* drawLine = new QAction("Draw", group);
    drawLine->setCheckable(true);
    drawLine->setIcon(QIcon(":/rec/Icons/LineIcon.png"));
    connect(drawLine, &QAction::triggered, this, &MainWindow::on_drawLineAction_triggered);

    QAction* deleteLine = new QAction("Delete", group);
    deleteLine->setCheckable(true);
    deleteLine->setIcon(QIcon(":/rec/Icons/trash_can.png"));
    connect(deleteLine, &QAction::triggered, this, &MainWindow::on_deleteAction_triggered);


    leftToolbar->addActions(group->actions());
    leftToolbar->addSeparator();

    QLabel *label1 = new QLabel(QString("Line color"));
    leftToolbar->addWidget(label1);

    getLineColor = new colorButton();
    leftToolbar->addWidget(getLineColor);
    QAction* setColor= new QAction(lineColor.name());
    getLineColor->setAction(setColor);
    connect(setColor, &QAction::triggered, this, &MainWindow::on_pickColorAction_triggered);

    QLabel *label2 = new QLabel(QString("Line width"));
    leftToolbar->addWidget(label2);
    QSpinBox *lineWidthSpinBox = new QSpinBox;
    lineWidthSpinBox->setRange(1, 10);
    lineWidthSpinBox->setSingleStep(1);
    lineWidthSpinBox->setValue(lineWidth);
    leftToolbar->addWidget(lineWidthSpinBox);
    connect(lineWidthSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(lineThicknessChanged(int)));



}



void MainWindow::createMenu()
{
    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(newAction);
    menu->addAction(saveAction);
    menu->addAction(exitAction);
    menu = menuBar()->addMenu(tr("&Edit"));
    menu->addAction(deleteAction);
    menu = menuBar()->addMenu(tr("&Draw"));
    menu->addAction(drawLineAction);
}

void MainWindow::createAction()
{

    //new
    newAction = new QAction(tr("&New"), this);
    newAction->setShortcuts(QKeySequence::New);
    newAction->setStatusTip(tr("New"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(on_newAction_triggered()));

    //save
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(on_saveAction_triggered()));

    //exit
    exitAction = new QAction(tr("&Exit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setStatusTip(tr("Quit"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(on_exitAction_triggered()));

    //delete
    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setShortcuts(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("delete"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(on_deleteAction_triggered()));

    //select
    selectAction = new QAction(tr("&Select"), this);
    selectAction->setStatusTip(tr("Select"));
    connect(selectAction, SIGNAL(triggered()), this, SLOT(on_selectAction_triggered()));

    //drawLine
    drawLineAction = new QAction(tr("&Draw line"), this);
    drawLineAction->setStatusTip(tr("Draw line"));
    connect(drawLineAction, SIGNAL(triggered()), this, SLOT(on_drawLineAction_triggered()));

}

//azioni menu file
void MainWindow::on_newAction_triggered()
{
    std::cout<<"New Action"<<std::endl;
    return;
}

void MainWindow::on_saveAction_triggered()
{
    std::cout<<"Save Action"<<std::endl;
    return;
}
void MainWindow::on_exitAction_triggered()
{
    std::cout<<"Fin qui tutto bene"<<std::endl;
    close();
}

//azioni menu Draw
void MainWindow::on_selectAction_triggered()
{
    uncheckAllToolbar();
    selectAction->setEnabled(true);
    canvas->setActiveTool(_selectionTool);
    std::cout<<"Select Action"<<std::endl;
    return;
}

void MainWindow::on_deleteAction_triggered()
{
    uncheckAllToolbar();
    std::cout<<"Delete Action"<<std::endl;
    return;
}

void MainWindow::on_drawLineAction_triggered()
{
    uncheckAllToolbar();
    drawLineAction->setEnabled(true);
    canvas->setActiveTool(_drawLineTool);
    std::cout<<"Draw Line Action"<<std::endl;
    return;
}


//azioni di supporto

void MainWindow::on_pickColorAction_triggered()
{
    QColor colorPicked = QColorDialog::getColor(Qt::black, this, "Choose Color");
    if (colorPicked.isValid())
    {
        lineColor=colorPicked;
        getLineColor->setColor(lineColor);
        std::cout<<lineColor.name().toStdString()<<std::endl;
        emit lineColorChaneged(lineColor);
    }

}

void MainWindow::on_canvasChanged()
{
    return;
}

void MainWindow::uncheckAllToolbar()
{
    drawLineAction->setChecked(false);
    selectAction->setChecked(false);
    deleteAction->setChecked(false);
}
