#include <string>
#include <iostream>
#include <ctime>
#include "../include/DataTypes/DTFecha.h"  
class Comentario
{
private:
    int id;
    std::string Texto;
     Fecha_de_realizado;

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