#include "../include/contenido.h"

Contenido::Contenido(){};
Contenido::Contenido(Producto *prod, int cantidad_minima) : prod(prod), cantidad_minima(cantidad_minima){}

Contenido::~Contenido()
{
    delete prod;
}

int Contenido::getCantMinima()
{
    return this->cantidad_minima;
}

Producto *Contenido::getProducto()
{
    return this->prod;
}



void Contenido::setCantMinima(int cantMinima)
{
    this->cantidad_minima = cantMinima;
}

void Contenido::setProducto(Producto *produ)
{
    this->prod = produ;
}
