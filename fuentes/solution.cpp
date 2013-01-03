#include "solution.h"
#include <QDebug>
#include <iostream>
#include <math.h>

Solution::Solution()
{
    this->zMax = -1;
    this->amountVariables = 0;
    this->n = 0;
    this->nearbyCity = -1;
}

Solution::~Solution()
{
}

QVector<double> Solution::getResult()
{
    return this->result;
}

QStringList Solution::getNameVariables()
{
    return this->nameVariables;
}

int Solution::getNearbyCity()
{
     double test = 0;
    if(this->nearbyCity == -1)
    {
        for(int i=4*n,j=0;i<4*n+n;i++,j++)
        {
            test = this->result.at(i);

            if(abs(test-1) < 0.00001)//Comparacion entre doubles teniendo en cuenta un margen de error xD
            {

                this->nearbyCity = j;
            }
        }
    }
    return this->nearbyCity;
}

double Solution::getZmax()
{
    return this->zMax;
}

int Solution::getN()
{
    return this->n;
}

int Solution::getAmountVariables()
{
    return this->amountVariables;
}

void Solution::setResult(double *result)
{
    this->result.clear();
    for(int i=0;i<this->amountVariables;i++)
    {
        this->result.append(result[i]);
    }
}

void Solution::setNameVariables(QStringList nameVariables)
{
    this->nameVariables = nameVariables;
}

void Solution::setNearbyCity(int nearbyCity)
{
    this->nearbyCity = nearbyCity;
}

void Solution::setZmax(double zMax)
{
    this->zMax = zMax;
}

void Solution::setN(int n)
{
    this->n = n;
}

void Solution::setAmountVariables(int amountVariables)
{
    this->amountVariables = amountVariables;
}

void Solution::printResult()
{
    for(int i=0;i<this->amountVariables;i++)
    {
        std::cout << this->nameVariables.at(i).toAscii().data() << ": " << this->result.at(i) << std::endl;
    }
}
