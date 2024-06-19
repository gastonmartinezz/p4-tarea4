#include "../include/Fabrica.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/Controladores/ControladorUsuario.h"

ControladorUsuario* Fabrica::getICUsuario() {
    return ControladorUsuario::getInstance();
}

ControladorProducto* Fabrica::getICProductos() { //Cambie el tipo de devolucion de la funcion para ver si funciona correctamente
    return ControladorProducto::getInstance();
}

void Fabrica::eliminar() {
    ControladorUsuario* aux1 = ControladorUsuario::getInstance();
    delete aux1;
    ControladorProducto* aux2 = ControladorProducto::getInstance();
    delete aux2;
}