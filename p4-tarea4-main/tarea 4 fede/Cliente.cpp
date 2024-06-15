#include "Cliente.h"
#include <iostream>

Cliente::Cliente(const std::string& nickname, const std::string& password, const DTFecha& fechaDeNacimiento,
                 const DTDireccion& direccion)
    : Usuario(nickname, password, fechaDeNacimiento), direccion(direccion) {}

DTDireccion Cliente::getDireccion() const {
    return direccion;
}

std::set<std::string> Cliente::getNotificaciones() const {
    return notificaciones;
}

void Cliente::setDireccion(const DTDireccion& direccion) {
    this->direccion = direccion;
}

void Cliente::agregarNotificacion(const std::string& notificacion) {
    notificaciones.insert(notificacion);
}

void Cliente::eliminarNotificacion(const std::string& notificacion) {
    notificaciones.erase(notificacion);
}

void Cliente::mostrarInformacion() const {
    std::cout << "Cliente: " << nickname << "\n";
}
