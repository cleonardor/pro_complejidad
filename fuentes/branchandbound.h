#ifndef BRANCHANDBOUND_H
#define BRANCHANDBOUND_H

#include "lp_lib.h"
#include <QStack>

class BranchAndBound
{
private:
    double zMax, xMax, yMax;
    lprec *lp;
    QStack<lprec*> stack;
    int n;

    bool isBin(double a);

public:
    BranchAndBound(lprec *lp, int n);
    ~BranchAndBound();

    void findSolution();
};

#endif // BRANCHANDBOUND_H
