#include "../include/DataTypes/DTContenido.h"

class DTProducto;
class DTPromocion;

DTContenido::DTContenido(DTProducto prod, int cantidad_minima): prod(prod), cantidad_minima(cantidad_minima) {}

void DTContenido::setProducto(DTProducto produ) {
    this->prod = produ;
}

int DTContenido::getCantMinima() {
    return cantidad_minima;
}

DTProducto DTContenido::getProducto() {
    return prod;
}

void DTContenido::setCantMinima(int cantMinima) {
    this->cantidad_minima = cantMinima;
}

DTContenido::~DTContenido() {}