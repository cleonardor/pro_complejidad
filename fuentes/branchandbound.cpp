#include "branchandbound.h"

#include <iostream>
using namespace std;

BranchAndBound::BranchAndBound(lprec *lp, int n)
{
    this->lp = lp;
    this->zMax = -1;
    this->xMax = -1;
    this->yMax = -1;
    this->n = n;
}

BranchAndBound::~BranchAndBound()
{

}


void BranchAndBound::findSolution()
{
    double *result = new double[get_Ncolumns(this->lp)];
    int Sxi=2*n, Syi=3*n, ci=4*n, Ax=5*n+2, Ay=5*n+3, state;

    this->stack.push(copy_lp(this->lp));

    while(!this->stack.empty())
    {
        this->lp = this->stack.pop();

        set_verbose(this->lp, IMPORTANT);//para que se vean mensages importantes mientras se resuelve
        state = solve(this->lp);
        //ver que el resultado sea satisfactible, de lo contrario terminar
        //si es satisfactible ver si las variables son binarias, si todas lo son se encontro una solucion factible
        //ver si esta es mejor que la minima, si no lo es dar por terminado
        get_variables(this->lp,result);

        for(int i=2*n;i<4*n+n;i++)
        {
            cout << "is bin " << get_col_name(this->lp, i+1) << " : " << this->isBin(result[i]) << endl;
        }
    }
}

bool BranchAndBound::isBin(double a)
{
    if(a == 0 || a == 1)
    {
        return true;
    }else{
        return false;
    }

}
