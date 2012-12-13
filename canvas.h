#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
QT_BEGIN_NAMESPACE
class City;
QT_END_NAMESPACE

class Canvas : public QGraphicsScene
{
     Q_OBJECT
public:
    Canvas(QObject *parent);
    ~Canvas();

    void drawState(int n, QVector<City> *cities);
};

#endif // CANVAS_H
