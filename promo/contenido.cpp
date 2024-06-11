#include <contenido.h>

int Contenido::getCantMinima() {
    return cantidad_minima;
}

Contenido::~Contenido() {
    delete producto; //Me da error y no le encuentro la 
    delete promo; // solucion :(
}