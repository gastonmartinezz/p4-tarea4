#ifndef DTPROMOCION_H
#define DTPROMOCION_H

#include <iostream>
#include <string>
#include "DTFecha.h"
#include "../include/Vendedor.h"
#include "../include/DataTypes/DTVendedor.h"
using namespace std;

class Vendedor;

class DTPromocion {
private:
    float descuento;
    string nombre;
    string descripcion;
    DTFecha fechaVencimiento;
    Vendedor* vendedor;

public:
    DTPromocion(float descuento, string nombre, string descripcion, DTFecha fechaVencimiento);
    float getDescuento();
    string getNombre();
    string getDescripcion();
    DTFecha getFechaVencimiento();
    Vendedor* getVendedor();
    ~DTPromocion();
    

    void setVendedor(Vendedor* vendedor);

};

ostream& operator<<(ostream& os, DTPromocion dtPromocion);

#endif // DTPROMOCION_H
