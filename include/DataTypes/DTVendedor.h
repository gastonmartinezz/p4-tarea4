#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H

#include <iostream>
#include <set>
#include <vector>
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
    DTVendedor(int rut, vector<Producto*> productos, vector<Promocion*> promociones); //Compila pero estamos usando OBJETOS y no DATATYPES. Hay que corregirlo
    string getRut();
    set<DTProducto> getProductos();
    set<DTPromocion> getPromociones();
    ~DTVendedor();
};

ostream &operator<<(ostream &os, DTVendedor dtVendedor);

#endif // DTVENDEDOR_H
