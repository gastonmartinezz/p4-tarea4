#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "Compras.h"
#include <vector>
#include <set>
#include <string>

struct DTDireccion {
    std::string calle;
    std::string ciudad;
    std::string pais;
};

class Cliente : public Usuario {
private:
    DTDireccion direccion;
    std::set<std::string> notificaciones;
    std::vector<Compra> compras; // Agregar esta línea para almacenar las compras del cliente

public:
    Cliente(const std::string& nickname, const std::string& password, const DTFecha& fechaDeNacimiento,
            const DTDireccion& direccion);

    DTDireccion getDireccion() const;
    std::set<std::string> getNotificaciones() const;
    std::vector<Compra> getCompras() const; // Agregar este método para obtener las compras

    void setDireccion(const DTDireccion& direccion);
    void agregarNotificacion(const std::string& notificacion);
    void eliminarNotificacion(const std::string& notificacion);
    void agregarCompra(const Compra& compra); // Agregar este método para agregar una compra

    void mostrarInformacion() const override;
};

#endif // CLIENTE_H

