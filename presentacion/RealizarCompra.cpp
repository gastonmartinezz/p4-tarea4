#include <iostream>
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Interfaces/ICProductos.h"
#include "../include/Fabrica.h"

#include <string>
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/DataTypes/DTCarro.h"
#include "../include/Producto.h"
#include "../include/Usuario.h"
#include <limits>

using std::numeric_limits;
using std::streamsize;

void RealizarCompra()
{

    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    ControladorUsuario *ctrlUsuario = Fabrica::getICUsuario();

    try
    {

        cout << " Realizar Compra" << endl;
        cout << "------------------" << endl;
        cout << endl;

        string nickname, clienteNickname;
        int iden, cantidad;

        std::vector<DTCliente> clientes = ctrlUsuario->listarClientes();
        std::cout << "Lista de Clientes:" << std::endl;
        if (clientes.size() == 0)
        {
            throw invalid_argument("No hay usuarios registrados.");
        }

        for (vector<DTCliente>::size_type i = 0; i < clientes.size(); ++i)
        {
            cout << i << "-";
            cout << clientes[i].getNickname() << endl;
        }

        std::cout << "Seleccione el nickname del cliente: ";
        std::cin >> clienteNickname;

        std::vector<DTProducto> productos = ctrlProducto->listarProductos2();
        std::cout << "Lista de Productos:" << std::endl;
        if (productos.size() == 0)
        {
            throw invalid_argument("No hay productos registrados.");
        }

        for (vector<DTProducto>::size_type i = 0; i < productos.size(); ++i)
        {
            cout << i << "-";
            cout << productos[i].getNombre() << endl;
            cout << productos[i].getId() << endl;
        }

        std::vector<DTCarro> carrito;
        bool seleccion = true;

        while (seleccion)
        {
            if (seleccion)
            {
                std::cout << "Seleccione el id del producto: ";
                std::cin >> iden;
                std::cout << "Seleccione la cantidad que quiera comprar: ";
                std::cin >> cantidad;
                carrito.push_back(DTCarro(iden, cantidad));
            }
            cout << "¿Queres seguir comprando? ";
            cin >> seleccion;
        }

        for (vector<DTCarro>::size_type i = 0; i < carrito.size(); ++i)
        {
        }
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    };
}
