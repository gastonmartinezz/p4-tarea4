#ifndef CONTENIDO_H
#define CONTENIDO_H
#include "Promocion.h"
#include "Producto.h"

// Esta clase es la clase asociativa producto/promocion

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

    Contenido();
    void setProducto(Producto *produ);
    void setPromocion(Promocion *promoc);

    int getCantMinima();
    Producto *getProducto();
    Promocion *getPromocion();

    void setCantMinima(int cantMinima);
};

#endif