#include <iostream>
#include <set>
#include "../include/Producto.h"
#include  "../include/Controladores/ControladorProducto.h"
#include "../include/CasosDeUso.h"
#include "../include/Fabrica.h"
#include <limits>
using namespace std;

void consultarProducto() {
    ControladorProducto* controlador = Fabrica::getICProductos();
    controlador->listarProductos();

    try {
        int id;
        cout << "Indique el numero de Id del producto que desea ver: " << endl;
        cin >> id;

        map<int, Producto*> lista = controlador->getListaProductos();

        Producto* prod = lista[id];
        DTProducto producto = prod->toDataType();
        
        producto.setPrecio(prod->getPrecio());
        producto.setStock(prod->getStock());
        producto.setDescripcion(prod->getDescripcion());

        cout << "Nombre: " << producto.getNombre() << endl;
        cout << "Id: " << producto.getId() << endl;
        cout << "Precio: " << producto.getPrecio() << endl;
        cout << "Stock: " << producto.getNombre() << endl;
        cout << "Descripcion: " << producto.getDescripcion()<< endl;
        //Falta agregar para que imprima el vendedor tambien
    } catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get();
}