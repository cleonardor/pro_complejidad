#include "branchandbound.h"
#include <math.h>
#include <QString>

BranchAndBound::BranchAndBound(lprec *lp, int n)
{
    this->lp = lp;
    this->n = n;

    this->solution = new Solution();
    this->solution->setN(n);
    this->solution->setAmountVariables(get_Ncolumns(this->lp));
}

BranchAndBound::~BranchAndBound()
{
    delete this->solution;
    this->solution = 0;

    //lp a cambiado al objeto que apunta en la ejecución, y ha sido eliminado. El objeto original pretenece a Solver, ella se encarga
}


void BranchAndBound::findSolution()
{
    double *result = new double[get_Ncolumns(this->lp)];
    double *row = new double[1];
    int *columnNumber = new int[1];
    int state;
    bool isIntSolution;

    this->stack.push(copy_lp(this->lp));

    while(!this->stack.empty())
    {
        this->lp = this->stack.pop();

        set_verbose(this->lp, IMPORTANT);//para que se vean mensages importantes mientras se resuelve
        state = solve(this->lp);

        if(state == INFEASIBLE)
        {
            delete_lp(this->lp);
            this->lp = 0;
            continue;
        }else if(floor(get_objective(this->lp)) <= this->solution->getZmax())
        {
            delete_lp(this->lp);
            this->lp = 0;
            continue;
        }else
        {
            get_variables(this->lp,result);

            for(int i=2*n;i<4*n+n;i++)
            {
                if(!this->isBin(result[i]))
                {                    
                    lprec *lp1 = copy_lp(this->lp);
                    lprec *lp2 = copy_lp(this->lp);

                    columnNumber[0] = i+1;
                    row[0] = 1;

                    add_constraintex(lp1,1,row,columnNumber,LE,floor(result[i]));
                    add_constraintex(lp2,1,row,columnNumber,GE,ceil(result[i]));

                    this->stack.push(lp2);
                    this->stack.push(lp1);

                    //write_lp(lp1,QString("model-").append(get_col_name(lp,i+1)).append("-1.lp").toAscii().data());
                    //write_lp(lp2,QString("model-").append(get_col_name(lp,i+1)).append("-2.lp").toAscii().data());

                    isIntSolution = false;
                    break;
                }
                isIntSolution = true;
            }

            if(isIntSolution)
            {
                if(get_objective(this->lp) > this->solution->getZmax())
                {
                    this->solution->setZmax(get_objective(this->lp));
                    this->solution->setResult(result);
                }
            }
        }
        delete_lp(this->lp);
        this->lp = 0;
    }
}

bool BranchAndBound::isBin(double a)
{
    if(a == 0.0 || a == 1.0)
    {
        return true;
    }else{
        return (1-a < 0.000001 || a < 0.000001);
    }
}

Solution* BranchAndBound::getSolution()
{
    return this->solution;
}
