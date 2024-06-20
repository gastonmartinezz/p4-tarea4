#include "../../include/DataTypes/DTFecha.h"

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