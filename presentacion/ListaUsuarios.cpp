
#include <iostream>
#include "../include/Fabrica.h"
#include "../include/Usuario.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Controladores/ControladorUsuario.h"

#include <limits>

using std::numeric_limits;
using std::streamsize;

void listaUsuarios()
{
    cout << " Listar Usuarios" << endl;
    cout << "---------------------" << endl;
    cout << endl;

    ICUsuario *CUsuario = Fabrica::getICUsuario();

    try
    {
        vector<DTCliente> clientes = CUsuario->listarClientes();

        cout << " Clientes" << endl;
        cout << "___________________" << endl;
        cout << endl;

        if (clientes.size() == 0)
        {
            cout << "No hay clientes registrados." << endl;
        }
        for (vector<DTUsuario>::size_type i = 0; i < clientes.size(); ++i)
        {
            cout << i << "-";
            cout << clientes[i].getNickname() << endl;
        }
        vector<DTVendedor> vendedores = CUsuario->listaVendedor();

        cout << "       " << endl;
        cout << " Vendedores" << endl;
        cout << "___________________" << endl;
        cout << endl;

        if (vendedores.size() == 0)
        {
            throw invalid_argument("No hay vendedores registrados.");
        }
        for (vector<DTUsuario>::size_type i = 0; i < vendedores.size(); ++i)
        {
            cout << i << "-";
            cout << vendedores[i].getNickname() << endl;
        }
    }

    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    };
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get(); // Espera que el usuario presione Enter
}
