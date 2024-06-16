#include <iostream>
#include <set>
#include <Producto.h>
#include <ControladorProducto.h> //Hay que arreglar el directorio cuanto antes

using namespace std;

set<Producto *> productosSistemas; //Set donde guardamos todos los productos del sistema, ordenados por ID (Codigo identificador)

void consultarProducto() {
    listarProductos();
    int id;
    cout << "Indique el numero de Id del producto que desea ver: " << endl;
    cin >> id;

    for (auto p: productosSistemas) {
        if (id == getId()) {
            cout << "Precio: " << getPrecio() << endl;
            cout << "Stock: " << getStock() << endl;
            cout << "Descripcion: " << getDescripcion()<< endl;
            cout << "Vendedor: " << getVendedor() << endl;
        }
    }
}