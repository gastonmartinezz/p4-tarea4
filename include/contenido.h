#ifndef CONTENIDO_H
#define CONTENIDO_H
#include "Promocion.h"
#include "Producto.h"

// Esta clase es la clase producto/promocion

class Producto;
class Promocion;

class Contenido
{
private:
    Producto *prod;
    Promocion *promo;

public:
    int cantidad_minima;

    Contenido(Producto *prod, Promocion *promo);
    ~Contenido();

    int getCantMinima();
    Producto *getProducto();

    void setCantMinima(int cantMinima);
};

#endif