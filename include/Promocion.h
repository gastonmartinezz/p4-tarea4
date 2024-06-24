#ifndef PROMOCION_H
#define PROMOCION_H

#include <iostream>
#include <set>
#include <string>
#include "../include/DataTypes/DTFecha.h"
#include "Vendedor.h"
#include "contenido.h"
#include "../include/DataTypes/DTPromocion.h"
using namespace std;

class Vendedor;
class Contenido;
class DTPromocion;

class Promocion {
private:
    float descuento;
    string nombre;
    string descripcion;
    DTFecha fecha_vencimiento;
    vector<Contenido *> productosDentroDePromo;
    Vendedor *vendedor;
    string ref;
public:
    Promocion(float descuento, string nombre, string desc, DTFecha fecha_ven);
    ~Promocion();
    Promocion();

    vector<Contenido *> getProductosDentroDePromo();
    string getDescripcion()const;
    float getDescuento();
    string getNombre();
    DTFecha getFechaVencimiento();
    Vendedor *getVendedor();
    void setReferencia(string ref);
    string getReferencia();

    void setDescuento(float descuento);
    void setNombre(string nombre);
    void setDescripcion(string descripcion);
    void setFechaVencimiento(DTFecha fecha);
    void setVendedor(Vendedor *vendedor);
    void setProductosDentroDePromo(vector<Contenido*> produ);

    DTPromocion toDataType();

    void agregarProducto(Contenido *contenido);
};

// set<Promocion*> promociones; //Set donde guardamos todas las promociones del sistema
// set<Promocion*> promocionesVigentes; //Set donde guardamos todas las promociones vigentes del sistema
#endif