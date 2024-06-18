#include "../../include/DataTypes/DTUsuario.h"

DtUsuario::DtUsuario(string _nombre, string _fechaNacimiento){
    nombre = _nombre;
    FechaNacimiento = _fechaNacimiento;
}

string DtUsuario::getNombre(){
    return nombre;
}

string DtUsuario::getFechaNacimiento(){
    return FechaNacimiento;
}

DtUsuario::~DtUsuario(){}