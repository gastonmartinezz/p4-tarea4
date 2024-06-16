#include "../../include/DataTypes/DtFecha.h"

DtFecha::DtFecha() {
    this->dia = 1;
    this->mes = 1;
    this->anio = 1700;
}

DtFecha:: DtFecha (int d,int m,int a){
    dia=d;
    mes=m;
    anio=a;
    
}

int DtFecha::getAnio(){
    return anio;
}
 DTFecha
int DtFecha::getDia(){
    return dia;
}


int DtFecha::getMes(){
    return mes;
}

bool DtFecha::operator>(DtFecha f){
    if(anio>f.anio) return true;
    if(anio==f.anio && mes>f.mes) return true;
    if(anio==f.anio && mes==f.mes && dia>f.dia) return true;
    return false;
}

DtFecha::~DtFecha(){}

ostream& operator<<(ostream& os, DtFecha fecha) {
    os << fecha.getDia() << "/" << fecha.getMes() << "/" << fecha.getAnio();
    return os;
}

bool DtFecha::esNula(){
    return anio==1700;
}