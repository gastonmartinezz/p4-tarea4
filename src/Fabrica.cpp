#include "../include/Fabrica.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/Controladores/ControladorUsuario.h"

ICUsuario* Fabrica::getICUsuario()
{
    return ControladorUsuario::getInstance();
}

ICProductos* Fabrica::getICProductos()
{
    return ControladorProducto::getInstance();
}

void Fabrica::eliminar()
{
    ControladorUsuario* aux1 = ControladorUsuario::getInstance();
    delete aux1;
    ControladorProducto* aux2 = ControladorProducto::getInstance();
    delete aux2;
}