#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include <iostream>
#include <string>
#include <set>
#include "DTDireccion.h"
#include "DTFecha.h"
#include "Compra.h"
using namespace std;

class Compra;
class DTDireccion;
class DTFecha;

class DTCliente
{
private:
    string nickname;
    DTDireccion direccion;
    DTFecha fechaNacimiento;
    vector<Compra *> compras;

public:
    DTCliente(string nickname, DTDireccion direccion, DTFecha fechaNacimiento, vector<Compra *> compras = {}); // Ver si el puntero a compra es correcto
    string getNickname();
    DTDireccion getDireccion();
    vector<Compra *> getCompras();
    DTFecha getFechaNacimiento();

    ~DTCliente();
};

ostream &operator<<(ostream &os, DTCliente dtCliente);

#endif // DTCLIENTE_H