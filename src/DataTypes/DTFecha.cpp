#include "../../include/DataTypes/DTFecha.h"

#include <sstream>

// Constructores
DTFecha::DTFecha() : dia(0), mes(0), anio(0) {}

DTFecha::DTFecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

// Métodos de acceso
int DTFecha::getDia() const { return dia; }
int DTFecha::getMes() const { return mes; }
int DTFecha::getAnio() const { return anio; }

// Operador mayor que
bool DTFecha::operator>(const DTFecha &other) const
{
    if (anio > other.anio)
        return true;
    if (anio == other.anio && mes > other.mes)
        return true;
    if (anio == other.anio && mes == other.mes && dia > other.dia)
        return true;
    return false;
}

// Método para verificar si la fecha es nula
bool DTFecha::esNula() const
{
    return dia == 0 && mes == 0 && anio == 0;
}

// Destructor
DTFecha::~DTFecha() {}

std::string DTFecha::toString() const
{
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

void DTFecha::setDia(int dia) {
    this->dia = dia;
}
void DTFecha::setMes(int mes) {
    this->mes = mes;
}
void DTFecha::setAnio(int anio) {
    this->anio = anio;
}