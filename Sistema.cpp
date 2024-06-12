#include "Sistema.h"
#include <iostream>

Sistema::~Sistema() {
    for (auto& [nickname, usuario] : usuarios) {
        delete usuario;
    }
}

bool Sistema::existeUsuario(const std::string& nickname) const {
    return usuarios.find(nickname) != usuarios.end();
}

bool Sistema::altaUsuario(const std::string& tipoUsuario, const std::string& nickname, const std::string& password, 
                          const DTFecha& fechaDeNacimiento, const DTDireccion& direccion, int codigoRut) {
    if (existeUsuario(nickname)) {
        std::cout << "Error: Usuario con nickname " << nickname << " ya existe.\n";
        return false;
    }

    if (password.length() < 6) {
        std::cout << "Error: La contraseña debe tener al menos 6 caracteres.\n";
        return false;
    }

    Usuario* nuevoUsuario = nullptr;
    if (tipoUsuario == "cliente") {
        nuevoUsuario = new Cliente(nickname, password, fechaDeNacimiento, direccion);
    } else if (tipoUsuario == "vendedor") {
        if (std::to_string(codigoRut).length() != 12) {
            std::cout << "Error: El codigo RUT debe tener 12 caracteres.\n";
            return false;
        }
        nuevoUsuario = new Vendedor(nickname, password, fechaDeNacimiento, codigoRut);
    } else {
        std::cout << "Error: Tipo de usuario no válido.\n";
        return false;
    }

    usuarios[nickname] = nuevoUsuario;
    std::cout << "Usuario " << nickname << " dado de alta exitosamente.\n";
    return true;
}

void Sistema::mostrarUsuarios() const {
    for (const auto& [nickname, usuario] : usuarios) {
        usuario->mostrarInformacion();
    }
}
