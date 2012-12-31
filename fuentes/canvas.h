#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
class City;
class Solution;
QT_END_NAMESPACE

class Canvas : public QGraphicsScene
{
     Q_OBJECT
public:
    Canvas(QObject *parent);
    ~Canvas();

    void drawState(int m, QVector<City *> *cities);
    void drawResult(Solution *solution, QVector<City *> *cities, int m);
};

#endif // CANVAS_H
