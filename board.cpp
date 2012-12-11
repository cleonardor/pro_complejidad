#include "board.h"
#include "city.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <iostream>
using namespace std;

Board::Board(QWidget *parent)
    :QWidget(parent)
{
    loadFileButton = new QPushButton(QIcon(":/images/fileopen.png"),tr("Cargar Archivo"));
    seeFileButton = new QPushButton(QIcon(":/images/fileopen.png"),tr("Ver Archivo Solución"));
    runButton = new QPushButton(QIcon(":/images/run.png"),tr("Ejecutar"));

    connect(loadFileButton,SIGNAL(clicked()),this,SLOT(loadFileSlot()));

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

void Board::loadFileSlot()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,
         tr("Abrir"), "", tr("Archivo (*.txt)"));

    if(fileName == NULL)
        return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {   //qDebug("algo");
        return;
    }

    QTextStream in(&file);
    QString line;
    QStringList row;

    int N;
    int amoutCity;
    QVector<City> cities;

    N = in.readLine().toInt();
    amoutCity = in.readLine().toInt();

    while (!in.atEnd())
    {
        line = in.readLine();
        row = line.split(" ");

        int number = row.at(0).toInt();
        int coorX = row.at(1).toInt();
        int coorY = row.at(2).toInt();

        City city(number, coorX, coorY);
        cities.append(city);
    }
    file.close();

    for(int i=0;i<cities.size();i++)
    {
        City c = cities.at(i);
        cout << c.getStringCity().toStdString() << endl;
    }
}

