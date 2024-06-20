#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <ctime>
#include "../include/DataTypes/DTFecha.h"
#include "Usuario.h"
using namespace std;

class Comentario
{
private:
    int id;
    string Texto;
    DTFecha Fecha_de_realizado;
    vector<Comentario *> respuestas;
    Comentario *comentarioRaiz = nullptr;
    Usuario *quienComenta;

public:
    // Constructor
    Comentario(int id, string &texto, DTFecha &fecha);
    ~Comentario();

    // Getters
    string getTexto();
    int getId();
    DTFecha getFechaDeRealizado();
    vector<Comentario *> getRespuestas();
    Comentario *getComentarioRaiz();
    Usuario *getQuienComenta();
    void imprimir(); //Falta la implementacion de este metodo, revisar

    // Setters
    void setID(int id);
    void setTexto(string &texto);
    void setFechaDeRealizado(DTFecha &fecha);
    void setRespuesta(Comentario *res);
    void setRaiz(Comentario *raiz);
    void setQuienComenta(Usuario *quien);
    // Imprime comentario y sus respuestas de forma recursiva
    map<int, Comentario *> printComentarios();
};

#endif