#include "../../include/DataTypes/DTFecha.h"

/*

DTFecha::DTFecha() {
    this->dia = 1;
    this->mes = 1;
    this->anio = 1700;
}

DTFecha:: DTFecha (int d,int m,int a){
    dia=d;
    mes=m;
    anio=a;
    
}

int DTFecha::getAnio(){
    return anio;
}

int DTFecha::getDia(){
    return dia;
}


int DTFecha::getMes(){
    return mes;
}

bool DTFecha::operator>(DTFecha f){
    if(anio>f.anio) return true;
    if(anio==f.anio && mes>f.mes) return true;
    if(anio==f.anio && mes==f.mes && dia>f.dia) return true;
    return false;
}

DTFecha::~DTFecha(){}

ostream& operator<<(ostream& os, DTFecha fecha) {
    os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio();
    return os;
}

bool DTFecha::esNula(){
    return anio==1700;
}

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& os, const DTFecha& fecha) {
    os << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
    return os;
}

// Sobrecarga del operador de entrada
std::istream& operator>>(std::istream& is, DTFecha& fecha) {
    std::string input;
    std::getline(is, input);

    std::istringstream ss(input);
    std::string token;

    // Extraer el día
    std::getline(ss, token, '/');
    fecha.dia = std::stoi(token);

    // Extraer el mes
    std::getline(ss, token, '/');
    fecha.mes = std::stoi(token);

    // Extraer el año
    std::getline(ss, token);
    fecha.anio = std::stoi(token);

    return is;
}
*/

#include <sstream>

// Constructores
DTFecha::DTFecha() : dia(0), mes(0), anio(0) {}

DTFecha::DTFecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

// Métodos de acceso
int DTFecha::getDia() const { return dia; }
int DTFecha::getMes() const { return mes; }
int DTFecha::getAnio() const { return anio; }

// Operador mayor que
bool DTFecha::operator>(const DTFecha& other) const {
    if (anio > other.anio) return true;
    if (anio == other.anio && mes > other.mes) return true;
    if (anio == other.anio && mes == other.mes && dia > other.dia) return true;
    return false;
}

// Método para verificar si la fecha es nula
bool DTFecha::esNula() const {
    return dia == 0 && mes == 0 && anio == 0;
}

// Destructor
DTFecha::~DTFecha() {}

std::string DTFecha::toString() const {
    return std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio);
}

// Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& os, const DTFecha& fecha) {
    os << fecha.dia << "/" << fecha.mes << "/" << fecha.anio;
    return os;
}

// Sobrecarga del operador de entrada
std::istream& operator>>(std::istream& is, DTFecha& fecha) {
    std::string input;
    std::getline(is, input);

    std::istringstream ss(input);
    std::string token;

    // Extraer el día
    std::getline(ss, token, '/');
    fecha.dia = std::stoi(token);

    // Extraer el mes
    std::getline(ss, token, '/');
    fecha.mes = std::stoi(token);

    // Extraer el año
    std::getline(ss, token);
    fecha.anio = std::stoi(token);

    return is;
}
