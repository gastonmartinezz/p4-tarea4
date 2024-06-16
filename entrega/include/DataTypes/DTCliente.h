#ifndef DTCLIENTE_H
#define DTCLIENTE_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

class DTCliente {
private:
    string direccion;
    set<string> compras;

public:
    DTCliente(string direccion, set<string> compras);
    string getDireccion();
    set<string> getCompras();
    ~DTCliente();
};

ostream& operator<<(ostream& os, DTCliente dtCliente);

#endif // DTCLIENTE_H
