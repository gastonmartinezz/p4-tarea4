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
    int cantidad_minima;

public:
    
    Contenido(Producto *prod, int cantidad_minima);
    ~Contenido();

    Contenido();
    void setProducto(Producto *produ);

    int getCantMinima();
    Producto *getProducto();

    void setCantMinima(int cantMinima);
};

#endif