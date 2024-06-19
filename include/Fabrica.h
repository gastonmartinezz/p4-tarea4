#ifndef FABRICA_H
#define FABRICA_H

#include "../include/Interfaces/ICProductos.h"
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/Controladores/ControladorUsuario.h"

class Fabrica {
private:
    Fabrica();
public:
    static ControladorUsuario* getICUsuario(); //cambie los tipos de interfaz a controlador para que compile, hay que fijarse
    static ControladorProducto* getICProductos();
    static void eliminar();
};

#endif
