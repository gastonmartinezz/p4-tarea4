#include "controladorUsuario.h"
#include <iostream>

// Agregar un usuario
void UsuarioController::addUser(Usuario *user)
{
    if (users.find(user->getNickname()) == users.end())
    {
        users[user->getNickname()] = user;
        std::cout << "Usuario " << user->getNickname() << " agregado exitosamente." << std::endl;
    }
    else
    {
        std::cout << "El usuario con nickname " << user->getNickname() << " ya existe." << std::endl;
    }
}

// Eliminar un usuario por su nickname
void UsuarioController::eliminarUser(std::string &nickname)
{
}

// Encontrar un usuario por su nickname
Usuario *UsuarioController::find(std::string nickname)
{
    auto it = users.find(nickname);
    if (it != users.end())
    {
        return it->second;
    }
    std::cout << "El usuario con nickname " << nickname << " no existe." << std::endl;
    return nullptr;
}
