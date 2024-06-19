#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include <iostream>
#include <string>
#include <set>
#include "DTDireccion.h"
#include "../include/Compra.h"

using namespace std;

class Compra;
class DTDireccion;

class DTCliente
{
private:
    std::string nickname;
    DTDireccion direccion;
    set<string> compras;

public:
    DTCliente(std::string nickname, DTDireccion direccion, set<Compra *> compras); // Ver si el puntero a compra es correcto
    DTDireccion getDireccion();
    set<string> getCompras();
    ~DTCliente();
};

ostream &operator<<(ostream &os, DTCliente dtCliente);

#endif // DTCLIENTE_H