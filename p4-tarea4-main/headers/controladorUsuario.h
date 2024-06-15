#include "Usuario.h"
#include <map>
#include <string>
#include <vector>

class UsuarioController
{
private:
    std::map<std::string, Usuario *> users;

public:
    // Agregar un usuario
    void addUser(Usuario *user);

    // Eliminar un usuario por su nickname
    void eliminarUser(std::string &nickname);

    // Encontrar un usuario por su nickname
    Usuario *find(std::string nickname);

    std::vector<Usuario *> listarUsuarios();
};
