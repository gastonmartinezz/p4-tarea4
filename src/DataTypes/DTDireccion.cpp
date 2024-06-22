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

// Destructor
DTDireccion::~DTDireccion() {}

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& os, const DTDireccion& dtDireccion) {
    os << "Ciudad: " << dtDireccion.ciudad_residencia << ", Calle: " << dtDireccion.calle << ", Numero: " << dtDireccion.numero_puerta;
    return os;
}

// Sobrecarga del operador de entrada
std::istream& operator>>(std::istream& is, DTDireccion& dtDireccion) {
    std::string input;

    std::cout << "Ingrese ciudad de residencia: ";
    std::getline(is, dtDireccion.ciudad_residencia);

    std::cout << "Ingrese calle: ";
    std::getline(is, dtDireccion.calle);

    std::cout << "Ingrese numero de puerta: ";
    std::getline(is, input);
    dtDireccion.numero_puerta = std::stoi(input);

    return is;
}
