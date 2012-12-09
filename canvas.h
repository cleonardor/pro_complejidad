#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>

class Canvas : public QGraphicsScene
{
     Q_OBJECT
public:
    Canvas(QObject *parent);
    ~Canvas();
};

#endif // CANVAS_H
