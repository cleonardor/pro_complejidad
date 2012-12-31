#include "board.h"
#include "city.h"
#include "solution.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QTextEdit>
#include <QString>
#include <QDebug>

Board::Board(QWidget *parent)
    :QWidget(parent)
{
    loadFileButton = new QPushButton(QIcon(":/images/fileopen.png"),tr("Cargar Archivo"));
    //seeFileButton = new QPushButton(QIcon(":/images/fileopen.png"),tr("Ver Archivo Solución"));
    runButton = new QPushButton(QIcon(":/images/run.png"),tr("Ejecutar"));
    textEdit = new QTextEdit(tr("Resultado de la ejecución"));

    connect(loadFileButton,SIGNAL(clicked()),this,SLOT(loadFileSlot()));
    connect(runButton,SIGNAL(clicked()),this,SLOT(runSlot()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(loadFileButton);
    //layout->addWidget(seeFileButton);
    layout->addWidget(runButton);
    layout->addStretch(10);
    layout->addWidget(textEdit);
    layout->addStretch(100);

    this->setLayout(layout);
    this->setMaximumWidth(250);
    //this->setMinimumWidth(250);
}

Board::~Board()
{
    delete this->loadFileButton;
    //delete this->seeFileButton;
    delete this->runButton;
    delete this->textEdit;

    this->loadFileButton = 0;
    //this->seeFileButton = 0;
    this->runButton = 0;
    this->textEdit = 0;

    this->clearCities();
}

void Board::loadFileSlot()
{
    clearCities();
    this->textEdit->setText(tr("Resultado de la ejecución"));

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

    m = in.readLine().toInt();
    amountCities = in.readLine().toInt();

    while (!in.atEnd())
    {
        line = in.readLine();
        row = line.split(" ");

        int number = row.at(0).toInt();
        int coorX = row.at(1).toInt();
        int coorY = row.at(2).toInt();

        City *city = new City(number, coorX, coorY);
        cities.append(city);
    }
    file.close();

    //imprimir ciudades
    /*for(int i=0;i<cities.size();i++)
    {
        cout << cities.at(i)->toString().toStdString() << endl;
    }*/

    emit loadFileDoneSignal();
}

int Board::getM()
{
    return this->m;
}

int Board::getAmountCities()
{
    return this->amountCities;
}

QVector<City *> *Board::getCitiesRef()
{
    return &cities;
}

void Board::runSlot()
{
    emit runSignal();
}

void Board::clearCities()
{
    for(int i=0;i<this->cities.size();i++)
    {
        City *c = this->cities.at(i);
        delete c;
        c = 0;
    }
    cities.clear();
}

void Board::setResult(Solution *solution)
{
    QString message;
    QStringList nameVariables = solution->getNameVariables();
    QVector<double> valueVariable = solution->getResult();

    message += "Valor Objetivo: " + QString::number(solution->getZmax()) + "\n\n";
    message += "**Valor de las variables**\n\n";
    for(int i=0;i<solution->getAmountVariables();i++)
    {
        message += nameVariables.at(i) + ": " + QString::number(valueVariable.at(i)) + "\n";
    }
    this->textEdit->setText(message);
}
