#include "DTDireccion.h"

DTDireccion::DTDireccion(string ciudad_residencia, string calle, int numero_puerta)
    : ciudad_residencia(ciudad_residencia), calle(calle), numero_puerta(numero_puerta) {}

string DTDireccion::getCiudadResidencia() {
    return ciudad_residencia;
}

string DTDireccion::getCalle() {
    return calle;
}

int DTDireccion::getNumeroPuerta() {
    return numero_puerta;
}

DTDireccion::~DTDireccion() {}

ostream& operator<<(ostream& os, DTDireccion dtDireccion) {
    os << "Ciudad: " << dtDireccion.getCiudadResidencia() << ", Calle: " << dtDireccion.getCalle() << ", Número: " << dtDireccion.getNumeroPuerta();
    return os;
}
