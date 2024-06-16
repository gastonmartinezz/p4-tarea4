#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <iostream>
#include <ctime>
#include "DataTypes/DTFecha.h"
class Comentario
{
private:
    int id;
    std::string Texto;
    DTFecha Fecha_de_realizado;

public:
    // Constructor
    Comentario(std::string &texto, DTFecha &fecha);

    // Getters
    std::string getTexto();
    DTFecha getFechaDeRealizado();

    // Setters
    void setID(int id);
    void setTexto(std::string &texto);
    void setFechaDeRealizado(DTFecha &fecha);
};

#endif