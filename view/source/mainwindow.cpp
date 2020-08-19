#include "view/header/mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), lineColor(Qt::black), lineWidth(2)
{
    QMainWindow::setMinimumSize(800, 600);
    createAction();
    createMenu();
    createLeftToolbar();
    singleton = Singleton::getInstance(this);
    _selectionTool = std::make_shared<SelectionTool>();
    _drawLineTool = std::make_shared<DrawLineTool>();
    _deleteTool = std::make_shared<DeleteTool>();
    _drawCircleTool = std::make_shared<DrawCircleTool>();
    _drawRectangleTool = std::make_shared<DrawRectangleTool>();
    canvas = new Canvas(this, _selectionTool, 800, 600);
    setCentralWidget(canvas);
}

MainWindow::~MainWindow()
{
    delete canvas;
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

    QAction* drawCircle = new QAction(QIcon(":/rec/Icons/CircleIcon.png"), "Draw");
    leftToolbar->addAction(drawCircle);
    connect(drawCircle, &QAction::triggered, this, &MainWindow::on_drawCircleAction_triggered);

    QAction* drawRectangle = new QAction(QIcon(":/rec/Icons/RectangleIcon.png"), "Draw");
    leftToolbar->addAction(drawRectangle);
    connect(drawRectangle, &QAction::triggered, this, &MainWindow::on_drawRectangleAction_triggered);

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
    connect(lineWidthSpinBox, SIGNAL(valueChanged(int)), this, SIGNAL(lineThicknessChanged(int)));
}



void MainWindow::createMenu()
{
    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(newAction);
    menu->addAction(openAction);
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

    //drawCircle
    drawCircleAction = new QAction(tr("&Draw circle"), this);
    drawCircleAction->setStatusTip(tr("Draw circle"));
    connect(drawCircleAction, SIGNAL(triggered()), this, SLOT(on_drawCircleAction_triggered()));

    //drawRectangle
    drawRectangleAction = new QAction(tr("&Draw Rectangle"), this);
    drawRectangleAction->setStatusTip(tr("Draw Rectangle"));
    connect(drawRectangleAction, SIGNAL(triggered()), this, SLOT(on_drawRectangleAction_triggered()));
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
    uncheckAllToolbar();
    deleteAction->setChecked(true);
    canvas->setActiveTool(_deleteTool);
    std::cout<<"Delete Action"<<std::endl;
    return;
}

void MainWindow::on_drawLineAction_triggered()
{
    uncheckAllToolbar();
    drawLineAction->setChecked(true);
    canvas->setActiveTool(_drawLineTool);
    std::cout<<"Draw Line Action"<<std::endl;
    return;
}

void MainWindow::on_drawCircleAction_triggered()
{
    uncheckAllToolbar();
    drawCircleAction->setChecked(true);
    canvas->setActiveTool(_drawCircleTool);
    std::cout<<"Draw Circle Action"<<std::endl;
    return;
}

void MainWindow::on_drawRectangleAction_triggered()
{
    uncheckAllToolbar();
    drawRectangleAction->setChecked(true);
    canvas->setActiveTool(_drawRectangleTool);
    std::cout<<"Draw Rectangle Action"<<std::endl;
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

void MainWindow::uncheckAllToolbar()
{
    drawLineAction->setChecked(false);
    selectAction->setChecked(false);
    deleteAction->setChecked(false);
}
