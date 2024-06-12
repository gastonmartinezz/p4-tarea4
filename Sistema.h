#ifndef SISTEMA_H
#define SISTEMA_H

#include <map>
#include "Usuario.h"
#include "Cliente.h"
#include "Vendedor.h"

class Sistema {
private:
    std::map<std::string, Usuario*> usuarios;

public:
    ~Sistema();
    bool existeUsuario(const std::string& nickname) const;
    bool altaUsuario(const std::string& tipoUsuario, const std::string& nickname, const std::string& password, 
                     const DTFecha& fechaDeNacimiento, const DTDireccion& direccion = {}, int codigoRut = 0);
    void mostrarUsuarios() const;
};

#endif // SISTEMA_H
