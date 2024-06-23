#include <iostream>
#include <set>
#include "../include/Producto.h"
#include  "../include/Controladores/ControladorProducto.h"
#include "../include/CasosDeUso.h"
#include "../include/Fabrica.h"
using namespace std;

void consultarProducto() {
    ControladorProducto* controlador = Fabrica::getICProductos();
    controlador->listarProductos();

    int id;
    cout << "Indique el numero de Id del producto que desea ver: " << endl;
    cin >> id;

    cout << "Hasta aca llego0" << endl;
    map<int, Producto*> lista = controlador->getListaProductos();
    cout << "Hasta aca llego1" << endl;

    Producto* prod = lista[id];
    DTProducto producto = prod->toDataType();
    
    cout << "Hasta aca llego2" << endl;

    producto.setPrecio(prod->getPrecio());
    producto.setStock(prod->getStock());
    producto.setDescripcion(prod->getDescripcion());
    cout << "Hasta aca llego3" << endl;

    cout << "Nombre: " << producto.getNombre() << endl;
    cout << "Id: " << producto.getId() << endl;
    cout << "Precio: " << producto.getPrecio() << endl;
    cout << "Stock: " << producto.getNombre() << endl;
    cout << "Descripcion: " << producto.getDescripcion()<< endl;
    //Falta agregar para que imprima el vendedor tambien
}