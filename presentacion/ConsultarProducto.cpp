
// #include <iostream>
// #include <set>
// #include "../include/Producto.h"
// #include  "../include/Controladores/ControladorProducto.h"
// using namespace std;

// void consultarProducto() {
//     ControladorProducto* controlador = ControladorProducto::getInstance();
//     controlador->listarProductos(); //revisar esto

//     int id;
//     cout << "Indique el numero de Id del producto que desea ver: " << endl;
//     cin >> id;

//     map<int, Producto*> lista = controlador->getListaProductos();

//     for (int i = 0; i <= lista.size(); i++) {

//         if (id == lista[i]->getId()) {
//             DTProducto producto = lista[i]->toDataType();

//             producto.setPrecio(lista[i]->getPrecio());
//             producto.setStock(lista[i]->getStock());
//             producto.setDescripcion(lista[i]->getDescripcion());

//             cout << "Nombre: " << producto.getNombre() << endl;
//             cout << "Id: " << producto.getId() << endl;
//             cout << "Precio: " << producto.getPrecio() << endl;
//             cout << "Stock: " << producto.getNombre() << endl;
//             cout << "Descripcion: " << producto.getDescripcion()<< endl;
//         }
//     }
// }