#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "Compra.h"
#include "../include/DataTypes/DTCliente.h"
#include "../include/DataTypes/DTDireccion.h"
#include <vector>
#include <set>
#include <string>

class DTCliente;
class DTDireccion;

class Cliente : public Usuario
{
private:
    DTDireccion direccion;
    std::set<std::string> notificaciones;
    std::vector<Compra *> compras; // Agregar esta línea para almacenar las compras del cliente

public:
    Cliente(std::string &nickname, std::string &password, DTFecha &fechaDeNacimiento,
            DTDireccion &direccion);

    DTDireccion getDireccion();
    std::set<std::string> getNotificaciones();
    std::vector<Compra *> getCompras(); // Agregar este método para obtener las compras

    DTCliente toDataType();

    void setDireccion(DTDireccion &direccion);
    void agregarNotificacion(std::string &notificacion);
    void eliminarNotificacion(std::string &notificacion);
    void agregarCompra(Compra *compra); // Agregar este método para agregar una compra

    void mostrarInformacion();
};

#endif // CLIENTE_H
