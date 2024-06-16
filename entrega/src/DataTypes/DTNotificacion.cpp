#include "DTNotificacion.h"

DTNotificacion::DTNotificacion(string emisor, string nombre, int id, string texto, set<string> contenido)
    : emisor(emisor), nombre(nombre), id(id), texto(texto), contenido(contenido) {}

string DTNotificacion::getEmisor() {
    return emisor;
}

string DTNotificacion::getNombre() {
    return nombre;
}

int DTNotificacion::getId() {
    return id;
}

string DTNotificacion::getTexto() {
    return texto;
}

set<string> DTNotificacion::getContenido() {
    return contenido;
}

DTNotificacion::~DTNotificacion() {}

ostream& operator<<(ostream& os, DTNotificacion dtNotificacion) {
    os << "Emisor: " << dtNotificacion.getEmisor() << ", Nombre: " << dtNotificacion.getNombre() << ", ID: " << dtNotificacion.getId() << ", Texto: " << dtNotificacion.getTexto();
    return os;
}
