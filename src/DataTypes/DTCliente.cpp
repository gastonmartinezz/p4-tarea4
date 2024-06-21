#include "../include/DataTypes/DTCliente.h"
#include "./DataTypes/DTDireccion.h"

DTCliente::DTCliente(string nickname, DTDireccion direccion, vector<Compra *> compras){};

DTDireccion DTCliente::getDireccion()
{
    return direccion;
};

set<string> DTCliente::getCompras()
{
    return compras;
}

DTCliente::~DTCliente() {}

// ostream &operator<<(ostream &os, DTCliente dtCliente)
// {
//     os << "Dirección: " << dtCliente.getDireccion() << ", Compras: ";
//     for (const auto &compra : dtCliente.getCompras())
//     {
//         os << compra << " ";
//     }
//     return os;
// }