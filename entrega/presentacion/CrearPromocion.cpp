#include <Vendedor.h>
#include <contenido.h>
#include <promocion.h>
#include <iostream>
#include <string>
#include <set>
#include <dataTypes.h>
using namespace std;


set<Vendedores*> vendedoresSistema; //Set donde guardamos todos los vendedores del sistema

//Caso de uso: CrearPromocion {FIJARSE EN EJEMPLO DE TRABAJO DEL OTRO GRUPO}

Promocion ingresarPromocion(string nombre, string descripcion, DTFecha vencimiento, float descuento) {
    Promocion *promoNueva = Promocion(descuento, nombre, desc, vencimiento);
    return promoNueva;
}

string obtenerListaVendedores() {
    for (auto p: vendedoresSistema) {
        cout << getNickname() << endl;
    }
}

void seleccionarVendedorYObtenerProductos(string nickname) {
    for (auto p: vendedoresSistema) {
        if (nickname == getNickname()) {
            //Hay que agregar en vendedor.h un atributo que sea una estructura de datos donde el vendedor guarda sus productos
            for (auto prod: setProductosVendedor /*Este es un supuesto set donde hay que agregar como atributo a la clase vendedor*/) {
                cout << getId() << endl;
                cout << getNombre() << endl;
            }
        }
    }
}

bool productoEnPromoExistente(int id) {
    for (auto promo: promocionesVigentes) {
        for (auto productos: productosDentroDePromo) {
            if (id == getId()) {
                return true;
                break;
            } else {
                return false;
            }
        }
    }
}

void seleccionarProductosParaPromocion(string nickname, int id, int cant_minima) {
    for (auto p: vendedoresSistema) {
        if (nickname == getNickname()) {
            for (auto prod: setProductosVendedor) {
                if (productoEnPromoExistente(id)) {
                    cout << "Este producto no se puede agregar a la promoción ya que ya pertenece a una promoción"
                } else {
                    promoNueva->productosDentroDePromo.insert(prod);
                    //Indiquemos la cantidad minima para la promocion por producto
                    for (auto promocion: promoNueva->productosDentroDePromo) {
                        if (id == getId()) {
                            //Hay que indicar que la cantidad minima de ese producto dentro de la promocion es cant_minima
                            promoNueva->productosDentroDePromo->cantidad_minima = cant_minima;
                        }
                    }
                }
            }
        }
    }
}

void ingresarPromocionASistema(Promocion promo) {
    promocionesVigentes.insert(promo);
}

//Faltaria funcion para dar de alta la promocion en el sistema

void crearPromocion() {

}