#ifndef PROMOCION_H
#define PROMOCION_H

#include <iostream>
#include <set>
#include <string>
#include "DataTypes/DTFecha.h"
#include "Vendedor.h"

class Promocion
{
private:
    float descuento;
    string nombre;
    string descripcion;
    DTFecha fecha_vencimiento;
    set<Producto *> productosDentroDePromo;
    Vendedor Vendedor;

public:
    Promocion(float descuento, string nombre, string desc, DTFecha fecha_ven);
    ~Promocion();
    float getDescuento();
    std::string getNombre() const;
    void agregarProducto(Producto *prod);
    DTFecha getFechaVencimiento();
    Vendedor getVendedor();
};

#endif
