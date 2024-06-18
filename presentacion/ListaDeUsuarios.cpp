/* #include <iostream>
#include "../include/Fabrica.h"
#include "../include/Usuario.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
#include "../include/Controladores/ControladorUsuario.h"

void listarUsuarios()
{
    ICUsuario *controladorUsuario = Fabrica::getICUsuario();
    std::vector<Usuario *> usuarios = controladorUsuario->listarUsuarios();

    for (Usuario *usuario : usuarios)
    {
        std::cout << "Nickname: " << usuario->getNickname() << std::endl;
        std::cout << "Fecha de Nacimiento: " << usuario->getFechaDeNacimiento().toString() << std::endl;

        Cliente *cliente = dynamic_cast<Cliente *>(usuario);
        if (cliente)
        {
            std::cout << "Direccion: " << cliente->getDireccion() << std::endl;
            std::cout << "Ciudad: " << cliente->getCiudad() << std::endl;
        }

        Vendedor *vendedor = dynamic_cast<Vendedor *>(usuario);
        if (vendedor)
        {
            std::cout << "Codigo RUT: " << vendedor->getCodigoRUT() << std::endl;
        }

        std::cout << "----------------------------" << std::endl;
    }
}
 */