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

class DTDireccion {
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

    ~DTDireccion();

    // Sobrecarga del operador de salida
    friend std::ostream& operator<<(std::ostream& os, const DTDireccion& dtDireccion);

    // Sobrecarga del operador de entrada
    friend std::istream& operator>>(std::istream& is, DTDireccion& dtDireccion);
};

#endif // DTDIRECCION_H
