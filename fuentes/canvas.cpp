#include "canvas.h"
#include "city.h"
#include "solution.h"
#include <QGraphicsLineItem>
#include <QPen>
#include <QPixmap>
#include <QGraphicsEllipseItem>
#include <QPen>

#include <iostream>
using namespace std;
Canvas::Canvas(QObject *parent)
    :QGraphicsScene(parent)
{
}

Canvas::~Canvas()
{}

/*
 m: tamaño del tablero
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
        item->setPos((c->getCoorX()-0.5)*dx,(m-c->getCoorY()-0.5)*dy);
        addItem(item);
    }
}

void Canvas::drawResult(Solution *solution, QVector<City *> *cities, int m)
{
    double dx = width()/m;
    double dy = height()/m;

    QVector<double> result = solution->getResult();
    double Ax = result.at(result.size()-2);
    double Ay = result.at(result.size()-1);

    /*dibujar basurero*/
    QPixmap pix(":/images/recycle.jpeg");
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pix.scaled(dx,dy));
    item->setPos((Ax-0.5)*dx,(m-Ay-0.5)*dy);
    addItem(item);

    int nearbyCity = solution->getNearbyCity();
    City *c = cities->at(nearbyCity);
    QGraphicsEllipseItem *item2 = new QGraphicsEllipseItem(0,0,dx,dy);
    item2->setPos(QPointF((c->getCoorX()-0.5)*dx,(m-c->getCoorY()-0.5)*dy));

    QPen pen;
    pen.setWidth(4);
    pen.setStyle(Qt::DashDotLine);
    pen.setColor(Qt::blue);
    item2->setPen(pen);

    addItem(item2);
}
