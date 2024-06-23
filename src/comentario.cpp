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

int Comentario::getId()
{
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

map<int, Comentario *> Comentario::printComentarios()
{
    map<int, Comentario *> comentariosMap;
    comentariosMap[id] = this;
    cout << this->getId() << endl;
    cout << this->getTexto() << endl;
    for (Comentario *respuesta : respuestas)
    {
        map<int, Comentario *> subComentarios = respuesta->printComentarios();
        comentariosMap.insert(subComentarios.begin(), subComentarios.end());
    }

    return comentariosMap;
}
