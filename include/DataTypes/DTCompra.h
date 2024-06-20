#ifndef DTCOMPRAS_H
#define DTCOMPRAS_H

#include <iostream>
#include <string>
#include "DTFecha.h"
using namespace std;

class DTCompras {
private:
    string nombreCliente;
    DTFecha fechaCompra;

public:
    DTCompras(string nombreCliente, DTFecha fechaCompra);
    string getNombreCliente();
    DTFecha getFechaCompra();

    void setNombreCliente(string nombreCliente);
    void setFechaCompra(DTFecha fecha);
    ~DTCompras();
};

ostream& operator<<(ostream& os, DTCompras dtCompras);

#endif // DTCOMPRAS_H
