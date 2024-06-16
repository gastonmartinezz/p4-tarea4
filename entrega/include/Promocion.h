#ifndef PROMOCION_H
#define PROMOCION_H

#include <iostream>
#include <set>
#include <string>
#include "DataTypes/DTFecha.h"
#include <Vendedor.h>
#include <producto|promocion.h>
using namespace std;

class Promocion {
private:
    float descuento;
    string nombre;
    string descripcion;
    DTFecha fecha_vencimiento;
    set<Contenido*> productosDentroDePromo;
    Vendedor Vendedor;

public:
    Promocion();
    Promocion(float descuento, string nombre, string desc, DTFecha fecha_ven);
    ~Promocion();
    set<Contenido*> getProductosDentroDePromo();
    string getDescripcion();
    float getDescuento();
    string getNombre() const;
    void agregarProducto(Producto *prod);
    DTFecha getFechaVencimiento();
    Vendedor getVendedor();
};

#endif