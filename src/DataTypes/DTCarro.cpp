#include "../include/DataTypes/DTCarro.h"


DTCarro::DTCarro(int prod, int cantidad) : prod(prod), cantidad(cantidad) {}


int DTCarro::getProd()const {
    return prod;
}
int DTCarro::getCantidad() {
    return cantidad;
}
void DTCarro::setProd(int p) {
    this->prod = p;
}
void DTCarro::setCantidad(int c) {
    this->cantidad = c;
}