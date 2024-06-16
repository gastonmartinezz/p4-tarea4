#include "DTVendedorProducto.h"

DTVendedorProducto::DTVendedorProducto(DTVendedor vendedor, DTProducto producto)
    : vendedor(vendedor), producto(producto) {}

DTVendedor DTVendedorProducto::getVendedor() {
    return vendedor;
}

DTProducto DTVendedorProducto::getProducto() {
    return producto;
}

DTVendedorProducto::~DTVendedorProducto() {}

ostream& operator<<(ostream& os, DTVendedorProducto dtVendedorProducto) {
    os << "Vendedor: " << dtVendedorProducto.getVendedor() << ", Producto: " << dtVendedorProducto.getProducto();
    return os;
}
