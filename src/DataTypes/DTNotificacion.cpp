#include "DTNotificacion.h"

DTNotificacion::DTNotificacion(Vendedor *emisor, Promocion *contenido)
    : emisor(emisor), contenido(contenido) {}

Vendedor *DTNotificacion::getEmisor() {
    return emisor;
}

Promocion *DTNotificacion::getContenido() {
    return contenido;
}

DTNotificacion::~DTNotificacion() {}
