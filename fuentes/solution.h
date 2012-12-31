#ifndef SOLUTION_H
#define SOLUTION_H

#include <QStringList>
#include <QVector>

class Solution
{
private:
    QVector<double> result;
    QStringList nameVariables;
    int nearbyCity;
    double zMax;
    int n;//cantidad de ciudades
    int amountVariables;

public:
    Solution();
    ~Solution();

    QVector<double> getResult();
    QStringList getNameVariables();
    int getNearbyCity();
    double getZmax();
    int getN();
    int getAmountVariables();

    void setResult(double *result);
    void setNameVariables(QStringList nameVariables);
    void setNearbyCity(int nearbyCity);
    void setZmax(double zMax);
    void setN(int n);
    void setAmountVariables(int amountVariables);

    void printResult();
};

#endif // SOLUTION_H
