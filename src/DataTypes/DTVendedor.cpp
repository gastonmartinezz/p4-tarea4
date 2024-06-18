#include "DTVendedor.h"

DTVendedor::DTVendedor(string rut, set<DTProducto> productos, set<DTPromocion> promociones)
    : rut(rut), productos(productos), promociones(promociones) {}

string DTVendedor::getRut() {
    return rut;
}

set<DTProducto> DTVendedor::getProductos() {
    return productos;
}

set<DTPromocion> DTVendedor::getPromociones() {
    return promociones;
}

DTVendedor::~DTVendedor() {}

ostream& operator<<(ostream& os, DTVendedor dtVendedor) {
    os << "RUT: " << dtVendedor.getRut() << ", Productos: ";
    for (const auto& producto : dtVendedor.getProductos()) {
        os << producto << " ";
    }
    os << ", Promociones: ";
    for (const auto& promocion : dtVendedor.getPromociones()) {
        os << promocion << " ";
    }
    return os;
}
