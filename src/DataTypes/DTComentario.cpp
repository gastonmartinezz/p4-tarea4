#include "DTComentario.h"

DTComentario::DTComentario(int id, string texto, DTFecha fechaDeRealizado)
    : id(id), texto(texto), fechaDeRealizado(fechaDeRealizado) {}

int DTComentario::getId() {
    return id;
}

string DTComentario::getTexto() {
    return texto;
}

DTFecha DTComentario::getFechaDeRealizado() {
    return fechaDeRealizado;
}

DTComentario::~DTComentario() {}

ostream& operator<<(ostream& os, DTComentario dtComentario) {
    os << "ID: " << dtComentario.getId() << ", Texto: " << dtComentario.getTexto() << ", Fecha: " << dtComentario.getFechaDeRealizado();
    return os;
}
