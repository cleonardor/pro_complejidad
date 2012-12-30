#ifndef CONSTRAINTSMANAGER_H
#define CONSTRAINTSMANAGER_H

#include "city.h"
#include "lp_lib.h"
#include <QVector>

class ConstraintsManager
{
private:
    double **constraints;
    QString *desigualdades;
    int *columnNumber;

    int amountConstraints;
    int amountVariables;
    int m;
    QVector<City *> *cities;

    void setColumnsNames(lprec *lp);
    void writeConstraints();
    void buildContraints();
    void setConstraints(lprec *lp);
    void setObjectiveFunction(lprec *lp);

public:
    ConstraintsManager(int m, QVector<City *> *cities);

    lprec* buildModel();
};

#endif // CONSTRAINTSMANAGER_H
