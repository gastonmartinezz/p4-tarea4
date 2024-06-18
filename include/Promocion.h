#ifndef PROMOCION_H
#define PROMOCION_H

#include <iostream>
#include <set>
#include <string>
#include "../include/DataTypes/DTFecha.h"
#include "Vendedor.h"
#include "contenido.h"
using namespace std;

class Promocion {
private:
    float descuento;
    string nombre;
    string descripcion;
    DTFecha fecha_vencimiento;
    set<Contenido*> productosDentroDePromo;
    Vendedor* vendedor;

public:
    Promocion();
    Promocion(float descuento, string nombre, string desc, DTFecha fecha_ven);
    ~Promocion();

    set<Contenido*> getProductosDentroDePromo();
    string getDescripcion();
    float getDescuento();
    string getNombre();
    DTFecha getFechaVencimiento();
    Vendedor* getVendedor();

    void setDescuento(float descuento);
    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setFechaVencimiento(DTFecha fecha);
    void setVendedor(Vendedor* vendedor);

    void agregarProducto(Contenido *contenido);
};

set<Promocion*> promociones; //Set donde guardamos todas las promociones del sistema
set<Promocion*> promocionesVigentes; //Set donde guardamos todas las promociones vigentes del sistema
#endif