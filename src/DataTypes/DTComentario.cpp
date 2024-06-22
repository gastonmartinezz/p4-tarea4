#include "DTComentario.h"
#include "DTFecha.h"

DTComentario::DTComentario(int id, string texto, DTFecha fechaDeRealizado)
    : id(id), texto(texto), fechaDeRealizado(fechaDeRealizado) {}

int DTComentario::getId()
{
    return id;
}

string DTComentario::getTexto()
{
    return texto;
}

DTFecha DTComentario::getFechaDeRealizado()
{
    return fechaDeRealizado;
}

DTComentario::~DTComentario() {}

ostream &operator<<(ostream &os, DTComentario dtComentario)
{
    DTFecha fecha = dtComentario.getFechaDeRealizado();
    os << "ID: " << dtComentario.getId() << ", Texto: " << dtComentario.getTexto() << ", Fecha: " << fecha.toString();
    return os;
}
