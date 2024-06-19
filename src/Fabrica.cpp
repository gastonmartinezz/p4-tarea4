#include "../include/Fabrica.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/Controladores/ControladorUsuario.h"

ICUsuario *Fabrica::getICUsuario()
{
    return ControladorUsuario::getInstancia();
}

ICProductos *Fabrica::getICProductos()
{
    return ControladorProducto::getInstancia();
}

void Fabrica::eliminar()
{
    ControladorUsuario *aux = ControladorUsuario::getInstancia();
    delete aux;
    ControladorProducto *aux = ControladorProducto::getInstancia();
    delete aux;
}