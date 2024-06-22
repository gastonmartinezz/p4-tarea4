
#include <iostream>
#include "../include/Fabrica.h"
#include "../include/Usuario.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Controladores/ControladorUsuario.h"

void listaUsuarios(){}

/*
{  
    cout << " Consulta de Usuario" << endl;
    cout << "---------------------" << endl;
    cout << endl;

    
    ICUsuario *CtrlUsuario = Fabrica::getICUsuario();

try
    {
        int comentario_respondido;
        vector<DTUsuario>::size_type i_usuario;

        vector<DTUsuario> usuarios = CUsuario->listarUsuarios();

        cout << " Usuarios" << endl;
        cout << "___________________" << endl;
        cout << endl;

        if (usuarios.size() == 0)
        {
            throw invalid_argument("No hay usuarios registrados.");
        }
        for (vector<DTUsuario>::size_type i = 0; i < usuarios.size(); ++i)
        {
            cout << i << "-";
            cout << usuarios[i].getNombre() << endl;
        }





    std::vector<Usuario *> usuarios = ctrlUsuario->listarUsuarios();

    for (Usuario *usuario : usuarios)
    {
        std::cout << "Nickname: " << usuario->getNickname() << std::endl;
        std::cout << "Fecha de Nacimiento: " << usuario->getFechaDeNacimiento().toString() << std::endl;

        Cliente *cliente = dynamic_cast<Cliente *>(usuario);
        if (cliente)
        {
            std::cout << "Direccion: " << cliente->getDireccion() << std::endl;
            std::cout << "Ciudad: " << cliente->getCiudadResidencia() << std::endl;
        }

        Vendedor *vendedor = dynamic_cast<Vendedor *>(usuario);
        if (vendedor)
        {
            std::cout << "Codigo RUT: " << vendedor->getRut() << std::endl;
        }

        std::cout << "----------------------------" << std::endl;
    }
}
 
*/

