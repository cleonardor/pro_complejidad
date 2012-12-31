#include "solver.h"
#include <QStringList>

Solver::Solver(int m, QVector<City *> *cities)
{
    this->n = cities->size();
    this->constrainsManager = new ConstraintsManager(m,cities);
    this->lp = 0;
    this->bb = 0;
    this->solution = 0;
}

Solver::~Solver()
{
    delete this->constrainsManager;
    delete this->lp;
    delete this->bb;
    //delete this->solution;//este puntero apunta a un objeto en BranchAndBoud, ella es la encargada de eliminarlo

    this->constrainsManager = 0;
    this->lp = 0;
    this->bb = 0;
    this->solution = 0;
}

void Solver::findSolution()
{
    if(this->lp == 0)
    {
        this->lp = this->constrainsManager->buildModel();
    }else
    {
        delete this->lp;
        this->lp = this->constrainsManager->buildModel();
    }

    this->bb = new BranchAndBound(this->lp,this->n);
    this->bb->findSolution();
    this->solution = this->bb->getSolution();
    QStringList nameVariables;
    for(int i=0;i<this->solution->getAmountVariables();i++)
    {
        nameVariables.append(QString(get_col_name(this->lp,i+1)));
    }
    this->solution->setNameVariables(nameVariables);
    //this->solution->printResult();
}

Solution* Solver::getSolution()
{
    return this->solution;
}
