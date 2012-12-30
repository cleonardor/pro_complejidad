#include "canvas.h"
#include "city.h"
#include <QGraphicsLineItem>
#include <QPen>
#include <QPixmap>
#include <QGraphicsItem>

Canvas::Canvas(QObject *parent)
    :QGraphicsScene(parent)
{
}

Canvas::~Canvas()
{}

/*
 n: tamaño del tablero
*/
void Canvas::drawState(int m, QVector<City *> *cities)
{
    double dx = width()/m;
    double dy = height()/m;

    this->clear();

    /*dibujar lienas verticales*/
    for(int i=0;i<=m;i++)
    {
        QGraphicsLineItem *line = new QGraphicsLineItem(i*dx,0.0,i*dx,height());
        QPen pen(QColor(Qt::red));
        line->setPen(pen);
        addItem(line);
    }

    /*dibujar lineas horizontales*/
    for(int j=0;j<=m;j++)
    {
        QGraphicsLineItem *line = new QGraphicsLineItem(0.0,j*dy,width(),j*dy);
        QPen pen(QColor(Qt::red));
        line->setPen(pen);
        addItem(line);
    }

    /*dibujar ciudades*/
    for(int i=0;i<cities->size();i++)
    {
        QPixmap pix(":/images/city3.png");
        QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pix.scaled(dx,dy));
        City *c = cities->at(i);
        item->setPos(c->getCoorX()*dx,(m-c->getCoorY()-1)*dy);
        addItem(item);
    }
}
