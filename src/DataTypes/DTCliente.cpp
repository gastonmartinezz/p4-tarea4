#include "../include/DataTypes/DTCliente.h"
#include "../include/DataTypes/DTDireccion.h"

class DTDireccion;

DTCliente::DTCliente(std::string nickname, DTDireccion direccion, set<Compra *> compras) {};

DTDireccion DTCliente::getDireccion() {
    return direccion;
};

set<string> DTCliente::getCompras() {
    return compras;
}

DTCliente::~DTCliente() {}

ostream &operator<<(ostream &os, DTCliente dtCliente) {
    os << "Dirección: " << dtCliente.getDireccion() << ", Compras: ";
    for (const auto &compra : dtCliente.getCompras())
    {
        os << compra << " ";
    }
    return os;
}