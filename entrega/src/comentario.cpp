

#include "../include/Comentario.h"
#include <string>
#include "DTFecha.h"

// Constructor
Comentario::Comentario(std::string &texto, DTFecha &fecha)
    : Texto(texto), Fecha_de_realizado(fecha) {}

// Getters
std::string Comentario::getTexto()
{
    return Texto;
}

DTFecha Comentario::getFechaDeRealizado()
{
    return Fecha_de_realizado;
}

// Setters
void Comentario::setID(int id)
{
    this->id = id;
}

void Comentario::setTexto(std::string &texto)
{
    this->Texto = texto;
}

void Comentario::setFechaDeRealizado(DTFecha &fecha)
{
    this->Fecha_de_realizado = fecha;
}
