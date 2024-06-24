#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include <limits>
#include "../include/Promocion.h"
#include "../include/contenido.h"
#include "../include/Vendedor.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/Fabrica.h"
#include "../include/CasosDeUso.h"
#include "../include/DataTypes/DTContenido.h"
#include <bits/stdc++.h>
using namespace std;

void crearPromocion() {
    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    ControladorUsuario *ctrlUsuario = Fabrica::getICUsuario();

    cout << "Inicio de crearPromocion" << endl;
    try {
        string nombre, desc;
        float descuento;
        int dia, mes, anio;
        DTFecha fechaVencimiento;

        cout << "Ingresa el nombre de la promoción: " << endl;
        cin >> nombre;
        if (cin.fail()) {
            cerr << "Error: Entrada no válida para nombre" << endl;
            return;
        }

        cout << "Ingrese la descripción de la promoción: " << endl;
        cin >> desc;
        if (cin.fail()) {
            cerr << "Error: Entrada no válida para la descripción." << endl;
            return;
        }

        cout << "Ingrese el descuento de la promoción: " << endl;
        cin >> descuento;
        if (cin.fail()) {
            cerr << "Error: Entrada no válida para el descuento." << endl;
            return;
        }

        cout << "Ingrese el dia de la fecha de vencimiento: " << endl;
        cin >> dia;
        while (cin.fail() || dia < 1 || dia > 31) {
            cerr << "Error: Entrada no válida para el dia de la fecha de vencimiento." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Día inválido. Por favor, ingrese un día entre 1 y 31: ";
            cin >> dia;
        }

        cout << "Ingrese el numero de mes de la fecha de vencimiento: " << endl;
        cin >> mes;
        while (cin.fail() || mes < 1 || mes > 12) {
            cerr << "Error: Entrada no válida para el mes de la fecha de vencimiento." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mes inválido. Por favor, ingrese un mes entre 1 y 12: ";
            cin >> mes;
        }

        cout << "Ingrese el año de la fecha de vencimiento: " << endl;
        cin >> anio;
        while (cin.fail() || anio < 1900 || anio > 2100) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Año inválido. Por favor, ingrese un año razonable: ";
            cin >> anio;
        }

        fechaVencimiento = DTFecha(dia, mes, anio);

        // Muestro los datos de los vendedores para que el administrador elija uno con el nickname.
        vector<DTVendedor> vendedores = ctrlUsuario->listaVendedor();
        cout << "Lista de Vendedores:" << endl;
        if (vendedores.empty()) {
            throw invalid_argument("No hay usuarios registrados.");
        }

        for (vector<DTVendedor>::size_type i = 0; i < vendedores.size(); i++) {
            cout << i << "-";
            cout << vendedores[i].getNickname() << endl;
        }
        
        // El usuario selecciona un vendedor de la lista por su nickname.
        string nickVendedor;
        cout << "Ingrese el nickname del vendedor para asignarle la promoción: " << endl;
        cin >> nickVendedor;

        //Guardo el objeto del vendedor para asignarle a la promocion luego.
        Vendedor* vendedorPromocion = ctrlUsuario->findVendedor(nickVendedor);
        if (!vendedorPromocion) {
            throw invalid_argument("Error: Vendedor no encontrado.");
        }

        // Invoco la función para ir agregando los productos a la promoción.
        ctrlProducto->listarProductosVendedor(nickVendedor, ctrlUsuario->listaVendedor());

        
        string respuesta;
        int idProducto;
        int cantMin;
        vector<Contenido *> productosPromocion; //Vector de Contenido para ir guardando los productos a la Promoción

        cout << "Deseas agregar un producto a la promoción? (si/no)" << endl;
        cin >> respuesta;
        /* while(cin.fail() || respuesta != "SI" || respuesta != "S" || respuesta != "NO" || respuesta != "N") {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Respuesta inválida, indique solamente si/no." << endl;
            cin >> respuesta;
        } */

        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

        if (respuesta == "SI" || respuesta == "S") { 
            cout << "Ingrese el Id del producto que desea agregar a la promoción: " << endl;
            cin >> idProducto;
            if (cin.fail()) {
                throw invalid_argument("Error: Entrada no válida para el Id del producto.");
            }

            cout << "Ingrese la cantidad mínima de ese producto para que la promoción sea válida: " << endl;
            cin >> cantMin;
            if (cin.fail()) {
                throw invalid_argument("Error: Entrada no válida para la cantidad mínima.");
            }

            //Revisando si el producto ya pertenece a una promocion
            if (!(ctrlProducto->productoEnPromoExistente(idProducto))) {
                Contenido* contenido = new Contenido(ctrlProducto->getProducto(idProducto),cantMin);
                productosPromocion.push_back(contenido);

            } else { cout << "Este producto no se puede agregar a la promoción ya que ya pertenece a otra promoción vigente." << endl; }

        } else if (respuesta == "NO" || respuesta == "N") {
            cout << "No se van a agregar productos a la promoción." << endl;
            cout << "Presiona Enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return;
        }

        cout << "Desea agregar otro producto a la promoción? (si/no)" << endl;
        cin >> respuesta;
        /* while(cin.fail() || respuesta != "SI" || respuesta != "S" || respuesta != "NO" || respuesta != "N") {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Respuesta inválida, indique solamente si/no." << endl;
            cin >> respuesta;
        } */
        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);
        
        //Mecanismo para ir agregando productos a la promoción
        bool seguir = true;
        if (!((respuesta == "SI") || (respuesta == "S"))) {
            seguir = false;
            cout << "No se van a agregar más productos a la promoción." << endl;
            cout << "-------------------------------------------------" << endl;
        }

        while (seguir) {
            ctrlProducto->listarProductosVendedor(nickVendedor, ctrlUsuario->listaVendedor());
            cout << "Ingrese el Id del producto que desea agregar a la promoción: " << endl;
            cin >> idProducto;
            
            cout << "Ingrese la cantidad mínima de ese producto para que la promoción sea válida: " << endl;
            cin >> cantMin;
            
            bool existeProductoEnPromo = ctrlProducto->productoEnPromoExistente(idProducto);

            if (!(existeProductoEnPromo)) {
                Contenido* contenido = new Contenido(ctrlProducto->getProducto(idProducto),cantMin);
                productosPromocion.push_back(contenido);
            } else {
                cout << "Este producto no se puede agregar a la promoción ya que ya pertenece a otra promoción vigente." << endl;
            }
            
            cout << "Desea agregar otro producto a la promoción? (si/no)" << endl;
            cin >> respuesta;
            /* if (cin.fail() || respuesta != "SI" || respuesta != "S" || respuesta != "NO" || respuesta != "N") {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Respuesta inválida, indique solamente si/no." << endl;
                cin >> respuesta;
            } */

            transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

            if (!((respuesta == "SI") || (respuesta == "S"))) {
                seguir = false;
            }
        }

        Promocion *promoNueva = new Promocion(descuento,nombre,desc,fechaVencimiento);
        promoNueva->setProductosDentroDePromo(productosPromocion);
        promoNueva->setVendedor(vendedorPromocion);

        vector<Promocion*> promocionesVigentes = ctrlProducto->getpromocionesSistemaVigentes();
        vector<Promocion*> promocionesTotales = ctrlProducto->getpromocionesSistema();

        promocionesVigentes.push_back(promoNueva);
        promocionesTotales.push_back(promoNueva);

        ctrlProducto->setPromocionesSistema(promocionesTotales);
        ctrlProducto->setPromocionesSistemaVigentes(promocionesVigentes);

        DTVendedor dtVen = promoNueva->getVendedor()->toDataType();

        cout << "Promoción ingresada: " << endl;

        DTPromocion promo = DTPromocion(promoNueva->getDescuento(), promoNueva->getNombre(), promoNueva->getDescripcion(), fechaVencimiento);
        cout << "Nombre de Promocion: " << promo.getNombre() << endl;
        cout << "Descripción de Promoción: " << promo.getDescripcion() << endl;
        cout << "Descuento de Promoción: " << promo.getDescuento() << "%" << endl;
        cout << "Fecha de Vencimiento de la Promoción: " << fechaVencimiento.toString() << endl;

        cout << "Vendedor de la promoción: " << dtVen.getNickname() << endl;
        cout << "Productos dentro de la Promoción: " << endl;
        ctrlProducto->imprimirProductosDentroDePromo(promoNueva->getProductosDentroDePromo());
        cout << "La promoción fue ingresada con éxito." << endl;
        cout << "-------------------------------------" << endl;
    } catch (const exception &e) {
        cerr << e.what() << '\n';
    };

    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get();
}