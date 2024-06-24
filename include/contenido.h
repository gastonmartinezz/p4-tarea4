#ifndef CONTENIDO_H
#define CONTENIDO_H
#include "Promocion.h"
#include "Producto.h"
#include "../include/DataTypes/DTContenido.h"
#include "../include/DataTypes/DTProducto.h"

// Esta clase es la clase asociativa producto/promocion

class Producto;
class Promocion;
class DTContenido;
class DTProducto;

class Contenido
{
private:
    Producto *prod;
    int cantidad_minima;
    string ref;

public:
    Contenido(Producto *prod, int cantidad_minima);
    ~Contenido();
    void setReferencia(string ref);
    string getReferencia(); 

    Contenido();
    void setProducto(Producto *produ);

    int getCantMinima();
    Producto *getProducto();

    void setCantMinima(int cantMinima);
    DTContenido toDataType();
};

#endif