#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include <iostream>
#include <string>
#include <set>
#include "DTDireccion.h"
#include "Compra.h"
using namespace std;

class Compra;
class DTDireccion;

class DTCliente {
private:
    string nickname;
    DTDireccion direccion;
    set<string> compras;

public:
    DTCliente(string nickname, DTDireccion direccion, vector<Compra*> compras); // Ver si el puntero a compra es correcto
    string getNickname();
    DTDireccion getDireccion();
    set<string> getCompras();
    ~DTCliente();
};

ostream &operator<<(ostream &os, DTCliente dtCliente);

#endif // DTCLIENTE_H