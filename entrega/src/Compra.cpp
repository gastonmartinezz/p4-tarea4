#include "../include/Compra.h"
#include "../include/DataTypes/DTFecha.h" 

Compra::Compra(int id, const DTFecha& fecha, const std::vector<Producto>& productos)
    : id(id), fecha(fecha), productos(productos) {}

int Compra::getId() const {
    return id;
}

DTFecha Compra::getFecha() const {
    return fecha;
}

std::vector<Producto> Compra::getProductos() const {
    return productos;
}
