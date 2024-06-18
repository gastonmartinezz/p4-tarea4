#include <Fabrica.h>
#include <ControladorProducto.h>
#include <ControladorUsuario.h>

ICUsuario *Fabrica::getICUsuario()
{
    return ControladorUsuario::getInstance();
}

ICProductos *Fabrica::getICProductos()
{
    return ControladorProducto::getInstance();
}

void Fabrica::eliminar()
{
    ControladorUsuario *aux = ControladorUsuario::getInstance();
    delete aux;
    ControladorProducto *aux = ControladorProducto::getInstance();
    delete aux;
}