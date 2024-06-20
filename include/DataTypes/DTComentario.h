#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <iostream>
#include <string>
#include "../include/DataTypes/DTFecha.h"

using namespace std;

class DTComentario {
private:
    int id;
    string texto;
    DTFecha fechaDeRealizado;

public:
    DTComentario(int id, string texto, DTFecha fechaDeRealizado);
    int getId();
    string getTexto();
    DTFecha getFechaDeRealizado();
    ~DTComentario();
};

ostream& operator<<(ostream& os, DTComentario dtComentario);

#endif // DTCOMENTARIO_H
