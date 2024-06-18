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
        if (compararFechas(f->getFechaVencimiento(), fecha)) {
            promocionesVigentes.insert(f);
        }
    }

    for (auto promociones: promocionesVigentes) {
        cout << "Nombre de la promocion: " << promociones->getNombre() << endl;
        cout << "Descripcion de la promocion: " << promociones->getDescripcion() << endl;
        cout << "Descuento de la promocion: " << promociones->getDescuento() << endl;
        cout << "Fecha de Vencimiento de la promocion: " << promociones->getFechaVencimiento() << endl;
        cout << "Vendedor de la promocion: " << promociones->getVendedor() << endl;
    }
}

string seleccionarPromocion(string nombre) {    
    transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper); //transformar el string de minúscula a mayúscula
    
    for (auto p: promocionesVigentes) {
        string nombrePromocion = p->getNombre();
        transform(nombrePromocion.begin(), nombrePromocion.end(), nombrePromocion.begin(), ::toupper);

        if (nombre == nombrePromocion) {
            //Imprimir datos del vendedor y los productos de la promocion 
            //(fijarse en cambiar el tipo de devolucion de la funcion)
            cout << "Nombre de la promocion: " << p->getNombre() << endl;
            cout << "Vendedor de la promocion: " << p->getVendedor() << endl;
            cout << "RUT del vendedor: " << p->getVendedor()->getCodigoRut() << endl;

            for (auto productos: p->getProductosDentroDePromo()) {
                cout << "Nombre del producto: " << productos->getProducto()->getNombre() << endl; 
                cout << "Id del producto: " << productos->getProducto()->getId() << endl;
                cout << "Descripcion del producto: " << productos->getProducto()->getDescripcion() << endl;
                cout << "Stock del producto: " << productos->getProducto()->getStock() << endl;
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

    fecha->dia = dia;
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