#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
#include <string>
using namespace std;
class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(int d, int m, int a);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    bool operator>(const DTFecha &other) const;
    bool esNula() const;

    ~DTFecha();

    string toString() const;
};

#endif // DTFECHA_H