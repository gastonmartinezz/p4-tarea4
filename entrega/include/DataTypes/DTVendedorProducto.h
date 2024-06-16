#ifndef DTVENDEDORPRODUCTO_H
#define DTVENDEDORPRODUCTO_H

#include <iostream>
#include <string>
#include "DTVendedor.h"
#include "DTProducto.h"

using namespace std;

class DTVendedorProducto {
private:
    DTVendedor vendedor;
    DTProducto producto;

public:
    DTVendedorProducto(DTVendedor vendedor, DTProducto producto);
    DTVendedor getVendedor();
    DTProducto getProducto();
    ~DTVendedorProducto();
};

ostream& operator<<(ostream& os, DTVendedorProducto dtVendedorProducto);

#endif // DTVENDEDORPRODUCTO_H
