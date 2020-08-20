#include "view/header/mainwindow.h"


#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), lineColor(Qt::black), lineWidth(2), isDirty(false), isCanvasDimensioned(false)
{



    //QMainWindow::setMinimumSize(800, 600);
    createAction();
    createMenu();
    createLeftToolbar();
    singleton = Singleton::getInstance(this);
    _selectionTool = std::make_shared<SelectionTool>();
    _drawLineTool = std::make_shared<DrawLineTool>();
    _deleteTool = std::make_shared<DeleteTool>();
    _drawCircleTool = std::make_shared<DrawCircleTool>();
    canvas = new Canvas(nullptr, _selectionTool, 600, 300);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(canvas);

    QWidget *contenitore = new QWidget(this);
    contenitore->setLayout(layout);

    QScrollArea *scrollArea = new QScrollArea(contenitore);
    scrollArea->setLayout(layout);
    scrollArea->setWidget(canvas);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //canvas->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    setCentralWidget(contenitore);
    //contenitore->show();



    /*QWidget *myCanvas = new QWidget(this);



    QHBoxLayout *myLayout = new QHBoxLayout(myCanvas);
    myLayout->addWidget(canvas);


    /*QScrollArea *scrollArea = new QScrollArea(myCanvas);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    /*scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setLayout(myLayout);
    scrollArea->setWidget(canvas);
    scrollArea->show();

    setCentralWidget(myCanvas);
    //myCanvas->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);*/

}

MainWindow::~MainWindow()
{
    delete canvas;
}


void MainWindow::canvasDimensionDialog()
{
    QDialog dialog(this);
    QFormLayout form(&dialog);

    form.addRow(new QLabel("You need to dimension your canvas before saving. \n"
                           "Please enter width and heigth or set default dimensions."));

    int dimensions[2];

    QSpinBox *width = new QSpinBox(&dialog);
    width->setRange(1, 100000);
    width->setSingleStep(1);
    width->setValue(600);
    QString label1 = QString("Width");
    form.addRow(label1, width);

    QSpinBox *height = new QSpinBox(&dialog);
    height->setRange(1, 100000);
    height->setValue(300);
    QString label2 = QString("Heigth");
    form.addRow(label2, height);

    dimensions[0] = width->value();
    dimensions[1] = height->value();

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Save | QDialogButtonBox::Close,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted)
    {
        canvasWidth=dimensions[0];
        canvasHeight=dimensions[1];
        return;

    }else
    {
        canvasWidth=600;
        canvasHeight=300;
        return;
    }
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

    QAction* drawLine = new QAction("Line", group);
    drawLine->setCheckable(true);
    drawLine->setIcon(QIcon(":/rec/Icons/LineIcon.png"));
    connect(drawLine, &QAction::triggered, this, &MainWindow::on_drawLineAction_triggered);
    QAction* drawCircle= new QAction("Circle", group);
    drawCircle->setCheckable(true);
    drawCircle->setIcon(QIcon(":/rec/Icons/CircleIcon.png"));
    connect(drawCircle, &QAction::triggered, this, &MainWindow::on_drawCircleAction_triggered);

    QAction* drawRectangle = new QAction("Rectangle", group);
    drawRectangle->setCheckable(true);
    drawRectangle->setIcon(QIcon(":/rec/Icons/RectangleIcon.png"));
    connect(drawRectangle, &QAction::triggered, this, &MainWindow::on_drawLineAction_triggered);


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
    getLineColor->setColor(lineColor.name());
    connect(setColor, &QAction::triggered, this, &MainWindow::on_pickColorAction_triggered);

    QLabel *label2 = new QLabel(QString("Fill color"));
    leftToolbar->addWidget(label2);

    getFillColor = new colorButton();
    leftToolbar->addWidget(getFillColor);
    QAction* setFillColor= new QAction(fillColor.name());
    getFillColor->setAction(setFillColor);
    getFillColor->setColor(fillColor.name());
    connect(setFillColor, &QAction::triggered, this, &MainWindow::on_pickFillColorAction_triggered);

    QLabel *label3 = new QLabel(QString("Line width"));
    leftToolbar->addWidget(label3);

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

    //drawCircle
    drawCircleAction = new QAction(tr("&Draw circle"), this);
    drawCircleAction->setStatusTip(tr("Draw circle"));
    connect(drawCircleAction, SIGNAL(triggered()), this, SLOT(on_drawCircleAction_triggered()));
}

//azioni menu file
void MainWindow::on_newAction_triggered()
{
    std::cout<<"New Action"<<std::endl;
    return;
}

void MainWindow::on_saveAction_triggered()
{
    if (!isCanvasDimensioned)
    {
        canvasDimensionDialog();
        isCanvasDimensioned = true;
    }

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
    selectAction->setEnabled(true);
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
    drawLineAction->setEnabled(true);
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

void MainWindow::on_pickFillColorAction_triggered()
{
    QColor colorPicked = QColorDialog::getColor(Qt::black, this, "Choose Color");
    if (colorPicked.isValid())
    {
        fillColor=colorPicked;
        getFillColor->setColor(fillColor);
        std::cout<<fillColor.name().toStdString()<<std::endl;
        emit lineColorChaneged(fillColor);
    }

}

void MainWindow::on_canvasChanged()
{
    //se ci sono modifiche pendenti e isDirty non le segna -
    if (!isDirty)
        isDirty=true;
    return;
}

void MainWindow::uncheckAllToolbar()
{
    drawLineAction->setChecked(false);
    selectAction->setChecked(false);
    deleteAction->setChecked(false);
}
