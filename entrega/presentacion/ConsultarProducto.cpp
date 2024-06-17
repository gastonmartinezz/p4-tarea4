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
        if (id == p->getId()) {
            cout << "Id: " << p->getId() << endl;
            cout << "Precio: " << p->getPrecio() << endl;
            cout << "Stock: " << p->getStock() << endl;
            cout << "Descripcion: " << p->getDescripcion()<< endl;
            cout << "Vendedor: " << p->getVendedor() << endl;
        }
    }
}
