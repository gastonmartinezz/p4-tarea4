#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"

struct DTDireccion {
    std::string calle;
    std::string ciudad;
    std::string pais;
};

class Cliente : public Usuario {
private:
    DTDireccion direccion;
    std::set<std::string> notificaciones;

public:
    Cliente(const std::string& nickname, const std::string& password, const DTFecha& fechaDeNacimiento,
            const DTDireccion& direccion);

    DTDireccion getDireccion() const;
    std::set<std::string> getNotificaciones() const;

    void setDireccion(const DTDireccion& direccion);
    void agregarNotificacion(const std::string& notificacion);
    void eliminarNotificacion(const std::string& notificacion);

    void mostrarInformacion() const override;
};

#endif // CLIENTE_H
