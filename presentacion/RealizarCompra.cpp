

 #include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Interfaces/ICProductos.h"
#include "../include/Fabrica.h"
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/DataTypes/DTCarro.h"
#include "../include/Producto.h"
#include "../include/Usuario.h"
#include <bits/stdc++.h>

using namespace std;

void RealizarCompra() {

    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    ControladorUsuario *ctrlUsuario = Fabrica::getICUsuario();

    try {

        cout << " Realizar Compra" << endl;
        cout << "------------------" << endl;
        cout << endl;

        string nickname, clienteNickname;
        int iden, cantidad;

        vector<DTCliente> clientes = ctrlUsuario->listarClientes();
        cout << "Lista de Clientes:" << endl;
        if (clientes.size() == 0) {
            throw invalid_argument("No hay usuarios registrados.");
        }

        for (vector<DTCliente>::size_type i = 0; i < clientes.size(); ++i) {
            cout << i << "-";
            cout << clientes[i].getNickname() << endl;
        }

        cout << "Seleccione el nickname del cliente: ";
        cin >> clienteNickname;

        vector<DTProducto> productos = ctrlProducto->listarProductos2();
        cout << "Lista de Productos:" << endl;
        if (productos.size() == 0) {
            throw invalid_argument("No hay productos registrados.");
        }

        for (vector<DTProducto>::size_type i = 0; i < productos.size(); ++i) {
            cout << i << "-";
            cout << productos[i].getNombre() << endl;
            cout << productos[i].getId() << endl;
        }

        vector<DTCarro> carrito;

        string respuesta;

        cout << "Deseas agregar un producto a la compra? (si/no)" << endl;
        cin >> respuesta;

        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

        if (respuesta == "SI" || respuesta == "S") { 
            cout << "Ingrese el Id del producto que desea agregar a carrito: " << endl;
            cin >> iden;
            if (cin.fail()) {
                throw invalid_argument("Error: Entrada no válida para el Id del producto.");
            }

            cout << "Ingrese una catidad: " << endl;
            cin >> cantidad;
            if (cin.fail()) {
                throw invalid_argument("Error: Entrada no válida para la cantidad.");
            }

        carrito.push_back(DTCarro(iden, cantidad));


        } else if (respuesta == "NO" || respuesta == "N") {
            cout << "No se van a agregar productos al carrito." << endl;
            cout << "Presiona Enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return;
        }

        cout << "Desea agregar otro producto al carrito? (si/no)" << endl;
        cin >> respuesta;
        
        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);
        
        bool seguir = true;
        if (!((respuesta == "SI") || (respuesta == "S"))) {
            seguir = false;
            cout << "No se van a agregar más productos al carrito." << endl;
            cout << "-------------------------------------------------" << endl;
        }

        while (seguir) {
            cout << "Ingrese el Id del producto que desea agregar al carrito: " << endl;
            cin >> iden;
            
            cout << "Ingrese la cantidad que desea comprar: " << endl;
            cin >> cantidad;

            carrito.push_back(DTCarro(iden, cantidad));

            cout << "Desea agregar otro producto al carrito? (si/no)" << endl;
            cin >> respuesta;
    

            transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

            if (!((respuesta == "SI") || (respuesta == "S"))) {
                seguir = false;
            }
        }


        for (size_t i = 0; i < carrito.size(); ++i) {
                cout << "Producto ID: " << carrito[i].getProd() 
                << ", Cantidad: " << carrito[i].getCantidad() << endl;
            }


        float montoTotal = 0.00;
        float suma = 0.00;
        vector<DTCarro> carrito_copia = carrito;
        vector<DTCarro> aux;
        vector<Promocion*> promociones;
        size_t i = 0;

        Vendedor* vendedor = ctrlProducto->getProducto(carrito_copia[0].getProd())->getVendedor();
        while (!carrito_copia.empty() || !aux.empty()) {
            if (vendedor == ctrlProducto->getProducto(carrito_copia[i].getProd())->getVendedor()) {
                aux.push_back(carrito_copia[i]);
                carrito_copia.erase(carrito_copia.begin() + i);
                i = i - 1;
            }
            if (!carrito_copia.empty() && i < carrito_copia.size() - 1) {
                i++;
            } else {
                i = 0;
                promociones = vendedor->getPromociones();
                for (vector<Promocion*>::size_type k = 0; k < promociones.size(); ++k) {
                    if (ctrlProducto->compararFechas(promociones[k]->getFechaVencimiento(), ctrlProducto->getFecha())) {
                        suma = 0.00;
                        size_t h = 0;
                        size_t j = 0;
                        while (h < aux.size()) {
                            for (vector<Contenido*>::size_type l = 0; l < promociones[k]->getProductosDentroDePromo().size(); ++l) {
                                if (promociones[k]->getProductosDentroDePromo()[l]->getProducto()->getId() == aux[h].getProd()) {
                                    if (promociones[k]->getProductosDentroDePromo()[l]->getCantMinima() == aux[h].getCantidad()) {
                                        suma += aux[h].getCantidad() * promociones[k]->getProductosDentroDePromo()[l]->getProducto()->getPrecio();
                                        j++;
                                        aux.erase(aux.begin() + h);
                                        h--;
                                    } else {
                                        suma += aux[h].getCantidad() * promociones[k]->getProductosDentroDePromo()[l]->getProducto()->getPrecio();
                                    }
                                    if (promociones[k]->getProductosDentroDePromo().size() == j) {
                                        suma = suma / promociones[k]->getDescuento();
                                        j = 0;
                                    }
                                }
                            }
                            h++;
                        }
                        montoTotal += suma;
                    }
                }
                auto it = aux.begin();
                while (it != aux.end()) {
                    montoTotal += (it->getCantidad() * ctrlProducto->getProducto(it->getProd())->getPrecio());
                    it = aux.erase(it);
                }

                if (!carrito_copia.empty()) {
                    vendedor = ctrlProducto->getProducto(carrito_copia[0].getProd())->getVendedor();
                }
            }
        }


        std::cout << "El monto total de la compra es: " << montoTotal << std::endl;


    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get();
} 









