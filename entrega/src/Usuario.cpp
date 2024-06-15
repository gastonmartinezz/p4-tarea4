#include "../include/Usuario.h"

Usuario::Usuario(const std::string& nickname, const std::string& password, const DTFecha& fechaDeNacimiento)
    : nickname(nickname), password(password), fechaDeNacimiento(fechaDeNacimiento) {}

std::string Usuario::getNickname() const {
    return nickname;
}

std::string Usuario::getPassword() const {
    return password;
}

DTFecha Usuario::getFechaDeNacimiento() const {
    return fechaDeNacimiento;
}

void Usuario::setNickname(const std::string& nickname) {
    this->nickname = nickname;
}

void Usuario::setPassword(const std::string& password) {
    this->password = password;
}

void Usuario::setFechaDeNacimiento(const DTFecha& fechaDeNacimiento) {
    this->fechaDeNacimiento = fechaDeNacimiento;
}
