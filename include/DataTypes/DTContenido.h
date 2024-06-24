#ifndef DTCONTENIDO_H
#define DTCONTENIDO_H
#include "../include/contenido.h"
#include "../include/DataTypes/DTProducto.h"
#include "../include/DataTypes/DTPromocion.h"

// Esta clase es la clase asociativa producto/promocion

class DTProducto;
class DTPromocion;

class DTContenido
{
private:
    DTProducto prod;
    int cantidad_minima;

public:
    DTContenido(DTProducto prod, int cantidad_minima);
    ~DTContenido();

    void setProducto(DTProducto produ);

    int getCantMinima();
    DTProducto getProducto();

    void setCantMinima(int cantMinima);
};

#endif