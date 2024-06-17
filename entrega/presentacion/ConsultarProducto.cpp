#include <iostream>
#include <set>
#include <Producto.h>
#include <ControladorProducto.h> //Hay que arreglar el directorio cuanto antes

using namespace std;


void consultarProducto() {
    ControladorProducto::listarProductos();
    int id;
    cout << "Indique el numero de Id del producto que desea ver: " << endl;
    cin >> id;

    for (auto p: productosSistema) {
        if (id == Producto::getId()) {
            cout << "Id: " << Producto::getId() << endl;
            cout << "Precio: " << Producto::getPrecio() << endl;
            cout << "Stock: " << Producto::getStock() << endl;
            cout << "Descripcion: " << Producto::getDescripcion()<< endl;
            cout << "Vendedor: " << Producto::getVendedor() << endl;
        }
    }
}