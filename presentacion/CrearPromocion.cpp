/* #include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include "../include/Promocion.h"
#include "../include/contenido.h"
#include "../include/Vendedor.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/Controladores/ControladorUsuario.h"
using namespace std;

//Función para imprimir los vendedores que hay registrado en el sistema.

void ingresarPromocionASistema(Promocion promo) {
    promocionesVigentes.insert(promo);
}

//Faltaria funcion para dar de alta la promocion en el sistema que tengo dudas para hacerlo

Promocion* crearPromocion() {

    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    ControladorUsuario *ctrlUsuario = Fabrica::getICUsuario();

    try {

    
    string nombre, desc;
    float descuento;
    int dia, mes, anio;
    DTFecha fechaVencimiento;

    cout << "Ingresa el nombre de la promoción: " << endl;
    cin >> nombre;
    cout << "Ingrese la descripción de la promoción: " << endl;
    cin >> desc;
    cout << "Ingrese el descuento de la promoción: " << endl;
    cin >> descuento;
    cout << "Ingrese el dia de la fecha de vencimiento: " << endl;
    cin >> dia;
    cout << "Ingrese el numero de mes de la fecha de vencimiento: " << endl;
    cin >> mes;
    cout << "Ingrese el anio de la fecha de vencimiento: " << endl;
    cin >> anio;

    fechaVencimiento->dia = dia;
    fechaVencimiento->mes = mes;
    fechaVencimiento->anio = anio;
    
    //Muestro los datos de los vendedores para que el administrador elija uno con el nickname.
    std::vector<DTVendedor> vendedores = ctrlUsuario->listaVendedor();
    std::cout << "Lista de Vendedores:" << std::endl;
    if (vendedores.size() == 0)
    {
        throw invalid_argument("No hay usuarios registrados.");
    }

    for (vector<DTVendedor>::size_type i = 0; i < vendedores.size(); ++i)
    {
        cout << i << "-";
        cout << vendedores[i].getNickname() << endl;
    }

    //El usuario selecciona un vendedor de la lista por su nickname.
    string nickVendedor;
    cout << "Ingrese el nickname del vendedor para asignarle la promoción: " << endl;
    cin >> nickVendedor;

    ctrlProducto->listarProductosVendedor(nickVendedor,ctrlProducto->listarProductos2());

    //Invoco la función para ir agregando los productos a la promoción.
    string respuesta;
    int idProducto;
    int cantMin;

    cout << "Deseas agregar un producto a la promoción? (si/no)" << endl;
    cin >> respuesta;
    transform(respuesta.begin(), respuesta.end(), ::toupper)

    set<Contenido*>productosPromocion;
    bool seguir = true;

    while (seguir) {
        cout << "Ingrese el Id del producto que desea agregar a la promoción: " << endl;
        cin >> idProducto;

        cout << "Ingrese la cantidad mínima de ese producto para que la promoción sea válida: " << endl;
        cin >> cantMin;

        Contenido* conte = seleccionarProductosParaPromocion(nickVendedor, ctrlProducto->listaProductos[idProducto], cantMin);
        productosPromocion.insert(conte);

        cout << "Desea agregar otro producto a la promoción? (si/no)" << endl;
        cin >> respuesta;

        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

        if !((respuesta == "SI") || (respuesta == "S")) {
            seguir = false;
        } 
    }

    Promocion* promoNueva = new Promocion();
    promoNueva->setDescripcion(desc);
    promoNueva->setNombre(nombre);
    promoNueva->setDescuento(descuento);
    promoNueva->setFechaVencimiento(fechaVencimiento);
    promoNueva->setProductosDentroDePromo(productosPromocion);

    ctrlProducto->getpromocionesSistemaVigentes().insert(promoNueva);
    ctrlProducto->getpromocionesSistema().insert(promoNueva);

    return promoNueva;

    } catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    };
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get(); // Espera que el usuario presione Enter
} */