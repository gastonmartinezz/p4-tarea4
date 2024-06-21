#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
#include <string>

using namespace std;

class DTDireccion
{
private:
    string ciudad_residencia;
    string calle;
    int numero_puerta;

public:
    DTDireccion();
    DTDireccion(string ciudad_residencia, string calle, int numero_puerta);
    string getCiudadResidencia();
    string getCalle();
    int getNumeroPuerta();
    ~DTDireccion();
};

ostream &operator<<(ostream &os, DTDireccion dtDireccion);

#endif // DTDIRECCION_H
