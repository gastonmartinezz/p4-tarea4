

#include <iostream>
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Fabrica.h"
#include "../include/CasosDeUso.h"
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

#include <limits>

using std::numeric_limits;
using std::streamsize;
using namespace std;

void cargaDatosDePrueba()
{
    cout << endl;
    cout << " Datos de prueba" << endl;
    cout << "----------------" << endl;
    cout << endl;

    ICUsuario *ctrlUsuario = Fabrica::getICUsuario();
    ctrlUsuario->cargarDatosPrueba();
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get();
}

void AltaProductoTest()
{
    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    ControladorUsuario *ctrlUsuario = Fabrica::getICUsuario();

    struct ProductoInfo
    {
        std::string nombre;
        std::string descripcion;
        float precio;
        int stock;
        Categoria categoria;
        std::string vendedorRef;
    };

    std::vector<ProductoInfo> productos = {
        {"Camiseta Azul", "Camiseta de poliester, color azul", 1400, 50, static_cast<Categoria>(0), "carlos78"},
        {"Televisor LED", "Televisor LED 55 pulgadas", 40500, 30, static_cast<Categoria>(1), "ana23"},
        {"Chaqueta de Cuero", "Chaqueta de cuero, color negro", 699.99, 20, static_cast<Categoria>(0), "carlos78"},
        // Añade más productos según la tabla
    };

    try
    {
        for (auto &producto : productos)
        {

            int cont = ctrlProducto->getListaProductos().size() + 1;
            Producto *nuevoProducto = ctrlUsuario->AddProducto(cont, producto.stock, producto.precio, producto.nombre, producto.descripcion, producto.categoria, producto.vendedorRef);
            ctrlProducto->agregarALaLista(cont, nuevoProducto);

            std::cout << "Producto agregado con éxito." << std::endl;
            std::cout << "ID: " << nuevoProducto->getId() << std::endl;
            std::cout << "Nombre: " << producto.nombre << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Presiona Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Espera que el usuario presione Enter
}
