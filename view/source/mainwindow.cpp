#include "view/header/mainwindow.h"

#define DEFAULT_CANVAS_WIDTH 600
#define DEFAULT_CANVAS_HEIGHT 300
#define DEFAULT_WINDOW_WIDTH 600
#define DEFAULT_WINDOW_HEIGHT 300

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),canvasWidth(DEFAULT_CANVAS_WIDTH), canvasHeight(DEFAULT_CANVAS_HEIGHT),
      lineColor(Qt::black), fillColor(Qt::white), lineWidth(2), isDirty(false), isCanvasDimensioned(false),
      saveFile(), scrollArea(new QScrollArea)
{
    Singleton::getInstance(this);
    QMainWindow::setMinimumSize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
    createAction();
    createLeftToolbar();
    createMenu();

    createCentralWidget();
    createTools();

    //segnale per salvare l'immagine creata
    connect(this, SIGNAL(saveImageSignal(QString, Canvas*)), &_saveImageTool, SLOT(saveImage(QString,Canvas*)));

}

MainWindow::~MainWindow()
{
    delete canvas;
}


void MainWindow::createMenu()
{
    menu = menuBar()->addMenu(tr("&File"));
    menu->addAction(newAction);
    menu->addAction(saveAction);
    menu->addAction(exitAction);
    menu = menuBar()->addMenu(tr("&Edit"));
    menu->addAction(deleteAllAction);
    menu->addAction(resizeAction);
    menu = menuBar()->addMenu(tr("&Draw"));
    menu->addAction(drawLineAction);
    menu->addAction(drawCircleAction);
    menu->addAction(drawRectangleAction);
}


