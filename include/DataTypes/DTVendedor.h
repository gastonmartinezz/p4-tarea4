#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H

#include <iostream>
#include <set>
#include <string>
#include "DTProducto.h"
#include "DTPromocion.h"

using namespace std;

class DTVendedor
{
private:
    string rut;
    set<DTProducto> productos;
    set<DTPromocion> promociones;

public:
    DTVendedor(string rut, set<DTProducto> productos, set<DTPromocion> promociones);
    string getRut();
    set<DTProducto> getProductos();
    set<DTPromocion> getPromociones();
    ~DTVendedor();
};

ostream &operator<<(ostream &os, DTVendedor dtVendedor);

#endif // DTVENDEDOR_H
