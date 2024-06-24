#include "../../include/DataTypes/DTDireccion.h"
/*
DTDireccion::DTDireccion()
    : ciudad_residencia(""), calle(""), numero_puerta(0) {} // Definición del constructor por defecto

DTDireccion::DTDireccion(string ciudad_residencia, string calle, int numero_puerta)
    : ciudad_residencia(ciudad_residencia), calle(calle), numero_puerta(numero_puerta) {}

string DTDireccion::getCiudadResidencia()
{
    return ciudad_residencia;
}

string DTDireccion::getCalle()
{
    return calle;
}

int DTDireccion::getNumeroPuerta()
{
    return numero_puerta;
}

DTDireccion::~DTDireccion() {}

ostream &operator<<(ostream &os, DTDireccion dtDireccion)
{
    os << "Ciudad: " << dtDireccion.getCiudadResidencia() << ", Calle: " << dtDireccion.getCalle() << ", Número: " << dtDireccion.getNumeroPuerta();
    return os;
}
*/

#include "DTDireccion.h"
#include <sstream>

// Constructores
DTDireccion::DTDireccion() : ciudad_residencia(""), calle(""), numero_puerta(0) {}

DTDireccion::DTDireccion(std::string ciudad_residencia, std::string calle, int numero_puerta)
    : ciudad_residencia(ciudad_residencia), calle(calle), numero_puerta(numero_puerta) {}

// Métodos de acceso
std::string DTDireccion::getCiudadResidencia() const { return ciudad_residencia; }
std::string DTDireccion::getCalle() const { return calle; }
int DTDireccion::getNumeroPuerta() const { return numero_puerta; }
std::string DTDireccion::toString() const
{
    return getCiudadResidencia() + "-" + getCalle() + " : " + std::to_string(getNumeroPuerta());
    // return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

// Destructor
DTDireccion::~DTDireccion() {}
