#include "Comentario.h"

DTFecha crearFechas(int dia, int mes, int anio)
{
    DTFecha fecha;
    fecha.dia = dia;
    fecha.mes = mes;
    fecha.año = anio;

    return fecha;
}
// Constructor
Comentario::Comentario(const std::string &texto, const DTFecha &fecha)
    : Texto(texto), Fecha_de_realizado(fecha) {}

// Getters
std::string Comentario::getTexto() const
{
    return Texto;
}

std::string Comentario::getFechaDeRealizado() const
{
    return Fecha_de_realizado.toString();
}

// Setters
void Comentario::setTexto(const std::string &texto)
{
    Texto = texto;
}

void Comentario::setFechaDeRealizado(const DTFecha &fecha)
{
    Fecha_de_realizado = fecha;
}
