#include "../include/DataTypes/DTDetalleCompras.h"

DTDetalleCompra::DTDetalleCompra(float monto_total, DTFecha fecha, set<DTProducto> productos)
    : monto_total(monto_total), fecha(fecha), productos(productos) {}

float DTDetalleCompra::getMontoTotal()
{
    return monto_total;
}

DTFecha DTDetalleCompra::getFecha()
{
    return fecha;
}

set<DTProducto> DTDetalleCompra::getProductos()
{
    return productos;
}

DTDetalleCompra::~DTDetalleCompra() {}

ostream &operator<<(ostream &os, DTDetalleCompra dtDetalleCompra)
{
    DTFecha fecha = dtDetalleCompra.getFecha();
    os << "Monto Total: " << dtDetalleCompra.getMontoTotal() << ", Fecha: " << fecha.toString() << ", Productos: ";
    for (const auto &producto : dtDetalleCompra.getProductos())
    {
        os << producto << " ";
    }
    return os;
}
