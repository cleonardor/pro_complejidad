#ifndef SOLVER_H
#define SOLVER_H

#include "city.h"
#include "constraintsmanager.h"
#include "lp_lib.h"
#include <QVector>

class Solver
{
private:
    //int n;
    //QVector<City *> *cities;
    ConstraintsManager *constrainsManager;
    lprec *lp;
public:
    Solver(int m=0, QVector<City *> *cities=0);

    void run();

    /*void setN(int n);
    void setCities(QVector<City *> *cities);
    int getN();
    QVector<City *>* getCities();*/

};

#endif // SOLVER_H
