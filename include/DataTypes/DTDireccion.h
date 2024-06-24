/*
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

*/

#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
#include <string>

class DTDireccion
{
private:
    std::string ciudad_residencia;
    std::string calle;
    int numero_puerta;

public:
    DTDireccion();
    DTDireccion(std::string ciudad_residencia, std::string calle, int numero_puerta);

    std::string getCiudadResidencia() const;
    std::string getCalle() const;
    int getNumeroPuerta() const;
    std::string toString() const;
    ~DTDireccion();
};

#endif // DTDIRECCION_H
