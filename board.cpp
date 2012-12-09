#include "board.h"
#include <QPushButton>
#include <QVBoxLayout>

Board::Board(QWidget *parent)
    :QWidget(parent)
{
    loadFileButton = new QPushButton(QIcon(":/images/fileopen.png"),tr("Cargar Archivo"));
    seeFileButton = new QPushButton(QIcon(":/images/fileopen.png"),tr("Ver Archivo Solución"));
    runButton = new QPushButton(QIcon(":/images/run.png"),tr("Ejecutar"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(loadFileButton);
    layout->addWidget(seeFileButton);
    layout->addWidget(runButton);
    layout->addStretch(250);

    this->setLayout(layout);
    //this->setMaximumWidth(250);
    //this->setMinimumWidth(250);
}

Board::~Board()
{}
