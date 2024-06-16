#include "DTCliente.h"

DTCliente::DTCliente(string direccion, set<string> compras)
    : direccion(direccion), compras(compras) {}

string DTCliente::getDireccion() {
    return direccion;
}

set<string> DTCliente::getCompras() {
    return compras;
}

DTCliente::~DTCliente() {}

ostream& operator<<(ostream& os, DTCliente dtCliente) {
    os << "Dirección: " << dtCliente.getDireccion() << ", Compras: ";
    for (const auto& compra : dtCliente.getCompras()) {
        os << compra << " ";
    }
    return os;
}
