#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "DTProducto.h"
#include "DTPromocion.h"
#include "../include/Promocion.h"
#include "../include/Producto.h"

using namespace std;

class DTVendedor
{
private:
    int rut;
    vector<Producto *> productos;
    vector<Promocion *> promociones;
    std::string nickname;

public:
    DTVendedor(int rut, vector<Producto *> productos, vector<Promocion *> promociones, std::string nickname); // Compila pero estamos usando OBJETOS y no DATATYPES. Hay que corregirlo aca y en CPP.
    int getRut();
    std::string getNickname();
    vector<Producto *> getProductos();
    vector<Promocion *> getPromociones();
    ~DTVendedor();
};

ostream &operator<<(ostream &os, DTVendedor dtVendedor);

#endif // DTVENDEDOR_H
