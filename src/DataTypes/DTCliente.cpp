#include "../include/DataTypes/DTCliente.h"
#include "./DataTypes/DTDireccion.h"

DTCliente::DTCliente(string nickname, DTDireccion direccion, DTFecha fechaNacimiento, vector<Compra *> compras)
    : nickname(nickname), direccion(direccion), fechaNacimiento(fechaNacimiento), compras(compras) // Asignación directa
{
    // No es necesario hacer nada aquí, ya que los miembros se inicializan directamente.
}

string DTCliente::getNickname()
{
    return nickname;
}

DTDireccion DTCliente::getDireccion()
{
    return direccion;
};

vector<Compra *> DTCliente::getCompras()
{
    return compras;
}

DTFecha DTCliente::getFechaNacimiento()
{
    return fechaNacimiento;
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