#ifndef FABRICA_H
#define FABRICA_H

#include "../include/Interfaces/ICProductos.h"
#include "../include/Interfaces/ICUsuario.h"

class Fabrica
{
private:
    Fabrica();

public:
    static ICUsuario *getICUsuario();
    static ICProductos *getICProductos();
    static void eliminar();
};

#endif
