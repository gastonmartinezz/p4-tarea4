#ifndef DTDETALLECOMPRA_H
#define DTDETALLECOMPRA_H

#include <iostream>
#include <set>
#include "DTFecha.h"
#include "DTProducto.h"

using namespace std;

class DTDetalleCompra {
private:
    float monto_total;
    DTFecha fecha;
    set<DTProducto> productos;

public:
    DTDetalleCompra(float monto_total, DTFecha fecha, set<DTProducto> productos);
    float getMontoTotal();
    DTFecha getFecha();
    set<DTProducto> getProductos();
    ~DTDetalleCompra();
};

ostream& operator<<(ostream& os, DTDetalleCompra dtDetalleCompra);

#endif // DTDETALLECOMPRA_H
