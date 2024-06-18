#include <Cliente.h>
#include "../include/DataTypes/DTCliente.h"
#include "../include/DataTypes/DTDireccion.h"
#include <iostream>

Cliente::Cliente(const std::string &nickname, const std::string &password, const DTFecha &fechaDeNacimiento,
                 const DTDireccion &direccion)
    : Usuario(nickname, password, fechaDeNacimiento), direccion(direccion) {}

DTDireccion Cliente::getDireccion() const
{
    return direccion;
}

std::set<std::string> Cliente::getNotificaciones() const
{
    return notificaciones;
}

std::vector<Compra*> Cliente::getCompras() const
{
    return compras;
}

void Cliente::setDireccion(const DTDireccion &direccion)
{
    this->direccion = direccion;
}

void Cliente::agregarNotificacion(const std::string &notificacion)
{
    notificaciones.insert(notificacion);
}

void Cliente::eliminarNotificacion(const std::string &notificacion)
{
    notificaciones.erase(notificacion);
}

void Cliente::agregarCompra(Compra *compra)
{
    compras.push_back(compra);
}

void Cliente::mostrarInformacion() const
{
    // Implementación de la función para mostrar la información del cliente
}


DTCliente Cliente::toDataType() {
    return DTCliente(getNickname(), getDireccion(), getCompras());
};
