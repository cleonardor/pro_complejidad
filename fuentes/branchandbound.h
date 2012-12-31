#ifndef BRANCHANDBOUND_H
#define BRANCHANDBOUND_H

#include "lp_lib.h"
#include "solution.h"
#include <QStack>

class BranchAndBound
{
private:
    lprec *lp;
    QStack<lprec*> stack;
    int n;//cantidad de ciudades
    Solution *solution;

    bool isBin(double a);

public:
    BranchAndBound(lprec *lp, int n);
    ~BranchAndBound();

    void findSolution();
    Solution* getSolution();
};

#endif // BRANCHANDBOUND_H
