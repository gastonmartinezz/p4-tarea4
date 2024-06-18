#ifndef DTPRODUCTOCANTIDAD_H
#define DTPRODUCTOCANTIDAD_H

#include <iostream>
#include <set>
#include <map>
#include "DTProducto.h"

using namespace std;

class DTProductoCantidad {
private:
    set<DTProducto> productos;
    map<DTProducto, int> cantMinima;

public:
    DTProductoCantidad(set<DTProducto> productos, map<DTProducto, int> cantMinima);
    set<DTProducto> getProductos();
    map<DTProducto, int> getCantMinima();
    ~DTProductoCantidad();
};

ostream& operator<<(ostream& os, DTProductoCantidad dtProductoCantidad);

#endif // DTPRODUCTOCANTIDAD_H
