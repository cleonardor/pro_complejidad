#ifndef SOLVER_H
#define SOLVER_H

#include "city.h"
#include "constraintsmanager.h"
#include "branchandbound.h"
#include "solution.h"
#include "lp_lib.h"
#include <QVector>

class Solver
{
private:
    int n;// cantidad de ciudades
    ConstraintsManager *constrainsManager;
    BranchAndBound *bb;
    lprec *lp;
    Solution *solution;

public:
    Solver(int m=0, QVector<City *> *cities=0);
    ~Solver();

    void findSolution();
    Solution* getSolution();
};

#endif // SOLVER_H
