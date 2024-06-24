#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "Compra.h"
#include "../include/DataTypes/DTCliente.h"
#include "../include/DataTypes/DTDireccion.h"
#include "../include/DataTypes/DTNotificacion.h"
#include "../include/Compra.h"
#include <vector>
#include <set>
#include <string>
using namespace std;

class DTCliente;
class DTDireccion;
class DTNotificacion;
class Compra;

class Cliente : public Usuario {
private:
    DTDireccion direccion;
    vector<DTNotificacion> notificaciones;
    vector<Compra *> compras; // Agregar esta línea para almacenar las compras del cliente

public:
    Cliente(string &nickname, string &password, DTFecha &fechaDeNacimiento, DTDireccion &direccion);
    ~Cliente();

    DTDireccion getDireccion();
    vector<DTNotificacion> getNotificaciones();
    vector<Compra *> getCompras(); // Agregar este método para obtener las compras

    DTCliente toDataType();

    void setDireccion(DTDireccion &direccion);
    void agregarNotificacion(DTNotificacion &notificacion);
    void eliminarNotificacion();
    void agregarCompra(Compra *compra); // Agregar este método para agregar una compra
    void mostrarInformacionCliente();
};

#endif // CLIENTE_H