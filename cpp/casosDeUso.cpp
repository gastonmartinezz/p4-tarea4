#include <resto.cpp>
#include <contenido.h>
#include <promocion.h>

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

//Caso de uso: CrearPromocion {FIJARSE EN EJEMPLO DE TRABAJO DEL OTRO GRUPO}

void ingresarPromocion(string nombre, string descripcion, DTFecha vencimiento, float descuento) {}

set<string> obtenerListaVendedores() {}

void seleccionarVendedor(string nickname) {}

set<DTProducto> obtenerProductosDisponibles() {}

//Caso de Uso: Consultar Promocion

DataPromocion obtenerPromocionesActivas(DTFecha fecha) {
    for (auto f: promociones) {
        for (auto p: Promocion) {
            if (compararFechas(getFechaVencimiento(p)), fecha) {
                promocionesVigentes.insert(p);
            }
        }
    }
}

set<DTPromocion> seleccionarPromocion(string nombre) {
    string nombreNuevo = (string)toupper(nombre);

    for (auto p: promocionesVigentes) {
        if (nombreNuevo == (string)toupper(p->vendedour->nombre)) {
            //Imprimir datos del vendedor y los productos de la promocion (fijarse en cambiar el tipo de devolucion de la funcion)
        }
    }
}

//Caso de Uso: Consultar Producto

set<DTProducto> mostrarInfoProductos() {}

void seleccionaProducto(DTProducto producto) {}

DTProducto mostrarDataProductos(DTProducto prod) {}