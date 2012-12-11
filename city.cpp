#include "city.h"

City::City(){}

City::City(int number, int coorX, int coorY)
{
    this->number = number;
    this->coorX = coorX;
    this->coorY = coorY;
}

void City::setNumber(int number)
{
    this->number = number;
}

void City::setCoorX(int coorX)
{
    this->coorX = coorX;
}

void City::setCoorY(int coorY)
{
    this->coorY = coorY;
}

int City::getNumber()
{
    return this->number;
}

int City::getCoorX()
{
    return this->coorX;
}

int City::getCoorY()
{
    return this->coorY;
}

QString City::getStringCity()
{
    QString city = "Number: " + QString::number(this->number) + " CoorX: " + QString::number(this->coorX) + " CoorY: " + QString::number(this->coorY);
    return city;
}
