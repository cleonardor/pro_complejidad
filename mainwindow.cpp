#include "mainwindow.h"
#include "canvas.h"
#include "board.h"
#include "solver.h"
#include <QTextCodec>
#include <QHBoxLayout>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTextCodec *linuxCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(linuxCodec);

    canvas = new Canvas(this);
    canvas->setSceneRect(QRectF(0, 0, 600, 500));
    QGraphicsView *view = new QGraphicsView(canvas);

    board = new Board();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(view);
    layout->addWidget(board);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    setCentralWidget(widget);
    setWindowTitle(tr("Complejidad y Optimización"));

    connect(board,SIGNAL(loadFileDoneSignal()),this,SLOT(loadFileDoneSlot()));
    connect(board,SIGNAL(runSignal()),this,SLOT(runSlot()));
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::loadFileDoneSlot()
{
    this->canvas->drawState(this->board->getM(), this->board->getCitiesRef());
}

void MainWindow::runSlot()
{
    this->solver = new Solver(this->board->getM(),this->board->getCitiesRef());
    this->solver->run();
}
