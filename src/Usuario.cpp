#include "../include/Usuario.h"

Usuario::Usuario(const string &nickname, const string &password, const DTFecha &fechaDeNacimiento)
    : nickname(nickname), password(password), fechaDeNacimiento(fechaDeNacimiento) {}

string Usuario::getNickname()
{
    return nickname;
}

string Usuario::getPassword()
{
    return password;
}

DTFecha Usuario::getFechaDeNacimiento()
{
    return fechaDeNacimiento;
}

void Usuario::setNickname(string &nickname)
{
    this->nickname = nickname;
}

void Usuario::setPassword(string &password)
{
    this->password = password;
}

void Usuario::setFechaDeNacimiento(DTFecha &fechaDeNacimiento)
{
    this->fechaDeNacimiento = fechaDeNacimiento;
}

DTUsuario Usuario::toDataType()
{
    return DTUsuario(getNickname(), getFechaDeNacimiento());
};

void Usuario::addComentario(Comentario *coment)
{
    ListaComentarios[coment->getId()] = coment;
}

vector<Comentario *> Usuario::listarComentarios()
{
    vector<Comentario *> comentarios;
    for (const auto &pair : ListaComentarios)
    {
        comentarios.push_back(pair.second);
    }
    return comentarios;
}

Usuario::~Usuario() {}
