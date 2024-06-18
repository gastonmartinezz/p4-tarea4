#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include "DataTypes/DTFecha.h"
#include "Usuario.h"
class Comentario
{
private:
    int id;
    std::string Texto;
    DTFecha Fecha_de_realizado;
    std::vector<Comentario *> respuestas;
    Comentario *comentarioRaiz;
    Usuario *QuienComenta;

public:
    // Constructor
    Comentario(std::string &texto, DTFecha &fecha);

    // Getters
    std::string getTexto();
    DTFecha getFechaDeRealizado();
    std::vector<Comentario *> getRespuetas();
    Comentario *getComentarioRaiz();
    Usuario *getQuienComenta();

    // Setters
    void setID(int id);
    void setTexto(std::string &texto);
    void setFechaDeRealizado(DTFecha &fecha);
    void setRespuesta(Comentario *res);
    void setRaiz(Comentario *raiz);
    void setQuienComenta(Usuario *quien);
};

#endif