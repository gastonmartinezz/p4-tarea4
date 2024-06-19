#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include  "../include/DataTypes/DTUsuario.h"
 
class Usuario
{
protected:
    std::string nickname;
    std::string password;
    DTFecha fechaDeNacimiento;

public:
    Usuario(const std::string &nickname, const std::string &password, const DTFecha &fechaDeNacimiento);

    std::string getNickname() const;
    std::string getPassword() const;
    DTFecha getFechaDeNacimiento() const;

    void setNickname(const std::string &nickname);
    void setPassword(const std::string &password);
    void setFechaDeNacimiento(const DTFecha &fechaDeNacimiento);
    DTUsuario toDataType();




    virtual ~Usuario() = default;
    void mostrarInformacion() const; 
};

#endif // USUARIO_H
