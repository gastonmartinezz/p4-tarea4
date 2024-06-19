#include <Cliente.h>
#include "../include/DataTypes/DTDireccion.h"
#include <iostream>

class DTCliente;

Cliente::Cliente(std::string &nickname, std::string &password, DTFecha &fechaDeNacimiento,
                 DTDireccion &direccion)
    : Usuario(nickname, password, fechaDeNacimiento), direccion(direccion) {}

DTDireccion Cliente::getDireccion()
{
    return direccion;
}

std::set<std::string> Cliente::getNotificaciones()
{
    return notificaciones;
}

std::vector<Compra *> Cliente::getCompras()
{
    return compras;
}

void Cliente::setDireccion(DTDireccion &direccion)
{
    this->direccion = direccion;
}

void Cliente::agregarNotificacion(std::string &notificacion)
{
    notificaciones.insert(notificacion);
}

void Cliente::eliminarNotificacion(std::string &notificacion)
{
    notificaciones.erase(notificacion);
}

void Cliente::agregarCompra(Compra *compra)
{
    compras.push_back(compra);
}

void Cliente::mostrarInformacion()
{
    // Implementación de la función para mostrar la información del cliente
}

DTCliente Cliente::toDataType() {};
// DTCliente Cliente::toDataType()
// {
//   return   DTCliente::DTCliente(getNickname(),  getDireccion(), getCompras());
// };
