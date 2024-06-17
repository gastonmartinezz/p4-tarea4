#include <iostream>
#include <DTFecha.h>
#include <Promocion.h>
#include <Vendedor.h>
#include <algorithm>
#include <cctype>
using namespace std;

//Funcion para comparar fechas
bool compararFechas(DTFecha fecha1, DTFecha fecha2) {
    if (fecha1.anio > fecha2.anio) {
        return true;

    } else if (fecha1.anio < fecha2.anio) {
        return false;   
        
    } else {
        if (fecha1.mes > fecha2.mes) {
            return true;
        } else if (fecha1.mes < fecha2.mes) {
            return false;
        } else {
            return fecha1.dia > fecha2.dia;
        }
    }
}

//Caso de Uso: Consultar Promocion
set<Contenido*> obtenerPromocionesActivas(DTFecha fecha) {
    for (auto f: promociones) {
        for (auto p: Promocion) {
            if (compararFechas(Promocion::getFechaVencimiento(p), fecha)) {
                promocionesVigentes.insert(p);
            }
        }
    }

    for (auto promociones: promocionesVigentes) {
        cout << "Nombre de la promocion: " << Promocion::getNombre() << endl;
        cout << "Descripcion de la promocion: " << Promocion::getDescripcion() << endl;
        cout << "Descuento de la promocion: " << Promocion::getDescuento() << endl;
        cout << "Fecha de Vencimiento de la promocion: " << Promocion::getFechaVencimiento() << endl;
        cout << "Vendedor de la promocion: " << Promocion::getVendedor() << endl;
    }
}

string seleccionarPromocion(string nombre) {    
    transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper); //transformar el string de minúscula a mayúscula
    string nombrePromocion = Promocion::getNombre();
    transform(nombrePromocion.begin(), nombrePromocion.end(), nombrePromocion.begin(), ::toupper);

    for (auto p: promocionesVigentes) {
        if (nombre == nombrePromocion) {
            //Imprimir datos del vendedor y los productos de la promocion 
            //(fijarse en cambiar el tipo de devolucion de la funcion)
            cout << "Nombre de la promocion: " << Promocion::getNombre() << endl;
            cout << "Vendedor de la promocion: " << Promocion::getVendedor() << endl;
            cout << "RUT del vendedor: " << Vendedor::getCodigoRut() << endl;

            for (auto productos: Promocion::productosDentroDePromo()) {
                cout << "Nombre del producto: " << Producto::getNombre() << endl; 
                cout << "Id del producto: " << Producto::getId() << endl;
                cout << "Descripcion del producto: " << Producto::getDescripcion() << endl;
                cout << "Stock del producto: " << Producto::getStock() << endl;
            }

        }
    }
}

void consultarPromocion() {
    int dia;
    int mes;
    int anio;
    DTFecha fecha;

    cout << "Introduzca el dia de la fecha deseada: " << endl;
    cin >> dia;
    cout << "Introduzca el mes de la fecha deseada: " << endl;
    cin >> mes;
    cout << "Introduzca el año de la fecha deseada: " << endl;
    cin >> anio;

    fecha-> dia = dia;
    fecha->mes = mes;
    fecha->anio = anio;

    obtenerPromocionesActivas(fecha);

    string respuesta;
    string nombrePromocion;
    cout << "Deseas seleccionar una promocion para ver sus detalles? (si/no)" << endl;
    cin >> respuesta;

    transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

    if ((respuesta == "NO") or (respuesta == "N")) {
        cout << "No se mostraran los detalles de ninguna promocion." << endl;

    } else if ((respuesta == "SI") or (respuesta == "S")) {
        cout << "Ingresa el nombre de la promocion que deseas ver: " << endl;
        cin >> nombrePromocion;

        seleccionarPromocion(nombrePromocion);
    }
}