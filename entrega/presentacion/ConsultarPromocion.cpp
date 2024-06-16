#include <iostream>
#include <DTFecha.h>
#include <Promocion.h>
#include <Vendedor.h>
#include <locale>
using namespace std;

set<Promocion*> promociones; //Set donde guardamos todas las promociones del sistema
set<Promocion*> promocionesVigentes; //Set donde guardamos todas las promociones vigentes del sistema
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
            if (compararFechas(getFechaVencimiento(p), fecha)) {
                promocionesVigentes.insert(p);
            }
        }
    }

    for (auto promociones: promocionesVigentes) {
        cout << "Nombre de la promocion: " << getNombre() << endl;
        cout << "Descripcion de la promocion: " << getDescripcion() << endl;
        cout << "Descuento de la promocion: " << getDescuento() << endl;
        cout << "Fecha de Vencimiento de la promocion: " << getFechaVencimiento() << endl;
        cout << "Vendedor de la promocion: " << getVendedor() << endl;
    }
}

string seleccionarPromocion(string nombre) {
    for (auto p: promocionesVigentes) {
        if ((string)toupper(nombre); == (string)toupper(getNombre())) {
            //Imprimir datos del vendedor y los productos de la promocion (fijarse en cambiar el tipo de devolucion de la funcion)
            cout << "Nombre de la promocion: " << getNombre() << endl;
            cout << "Vendedor de la promocion: " << getVendedor() << endl;
            cout << "RUT del vendedor: " << getCodigoRut() << endl;

            for (auto productos: productosDentroDePromo) {
                cout << "Nombre del producto: " << getNombre() << endl; 
                cout << "Id del producto: " << getId() << endl;
                cout << "Descripcion del producto: " << getDescripcion() << endl;
                cout << "Stock del producto: " << getStoc() << endl;
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

    if ((string)toupper(respuesta) == "NO") {
        cout << "No se mostraran detalles sobre ninguna promocion." << endl;

    } else if ((string)toupper(respuesta) == "SI") {
        cout << "Ingresa el nombre de la promocion que deseas ver: " << endl;
        cin >> nombrePromocion;

        seleccionarPromocion(nombrePromocion);
    }
}





