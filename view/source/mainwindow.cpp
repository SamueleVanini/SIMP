#include "view/header/mainwindow.h"
#include "view/header/canvas.h"

#include <iostream>


#include <QMenu>
#include <QMenuBar>
#include <QtWidgets>
#include <QMessageBox>
#include <QIcon>
#include <QToolButton>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), lineColor(Qt::black)
{
    QMainWindow::setMinimumSize(600, 300);
    createAction();
    createMenu();
    createLeftToolbar();
}

MainWindow::~MainWindow()
{

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

    QAction* getLineColor = new QAction(QIcon(":/rec/Icons/colorPalette.png"), "Pick a ");
    leftToolbar->addAction(getLineColor);
    connect(getLineColor, &QAction::triggered, this, &MainWindow::on_pickColorAction_triggered);
}



void MainWindow::createMenu()
{
    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(newAction);
    menu->addAction(openAction);
    menu->addAction(saveAction);
    menu->addAction(exitAction);
    menu = menuBar()->addMenu(tr("&Edit"));
    menu->addAction(undoAction);
    menu->addAction(redoAction);
    menu->addAction(deleteAction);
    menu = menuBar()->addMenu(tr("&Arrange"));
    menu->addAction(bringToFrontAction);
    menu->addAction(sendToBackAction);
    menu->addAction(bringForwardAction);
    menu->addAction(sendBackwardAction);
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

    //open
    openAction = new QAction(tr("&Open"), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(on_openAction_triggered()));

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

    //undo
    undoAction = new QAction(tr("&Undo"), this);
    undoAction->setShortcuts(QKeySequence::Undo);
    undoAction->setStatusTip(tr("Undo"));
    connect(undoAction, SIGNAL(triggered()), this, SLOT(on_undoAction_triggered()));

    //redo
    redoAction = new QAction(tr("&Redo"), this);
    redoAction->setShortcuts(QKeySequence::Redo);
    redoAction->setStatusTip(tr("Redo"));
    connect(redoAction, SIGNAL(triggered()), this, SLOT(on_redoAction_triggered()));

    //delete
    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setShortcuts(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("delete"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(on_deleteAction_triggered()));

    //bringToFront
    bringToFrontAction = new QAction(tr("&Bring to front"), this);
    //bringToFrontAction->setShortcuts(QKeySequence::Delete); da inserire eventuale shortcut
    bringToFrontAction->setStatusTip(tr("Bring to front"));
    connect(bringToFrontAction, SIGNAL(triggered()), this, SLOT(on_bringToFrontAction_triggered()));

    //sendToBack
    sendToBackAction = new QAction(tr("&Send to back"), this);
    //sendToBackAction->setShortcuts(QKeySequence::Delete); da inserire eventuale shortcut
    sendToBackAction->setStatusTip(tr("Send to back"));
    connect(sendToBackAction, SIGNAL(triggered()), this, SLOT(on_sendToBackAction_triggered()));

    //bringForward
    bringForwardAction = new QAction(tr("&Bring forward"), this);
    //bringForwardAction->setShortcuts(QKeySequence::Delete); da inserire eventuale shortcut
    bringForwardAction->setStatusTip(tr("Bring forward"));
    connect(bringForwardAction, SIGNAL(triggered()), this, SLOT(on_bringForwardAction_triggered()));

    //sendBackward
    sendBackwardAction = new QAction(tr("&sendBackward"), this);
    //sendBackwardAction->setShortcuts(QKeySequence::Delete); da inserire eventuale shortcut
    sendBackwardAction->setStatusTip(tr("Send backward"));
    connect(sendBackwardAction, SIGNAL(triggered()), this, SLOT(on_sendBackwardAction_triggered()));

    //select
    selectAction = new QAction(tr("&Select"), this);
    //drawLineAction->setShortcuts(QKeySequence::Delete); da inserire eventuale shortcut
    selectAction->setStatusTip(tr("Select"));
    connect(selectAction, SIGNAL(triggered()), this, SLOT(on_selectAction_triggered()));

    //drawLine
    drawLineAction = new QAction(tr("&Draw line"), this);
    //drawLineAction->setShortcuts(QKeySequence::Delete); da inserire eventuale shortcut
    drawLineAction->setStatusTip(tr("Draw line"));
    connect(drawLineAction, SIGNAL(triggered()), this, SLOT(on_drawLineAction_triggered()));

}

//azioni menu file
void MainWindow::on_newAction_triggered()
{
    std::cout<<"New Action"<<std::endl;
    return;
}
void MainWindow::on_openAction_triggered()
{
    std::cout<<"Open Action"<<std::endl;
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

//azioni menu Edit
void MainWindow::on_undoAction_triggered()
{
    std::cout<<"Undo Action"<<std::endl;
    return;
}
void MainWindow::on_redoAction_triggered()
{
    std::cout<<"Redo Action"<<std::endl;
    return;
}
void MainWindow::on_deleteAction_triggered()
{
    std::cout<<"Delete Action"<<std::endl;
    return;
}
//azioni menu arrange
void MainWindow::on_bringToFrontAction_triggered()
{
    std::cout<<"Bring to front Action"<<std::endl;
    return;
}
void MainWindow::on_sendToBackAction_triggered()
{
    std::cout<<"Send to Back Action"<<std::endl;
    return;
}
void MainWindow::on_bringForwardAction_triggered()
{
    std::cout<<"Bring Forward Action"<<std::endl;
    return;
}
void MainWindow::on_sendBackwardAction_triggered()
{
    std::cout<<"Send Backward Action"<<std::endl;
    return;
}
//azioni menu Draw
void MainWindow::on_selectAction_triggered()
{
    std::cout<<"Select Action"<<std::endl;
    return;
}

void MainWindow::on_drawLineAction_triggered()
{
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
        std::cout<<lineColor.name().toStdString()<<std::endl;
    }

}
