#ifndef DTVENDEDOR_H
#define DTVENDEDOR_H

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include "DTCliente.h"
#include "DTProducto.h"
#include "DTPromocion.h"
#include "../include/Cliente.h"
#include "../include/Promocion.h"
#include "../include/Producto.h"

class Cliente;

using namespace std;

class DTVendedor
{
private:
    std::string nickname;
    int rut;
    set<Cliente *> suscriptores;
    vector<Producto *> productos;
    vector<Promocion *> promociones;
    DTFecha fechaNacimiento;

public:
    DTVendedor(string nickname, int rut, DTFecha fechaNacimiento, set<Cliente *> suscriptores = {}, vector<Producto *> productos = {}, vector<Promocion *> promociones = {});
    std::string getNickname();
    int getRut();
    set<Cliente *> getSuscriptores();
    vector<Producto *> getProductos();
    vector<Promocion *> getPromociones();
    ~DTVendedor();
};

ostream &operator<<(ostream &os, DTVendedor dtVendedor);

#endif // DTVENDEDOR_H
