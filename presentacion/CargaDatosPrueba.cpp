

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
    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    ctrlProducto->cargarDatosPromocion();
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
        {"Microondas Digital", "Microondas digital, 30L", 1199.99, 15, static_cast<Categoria>(1), "ana23"},
        {"Luz LED", "Luz Bluetooth LED", 599.99, 40, static_cast<Categoria>(2), "diegom"},
        {"Pantalones Vaqueros", "Pantalones vaqueros, talla 32", 60, 25, static_cast<Categoria>(0), "carlos78"},
        {"Auriculares Bluetooth", "Auriculares bluethooth para celular", 199.99, 35, static_cast<Categoria>(2), "diegom"},
        {"Refrigerador", "Refrigerador de doble puerta", 15499, 10, static_cast<Categoria>(1), "ana23"},
        {"Cafetera", "Cafetera de goteo programable", 23000, 50, static_cast<Categoria>(1), "ana23"},
        {"Zapatillas Deportivas", "Zapatillas para correr, talla 42", 5500, 20, static_cast<Categoria>(0), "carlos78"},
        {"Mochila", "Mochila de viaje, 40L", 9000, 30, static_cast<Categoria>(2), "carlos78"},
        {"Plancha de Ropa", "Plancha a vapor, 1500W", 2534, 25, static_cast<Categoria>(1), "diegom"},
        {"Gorra", "Gorra para deportes, color rojo", 200, 50, static_cast<Categoria>(0), "sofia25"},
        {"Tablet", "Tablet Android de 10 pulgadas", 15000, 15, static_cast<Categoria>(1), "diegom"},
        {"Reloj de Pared", "Reloj de pared vintage", 150.50, 20, static_cast<Categoria>(2), "sofia25"}
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
