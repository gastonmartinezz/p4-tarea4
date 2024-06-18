#ifndef DTPROMOCION_H
#define DTPROMOCION_H

#include <iostream>
#include <string>
#include "DTFecha.h"

using namespace std;

class DTPromocion {
private:
    float descuento;
    string nombre;
    string descripcion;
    DTFecha fechaVencimiento;

public:
    DTPromocion(float descuento, string nombre, string descripcion, DTFecha fechaVencimiento);
    float getDescuento();
    string getNombre();
    string getDescripcion();
    DTFecha getFechaVencimiento();
    ~DTPromocion();
};

ostream& operator<<(ostream& os, DTPromocion dtPromocion);

#endif // DTPROMOCION_H
