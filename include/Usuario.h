#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include "../include/DataTypes/DTUsuario.h"
#include "Comentario.h"

class Comentario;

using namespace std;

class Usuario
{
protected:
    string nickname;
    string password;
    DTFecha fechaDeNacimiento;
    map<int, Comentario *> ListaComentarios;

public:
    Usuario(const string &nickname, const string &password, const DTFecha &fechaDeNacimiento);

    string getNickname();
    string getPassword();
    DTFecha getFechaDeNacimiento();

    void setNickname(string &nickname);
    void setPassword(string &password);
    void setFechaDeNacimiento(DTFecha &fechaDeNacimiento);
    DTUsuario toDataType();
    void addComentario(Comentario *coment);
    vector<Comentario *> listarComentarios();
    ~Usuario();
};

#endif // USUARIO_H