void MainWindow::createAction()
{

    //new
    newAction = new QAction(tr("&New"), this);
    newAction->setShortcuts(QKeySequence::New);
    newAction->setToolTip(tr("New"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(on_newAction_triggered()));

    //save
    saveAction = new QAction(tr("&Save"), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setToolTip(tr("Save"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(on_saveAction_triggered()));

    //exit
    exitAction = new QAction(tr("&Exit"), this);
    exitAction->setShortcuts(QKeySequence::Quit);
    exitAction->setToolTip(tr("Quit"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(on_exitAction_triggered()));

    //delete
    deleteAction = new QAction(tr("&Delete"), this);
    deleteAction->setToolTip(tr("Press to delete"));
    connect(deleteAction, SIGNAL(triggered()), this, SLOT(on_deleteAction_triggered()));

    //deleteAll
    deleteAllAction = new QAction(tr("&Delete all"), this);
    deleteAllAction->setShortcut(Qt::CTRL + Qt::Key_Delete);
    deleteAllAction->setToolTip(tr("Press CTRL+DEL to delete all"));
    connect(deleteAllAction, SIGNAL(triggered()), this, SLOT(on_deleteAllAction_triggered()));

    //resizeAction
    resizeAction = new QAction(tr("&Resize Canvas"), this);
    resizeAction->setToolTip(tr("Resize Canvas"));

    //select
    selectAction = new QAction(tr("&Select"), this);
    selectAction->setToolTip(tr("Press to Select"));
    connect(selectAction, SIGNAL(triggered()), this, SLOT(on_selectAction_triggered()));

    //drawLine
    drawLineAction = new QAction(tr("&Draw line"), this);
    drawLineAction->setToolTip(tr("Press to draw a line"));
    connect(drawLineAction, SIGNAL(triggered()), this, SLOT(on_drawLineAction_triggered()));

    //drawCircle
    drawCircleAction = new QAction(tr("&Draw circle"), this);
    drawCircleAction->setToolTip(tr("Press to draw a circle"));
    connect(drawCircleAction, SIGNAL(triggered()), this, SLOT(on_drawCircleAction_triggered()));

    //drawRectangle
    drawRectangleAction = new QAction(tr("&Draw Rectangle"), this);
    drawRectangleAction->setToolTip(tr("Press to draw a rectangle"));
    connect(drawRectangleAction, SIGNAL(triggered()), this, SLOT(on_drawRectangleAction_triggered()));
}

void MainWindow::createLeftToolbar()
{
    leftToolbar=new QToolBar();
    QMainWindow::addToolBar(Qt::LeftToolBarArea, leftToolbar);
    leftToolbar->setAllowedAreas(Qt::LeftToolBarArea);

    QActionGroup *group = new QActionGroup(leftToolbar);

    group->addAction(selectAction);
    selectAction->setCheckable(true);
    selectAction->setChecked(true);
    selectAction->setIcon(QIcon(":/rec/Icons/CursorIcon.png"));
    connect(selectAction, &QAction::triggered, this, &MainWindow::on_selectAction_triggered);


    group->addAction(drawLineAction);
    drawLineAction->setCheckable(true);
    drawLineAction->setIcon(QIcon(":/rec/Icons/LineIcon.png"));
    connect(drawLineAction, &QAction::triggered, this, &MainWindow::on_drawLineAction_triggered);

    group->addAction(drawCircleAction);
    drawCircleAction->setCheckable(true);
    drawCircleAction->setIcon(QIcon(":/rec/Icons/CircleIcon.png"));
    connect(drawCircleAction, &QAction::triggered, this, &MainWindow::on_drawCircleAction_triggered);

    group->addAction(drawRectangleAction);
    drawRectangleAction->setCheckable(true);
    drawRectangleAction->setIcon(QIcon(":/rec/Icons/RectangleIcon.png"));
    connect(drawRectangleAction, &QAction::triggered, this, &MainWindow::on_drawRectangleAction_triggered);

    group->addAction(deleteAction);
    deleteAction->setCheckable(true);
    deleteAction->setIcon(QIcon(":/rec/Icons/Eraser.png"));
    connect(deleteAction, &QAction::triggered, this, &MainWindow::on_deleteAction_triggered);

    leftToolbar->addActions(group->actions());
    leftToolbar->addSeparator();

    QLabel *label1 = new QLabel(QString("Line color"));
    leftToolbar->addWidget(label1);

    getLineColor = new ColorButton();
    leftToolbar->addWidget(getLineColor);
    QAction* setColor= new QAction(lineColor.name());
    getLineColor->setAction(setColor);
    getLineColor->setColor(lineColor.name());
    connect(setColor, &QAction::triggered, this, &MainWindow::on_pickColorAction_triggered);

    QLabel *label2 = new QLabel(QString("Fill color"));
    leftToolbar->addWidget(label2);

    getFillColor = new ColorButton();
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

void MainWindow::createTools()
{
    _selectionTool = std::make_shared<SelectionTool>();
    _drawLineTool = std::make_shared<DrawLineTool>();
    _deleteTool = std::make_shared<DeleteTool>();
    _drawCircleTool = std::make_shared<DrawCircleTool>();
    _drawRectangleTool = std::make_shared<DrawRectangleTool>();
    canvas->setActiveTool(_selectionTool);
    //se disegno una figura aggiorno lo stato del canvas
    connect(_drawLineTool.get(), SIGNAL(canvasModified()), this, SLOT(on_canvasChanged()));
    connect(_drawRectangleTool.get(), SIGNAL(canvasModified()), this, SLOT(on_canvasChanged()));
    connect(_drawCircleTool.get(), SIGNAL(canvasModified()), this, SLOT(on_canvasChanged()));
    connect(_deleteTool.get(), SIGNAL(canvasModified()), this, SLOT(on_canvasChanged()));
}

void MainWindow::createCentralWidget()
{
    canvas = new Canvas(nullptr, _selectionTool, DEFAULT_CANVAS_WIDTH, DEFAULT_CANVAS_HEIGHT);
    scrollArea->setBackgroundRole(QPalette::Background);
    canvas->setFixedSize(QSize(DEFAULT_CANVAS_WIDTH,DEFAULT_CANVAS_HEIGHT));
    canvas->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    scrollArea->setWidget(canvas);
    scrollArea->setWidgetResizable(true);
    scrollArea->setVisible(true);
    setCentralWidget(scrollArea);
    connect(resizeAction, SIGNAL(triggered()), this, SLOT(on_resizeAction_triggered()));
    connect(this, SIGNAL(canvasDimensionChanged(unsigned int, unsigned int)), canvas, SLOT(changeCanvasDimension(unsigned int, unsigned int)));
    scrollArea->show();
}


void MainWindow::uncheckAllToolbar()
{
    selectAction->setChecked(false);
    drawLineAction->setChecked(false);
    drawCircleAction->setChecked(false);
    drawRectangleAction->setChecked(false);
    deleteAction->setChecked(false);
}


void MainWindow::canvasDimensionDialog()
{
    QDialog dialog(this);
    QFormLayout form(&dialog);

    form.addRow(new QLabel("Enter new dimensions:"));

    QSpinBox *width = new QSpinBox(&dialog);
    width->setRange(1, 100000);
    width->setSingleStep(1);
    width->setValue(canvasWidth);
    QString label1 = QString("Width");
    form.addRow(label1, width);

    QSpinBox *height = new QSpinBox(&dialog);
    height->setRange(1, 100000);
    height->setValue(canvasHeight);
    QString label2 = QString("Heigth");
    form.addRow(label2, height);

    QDialogButtonBox buttonBox(QDialogButtonBox::Save | QDialogButtonBox::Close,
                               Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    if (dialog.exec() == QDialog::Accepted)
    {
        canvasWidth=width->value();
        canvasHeight=height->value();
        return;

    }else
    {
        canvasWidth=DEFAULT_CANVAS_WIDTH;
        canvasHeight=DEFAULT_CANVAS_HEIGHT;
        return;
    }
}

bool MainWindow::exitPrompt()
{
    if (isDirty) {
        QMessageBox *exitDialog = new QMessageBox(this);
        exitDialog->setIcon(QMessageBox::Question);
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
    }else {
        QMessageBox *exitDialog = new QMessageBox(this);
        exitDialog->setIcon(QMessageBox::Question);
        exitDialog->setText("Do you really want to exit?");
        QAbstractButton *exit = exitDialog->addButton("Exit", QMessageBox::DestructiveRole);
        exitDialog->addButton("Cancel", QMessageBox::RejectRole);
        exitDialog->exec();
        return exitDialog->clickedButton()==exit;
    }
    return true;
}


//azioni menu file


void MainWindow::on_newAction_triggered()
{
    if (isDirty)
    {
        exitPrompt();
    }
    uncheckAllToolbar();
    selectAction->setEnabled(true);
    canvas->setActiveTool(_selectionTool);
    on_deleteAllAction_triggered();
    isDirty=false;
    emit canvasDimensionChanged(600, 300);
    lineColor=Qt::black;
    getLineColor->setColor(lineColor);
    emit lineColorChanged(lineColor);
    fillColor=Qt::white;
    getFillColor->setColor(fillColor);
    emit fillColorChanged(fillColor);
    isCanvasDimensioned=false;
    emit canvasDimensionChanged(600,300);
    emit lineThicknessChanged(2);
    saveFile= QString();
}

void MainWindow::on_saveAction_triggered()
{
    if (saveFile==nullptr)
    {
        saveFile = QFileDialog::getSaveFileName(this, tr("Save File"), "/home/student/Pictures/untitled.png", tr("Images (*.png)"));
        if (saveFile == nullptr) //se l'utente e` uscito dal dialogo senza fornire il path allora esci
        {
            return;
        }
    }
    emit saveImageSignal(saveFile, canvas);
    isDirty = false;
    return;
}

void MainWindow::on_exitAction_triggered()
{
    close();
}


void MainWindow::on_deleteAction_triggered()
{
    uncheckAllToolbar();
    deleteAction->setChecked(true);
    canvas->setActiveTool(_deleteTool);
    return;
}


void MainWindow::on_deleteAllAction_triggered()
{
    Singleton::getInstance(nullptr)->getActualSceneInstance().deleteAll();
    canvas->repaint();
    uncheckAllToolbar();
    selectAction->setEnabled(true);
    canvas->setActiveTool(_selectionTool);
    return;
}


void MainWindow::on_resizeAction_triggered()
{
    canvasDimensionDialog();
    emit canvasDimensionChanged(canvasWidth, canvasHeight);
    return;
}


void MainWindow::on_selectAction_triggered()
{
    uncheckAllToolbar();
    selectAction->setChecked(true);
    canvas->setActiveTool(_selectionTool);
    return;
}


void MainWindow::on_drawLineAction_triggered()
{
    uncheckAllToolbar();
    drawLineAction->setChecked(true);
    canvas->setActiveTool(_drawLineTool);
    return;
}


void MainWindow::on_drawCircleAction_triggered()
{
    uncheckAllToolbar();
    drawCircleAction->setChecked(true);
    canvas->setActiveTool(_drawCircleTool);
    return;
}

void MainWindow::on_drawRectangleAction_triggered()
{
    uncheckAllToolbar();
    drawRectangleAction->setChecked(true);
    canvas->setActiveTool(_drawRectangleTool);
    return;
}



void MainWindow::on_pickColorAction_triggered()
{
    QColor colorPicked = QColorDialog::getColor(Qt::black, this, "Choose Color");
    if (colorPicked.isValid())
    {
        lineColor=colorPicked;
        getLineColor->setColor(lineColor);
        emit lineColorChanged(lineColor);
    }

}


void MainWindow::on_pickFillColorAction_triggered()
{
    QColor colorPicked = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if (colorPicked.isValid())
    {
        fillColor=colorPicked;
        getFillColor->setColor(fillColor);
        emit fillColorChanged(fillColor);
    }

}


void MainWindow::on_canvasChanged()
{
    if (!isDirty)
        isDirty=true;
    return;
}



void MainWindow::closeEvent(QCloseEvent *event)
{
    if (exitPrompt() == false)
        event->ignore();
}

