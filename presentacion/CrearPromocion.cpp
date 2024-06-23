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
        if (cin.fail()) {
            cerr << "Error: Entrada no válida para el mes de la fecha de vencimiento." << endl;
            return;
        }

        cout << "Ingrese el año de la fecha de vencimiento: " << endl;
        cin >> anio;
        while (cin.fail() || anio < 1900 || anio > 2100)
        { // Puedes ajustar el rango según tus necesidades
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Año inválido. Por favor, ingrese un año razonable: ";
            cin >> anio;
        }

        fechaVencimiento = DTFecha(dia, mes, anio);
        fechaVencimiento.toString();

        // Muestro los datos de los vendedores para que el administrador elija uno con el nickname.
        vector<DTUsuario> vendedores = ctrlUsuario->listarUsuarios();
        //vector<DTVendedor> vendedores = ctrlUsuario->listaVendedor();
        cout << "Lista de Vendedores:" << endl;
        if (vendedores.size() == 0) {
            throw invalid_argument("No hay usuarios registrados.");
        }

        for (vector<DTVendedor>::size_type i = 0; i < vendedores.size(); ++i) {
            cout << i << "-";
            cout << vendedores[i].getNombre() << endl;
        }
        
        cout << "llego aca2" << endl;
        // El usuario selecciona un vendedor de la lista por su nickname.
        string nickVendedor;
        cout << "Ingrese el nickname del vendedor para asignarle la promoción: " << endl;
        cin >> nickVendedor;

        ctrlProducto->listarProductosVendedor(nickVendedor, ctrlUsuario->listaVendedor());

        // Invoco la función para ir agregando los productos a la promoción.
        string respuesta;
        int idProducto;
        int cantMin;

        cout << "Deseas agregar un producto a la promoción? (si/no)" << endl;
        cin >> respuesta;
        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

        vector<Contenido *> productosPromocion;
        bool seguir = true;

        while (seguir) {
            cout << "Ingrese el Id del producto que desea agregar a la promoción: " << endl;
            cin >> idProducto;

            cout << "Ingrese la cantidad mínima de ese producto para que la promoción sea válida: " << endl;
            cin >> cantMin;

            Contenido *conte = ctrlProducto->seleccionarProductosParaPromocion(ctrlUsuario->listaVendedor(), nickVendedor, ctrlProducto->getListaProductos()[idProducto], cantMin, idProducto);
            productosPromocion.push_back(conte);

            cout << "Desea agregar otro producto a la promoción? (si/no)" << endl;
            cin >> respuesta;

            transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

            if (!((respuesta == "SI") || (respuesta == "S"))) {
                seguir = false;
            }
        }

        Promocion *promoNueva = new Promocion();
        promoNueva->setDescripcion(desc);
        promoNueva->setNombre(nombre);
        promoNueva->setDescuento(descuento);
        promoNueva->setFechaVencimiento(fechaVencimiento);
        promoNueva->setProductosDentroDePromo(productosPromocion);

        ctrlProducto->getpromocionesSistemaVigentes().push_back(promoNueva);
        ctrlProducto->getpromocionesSistema().push_back(promoNueva);
     }
    catch (const std::exception &e) {
        cerr << e.what() << '\n';
    };
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get(); // Espera que el usuario presione Enter 
}