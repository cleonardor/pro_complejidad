#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "solver.h"

QT_BEGIN_NAMESPACE
class Canvas;
class Board;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Canvas *canvas;
    Board *board;
    Solver *solver;

private slots:
    void loadFileDoneSlot();
    void runSlot();
};

#endif // MAINWINDOW_H
