#include "Vendedor.h"
#include <iostream>

Vendedor::Vendedor(const std::string& nickname, const std::string& password, const DTFecha& fechaDeNacimiento,
                   int codigoRut)
    : Usuario(nickname, password, fechaDeNacimiento), codigoRut(codigoRut) {}

int Vendedor::getCodigoRut() const {
    return codigoRut;
}

std::set<Cliente> Vendedor::getSuscriptores() const {
    return suscriptores;
}

void Vendedor::setCodigoRut(int codigoRut) {
    this->codigoRut = codigoRut;
}

void Vendedor::agregarSuscriptor(const Cliente& cliente) {
    suscriptores.insert(cliente);
}

void Vendedor::eliminarSuscriptor(const Cliente& cliente) {
    suscriptores.erase(cliente);
}

void Vendedor::mostrarInformacion() const {
    std::cout << "Vendedor: " << nickname << "\n";
}
