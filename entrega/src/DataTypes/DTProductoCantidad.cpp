#include "DTProductoCantidad.h"

DTProductoCantidad::DTProductoCantidad(set<DTProducto> productos, map<DTProducto, int> cantMinima)
    : productos(productos), cantMinima(cantMinima) {}

set<DTProducto> DTProductoCantidad::getProductos() {
    return productos;
}

map<DTProducto, int> DTProductoCantidad::getCantMinima() {
    return cantMinima;
}

DTProductoCantidad::~DTProductoCantidad() {}

ostream& operator<<(ostream& os, DTProductoCantidad dtProductoCantidad) {
    os << "Productos: ";
    for (const auto& producto : dtProductoCantidad.getProductos()) {
        os << producto << " ";
    }
    os << ", Cantidad Mínima: ";
    for (const auto& [producto, cantidad] : dtProductoCantidad.getCantMinima()) {
        os << producto << ": " << cantidad << " ";
    }
    return os;
}
