#include <iostream>
#include <set>
#include "../include/Producto.h"
#include  "../include/Controladores/ControladorProducto.h"
using namespace std;

void consultarProducto() {
    ControladorProducto* controlador = ControladorProducto::getInstancia();
    controlador->listarProductos();

    int id;
    cout << "Indique el numero de Id del producto que desea ver: " << endl;
    cin >> id;

    for (int i = 0; i <= arrayProductos.size(); i++) {
        if (id == arrayProductos[i]->getId()) {
            cout << "Id: " << arrayProductos[i]->getId() << endl;
            cout << "Precio: " << arrayProductos[i]->getPrecio() << endl;
            cout << "Stock: " << arrayProductos[i]->getStock() << endl;
            cout << "Descripcion: " << arrayProductos[i]->getDescripcion()<< endl;
            //cout << "Vendedor: " << arrayProductos[i]->getVendedor() << endl;
        }
    }
}