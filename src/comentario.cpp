#include "../include/DataTypes/DTFecha.h"
#include "../include/Comentario.h"
#include <string>
#include <map>
#include <functional>

// Constructor
Comentario::Comentario(int id, string &texto, DTFecha &fecha)
    : id(id), Texto(texto), Fecha_de_realizado(fecha) {}

Comentario::~Comentario() {}

// Getters

int Comentario::getId() {
    return id;
}

string Comentario::getTexto()
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

vector<Comentario *> Comentario::getRespuestas()
{
    return respuestas;
};

Comentario *Comentario::getComentarioRaiz()
{
    return comentarioRaiz;
};

Usuario *Comentario::getQuienComenta()
{
    return quienComenta;
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

    quienComenta = quien;
};

map<int, Comentario *> printComentarios()
{
    map<int, Comentario *> comentariosMap;

    // Función lambda recursiva para imprimir y llenar el map de comentarios
    function<void(Comentario *)> imprimirYAgregar = [&](Comentario *comentario)
    {
        if (comentario)
        {
            comentario->imprimir();
            comentariosMap[comentario->getId()] = comentario;

            // Recorrer respuestas recursivamente
            for (Comentario *respuesta : comentario->getRespuestas())
            {
                imprimirYAgregar(respuesta);
            }
        }
    };

    // Iniciar la impresión y llenado del mapa desde el comentario actual
    // imprimirYAgregar(this);

    return comentariosMap;
}
