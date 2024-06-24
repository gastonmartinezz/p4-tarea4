#include <iostream>
#include <algorithm>
#include <cctype>
#include "../include/Promocion.h"
#include "../include/Vendedor.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/Fabrica.h"
using namespace std;

void consultarPromocion() {
    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    //ControladorUsuario *ctrlUsuario = Fabrica::getICUsuario();

    int dia;
    int mes;
    int anio;

    cout << "Introduzca el dia de la fecha deseada: " << endl;
    cin >> dia;
    cout << "Introduzca el mes de la fecha deseada: " << endl;
    cin >> mes;
    cout << "Introduzca el año de la fecha deseada: " << endl;
    cin >> anio;

    DTFecha fecha = DTFecha(dia, mes, anio);

    ctrlProducto->obtenerPromocionesActivas(fecha);

    string respuesta;
    string nombrePromocion;
    cout << "Desea seleccionar una promocion para ver sus detalles? (si/no)" << endl;
    cin >> respuesta;

    transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

    if ((respuesta == "NO") or (respuesta == "N")) {
        cout << "No se mostraran los detalles de ninguna promocion." << endl;

    } else if ((respuesta == "SI") or (respuesta == "S")) {
        cout << "Ingresa el nombre de la promocion que deseas ver: " << endl;
        cin >> nombrePromocion;

        ctrlProducto->seleccionarPromocion(nombrePromocion);
    }
}
