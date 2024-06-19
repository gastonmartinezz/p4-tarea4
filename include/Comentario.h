#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <ctime>
#include "../include/DataTypes/DTFecha.h"
#include "Usuario.h"
class Comentario
{
private:
    int id;
    std::string Texto;
    DTFecha Fecha_de_realizado;
    std::vector<Comentario *> respuestas;
    Comentario *comentarioRaiz = nullptr;
    Usuario *quienComenta;

public:
    // Constructor
    Comentario(int id, std::string &texto, DTFecha &fecha);

    // Getters
    std::string getTexto();
    int getId();
    DTFecha getFechaDeRealizado();
    std::vector<Comentario *> getRespuestas();
    Comentario *getComentarioRaiz();
    Usuario *getQuienComenta();
    void imprimir();

    // Setters
    void setID(int id);
    void setTexto(std::string &texto);
    void setFechaDeRealizado(DTFecha &fecha);
    void setRespuesta(Comentario *res);
    void setRaiz(Comentario *raiz);
    void setQuienComenta(Usuario *quien);
    // Imprime comentario y sus respuestas de forma recursiva
    std::map<int, Comentario *> printComentarios();
};

#endif