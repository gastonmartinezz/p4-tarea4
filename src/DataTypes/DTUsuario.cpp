#include "../../include/DataTypes/DTUsuario.h"

DTUsuario::DTUsuario(string _nombre, DTFecha _fechaNacimiento, string password) {
    nickname = _nombre;
    fechaNacimiento = _fechaNacimiento;
}

string DTUsuario::getNombre(){
    return nickname;
}

DTFecha DTUsuario::getFechaNacimiento(){
    return fechaNacimiento;
}

DTUsuario::~DTUsuario(){}