#include "view/header/mainwindow.h"
#include "controller/header/envstyle.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), lineColor(Qt::black), lineWidth(2), isDirty(false)
{
    QMainWindow::setMinimumSize(600, 300);
    createAction();
    createMenu();
    createLeftToolbar();
    canvas = new Canvas(this);
    auto style = new EnvStyle();
    _selectionTool = new SelectionTool(canvas, style);
    _drawLineTool = new DrawLineTool(canvas, style);
    canvas->setActiveTool(_selectionTool);
    setCentralWidget(canvas);
}

MainWindow::~MainWindow()
{

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
    if (!exitPrompt())
        event->ignore();
}

void MainWindow::createLeftToolbar()
{
    leftToolbar=new QToolBar();
    QMainWindow::addToolBar(Qt::LeftToolBarArea, leftToolbar);
    leftToolbar->setOrientation(Qt::Vertical);

    QAction* select = new QAction(QIcon(":/rec/Icons/CursorIcon.png"), "Select");
    leftToolbar->addAction(select);
    connect(select, &QAction::triggered, this, &MainWindow::on_selectAction_triggered);

    QAction* drawLine = new QAction(QIcon(":/rec/Icons/LineIcon.png"), "Draw");
    leftToolbar->addAction(drawLine);
    connect(drawLine, &QAction::triggered, this, &MainWindow::on_drawLineAction_triggered);

    QAction* deleteLine = new QAction(QIcon(":/rec/Icons/trash_can.png"), "Delete");
    leftToolbar->addAction(deleteLine);
    connect(deleteLine, &QAction::triggered, this, &MainWindow::on_deleteAction_triggered);

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
    close();
}

//azioni menu Draw
void MainWindow::on_selectAction_triggered()
{
    uncheckAllToolbar();
    selectAction->setChecked(true);
    canvas->setActiveTool(_selectionTool);
    std::cout<<"Select Action"<<std::endl;
    return;
}

void MainWindow::on_deleteAction_triggered()
{
    std::cout<<"Delete Action"<<std::endl;
    return;
}

void MainWindow::on_drawLineAction_triggered()
{
    uncheckAllToolbar();
    drawLineAction->setChecked(true);
    canvas->setActiveTool(_drawLineTool);
    if (isDirty == false)
        isDirty = true;
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
    }

}

void MainWindow::uncheckAllToolbar()
{
    drawLineAction->setChecked(false);
    selectAction->setChecked(false);
}
