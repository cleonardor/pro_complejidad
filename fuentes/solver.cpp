#include "solver.h"
#include <iostream>
using namespace std;

Solver::Solver(int m, QVector<City *> *cities)
{
    this->n = cities->size();
    //this->cities = cities;//creo que estos dos atributos no son necesarios
    this->constrainsManager = new ConstraintsManager(m,cities);
    lp = 0;
    bb = 0;
}

Solver::~Solver()
{
    delete this->constrainsManager;
    delete this->lp;

    this->constrainsManager = 0;
    this->lp = 0;
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

    /*int n = get_Ncolumns(this->lp);
    double *result = new double[n];

    set_verbose(this->lp, IMPORTANT);//para que se vean mensages importantes mientras se resuelve
    int state = solve(lp);
    get_variables(this->lp,result);

    cout << "estado: " << state << endl;
    cout << "valor objetivo: " << get_objective(this->lp) << endl;
    for(int i=0;i<n;i++)
    {
        cout << get_col_name(this->lp, i+1) << ": " << result[i] << endl;
    }
*/

}


/*void Solver::setN(int n)
{
    this->n = n;
}

void Solver::setCities(QVector<City *> *cities)
{
    this->cities = cities;
}

int Solver::getN()
{
    return this->n;
}

QVector<City *>* Solver::getCities()
{
    return this->cities;
}
*/
