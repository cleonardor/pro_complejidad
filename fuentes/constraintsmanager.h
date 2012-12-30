#ifndef CONSTRAINTSMANAGER_H
#define CONSTRAINTSMANAGER_H

#include "city.h"
#include "lp_lib.h"
#include <QVector>
#include <string>

class ConstraintsManager
{
private:
    double **constraints;
    std::string *inequalities;
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
    ~ConstraintsManager();

    lprec* buildModel();
};

#endif // CONSTRAINTSMANAGER_H
