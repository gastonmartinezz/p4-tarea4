#include <iostream>
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Interfaces/ICProductos.h"
#include "../include/Fabrica.h" //DEFINIR

#include <string>
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/Producto.h"
#include "../include/Usuario.h"
#include <limits>

using std::numeric_limits;
using std::streamsize;

void AltaProducto()
{

    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    ControladorUsuario *ctrlUsuario = Fabrica::getICUsuario();

    try
    {
        // Listar vendedores
        std::vector<DTVendedor> vendedores = ctrlUsuario->listaVendedor();
        std::cout << "Lista de Vendedores:" << std::endl;
        if (vendedores.size() == 0)
        {
            throw invalid_argument("No hay usuarios registrados.");
        }

        for (vector<DTVendedor>::size_type i = 0; i < vendedores.size(); ++i)
        {
            cout << i << "-";
            cout << vendedores[i].getNickname() << endl;
        }
        // Ingresar datos del producto
        std::string nombre, descripcion, vendedorNickname;
        float precio;
        int stock;
        int catInt;
        Categoria cat;

        std::cout << "Seleccione el nickname del vendedor: ";
        std::cin >> vendedorNickname;

        std::cout << "Ingrese el nombre del producto: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);

        std::cout << "Ingrese el precio del producto: ";
        std::cin >> precio;

        std::cout << "Ingrese la cantidad en stock: ";
        std::cin >> stock;

        std::cout << "Ingrese la descripción del producto: ";
        std::cin.ignore();
        std::getline(std::cin, descripcion);

        std::cout << "Seleccione la categoría del producto (0: Ropa, 1: Electrodomesticos, 2: Otros): ";
        std::cin >> catInt;
        cat = static_cast<Categoria>(catInt); // Corregido para usar Producto::Categoria
        int cont = ctrlProducto->getListaProductos().size();

        cont++;
        ctrlProducto->setContador(cont); 
        Producto *newProducto = ctrlUsuario->AddProducto(cont, stock, precio, nombre, descripcion, cat, vendedorNickname);
        ctrlProducto->agregarALaLista(cont, newProducto);        

        cout << "Producto agregado con éxito." << endl;
        cout << "ID: " << newProducto->getId() << endl;
        cout << "Nombre: " << nombre << endl;

        // // Listar productos para verificar
        // ctrlProducto->listarProductos();
    }

    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    };
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get(); // Espera que el usuario presione Enter
}