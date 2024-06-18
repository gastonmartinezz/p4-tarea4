#include "../include/contenido.h"

Contenido::Contenido(Producto* prod, Promocion* promo): producto(prod), promo(promo), cantidad_minima(0) {
    //Tengo dudas con este constructor
} 

Contenido::~Contenido() {
    delete promo;
    delete producto;
}

int Contenido::getCantMinima() {
    return cantidad_minima;
}

Producto* Contenido::getProducto() {
    return producto;
}

void Contenido::setCantMinima(int cantMinima) {
    this->cantidad_minima = cantMinima;
}