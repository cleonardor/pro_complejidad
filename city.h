#ifndef CITY_H
#define CITY_H

#include <QString>

class City
{
private:
    int number;
    int coorX;
    int coorY;
public:
    City();
    City(int number, int coorX, int coorY);
    void setNumber(int number);
    void setCoorX(int coorX);
    void setCoorY(int coorY);

    int getNumber();
    int getCoorX();
    int getCoorY();

    QString getStringCity();

};

#endif // CITY_H
