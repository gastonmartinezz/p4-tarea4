#include <string>
#include <iostream>
#include <ctime>

struct DTFecha
{
    int dia;
    int mes;
    int año;
};
class Comentario
{
private:
    std::string Texto;
    DTFecha Fecha_de_realizado;

public:
    // Constructor
    Comentario(const std::string &texto, const DTFecha &fecha);

    // Getters
    std::string getTexto() const;
    DTFecha getFechaDeRealizado() const;

    // Setters
    void setTexto(const std::string &texto);
    void setFechaDeRealizado(const DTFecha &fecha);

    // Print method
    void printComentario() const;
};