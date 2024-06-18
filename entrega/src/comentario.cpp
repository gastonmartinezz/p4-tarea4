
#include "../include/DataTypes/DTFecha.h"
#include "../include/Comentario.h"
#include <string>

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

std::vector<Comentario *> Comentario::getRespuetas()
{
    return respuestas;
};

Comentario *Comentario::getComentarioRaiz()
{
    return comentarioRaiz;
};

Usuario *Comentario::getQuienComenta()
{
    return QuienComenta;
};

void Comentario::setRespuesta(Comentario *res)
{
    respuestas.push_back(res);
};
void Comentario::setRaiz(Comentario *raiz)
{
    comentarioRaiz = raiz;
};
void Comentario::setQuienComenta(Usuario *quien)
{

    QuienComenta = quien;
};