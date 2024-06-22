#include <Cliente.h>
#include "../include/DataTypes/DTDireccion.h"
#include "../include/DataTypes/DTCliente.h"
#include <iostream>

class DTCliente;

Cliente::Cliente(string &nickname, string &password, DTFecha &fechaDeNacimiento, DTDireccion &direccion)
    : Usuario(nickname, password, fechaDeNacimiento), direccion(direccion) {}

DTDireccion Cliente::getDireccion()
{
    return direccion;
}

set<string> Cliente::getNotificaciones()
{
    return notificaciones;
}

vector<Compra *> Cliente::getCompras()
{
    return compras;
}

void Cliente::setDireccion(DTDireccion &direccion)
{
    this->direccion = direccion;
}

void Cliente::agregarNotificacion(string &notificacion)
{
    notificaciones.insert(notificacion);
}

void Cliente::eliminarNotificacion(string &notificacion)
{
    notificaciones.erase(notificacion);
}

void Cliente::agregarCompra(Compra *compra)
{
    compras.push_back(compra);
}

void Cliente::mostrarInformacionCliente()
{
    DTFecha fecha = getFechaDeNacimiento();
    std::string string_fecha = fecha.toString();
    cout << "Nickname: " << getNickname() << endl;
    cout << "Fecha de Nacimiento: " << string_fecha << endl;
    // cout << "Direccion: " << getDireccion() << endl;
}

DTCliente Cliente::toDataType()
{
    return DTCliente(getNickname(), getDireccion(), getFechaDeNacimiento(), getCompras());
}

Cliente::~Cliente()
{
    for (auto compra : compras)
    {
        delete compra;
    }
    compras.clear();
}