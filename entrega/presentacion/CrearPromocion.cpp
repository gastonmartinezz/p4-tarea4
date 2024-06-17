#include <Vendedor.h>
#include <iostream>
#include <string>
#include <set>
#include <Promocion.h>
#include <producto|promocion.h>
using namespace std;

set<Vendedor *> vendedoresSistema; //Set donde guardamos todos los vendedores del sistema

Promocion ingresarPromocion(string nombre, string descripcion, DTFecha vencimiento, float descuento) {
    Promocion *promoNueva = Promocion(descuento, nombre, descripcion, vencimiento);
    return promoNueva;
}

string obtenerListaVendedores() {
    for (auto p: vendedoresSistema) {
        cout << Vendedor::getNickname() << endl;
    }
}

void seleccionarVendedorYObtenerProductos(string nickname) {
    for (auto p: vendedoresSistema) {
        if (nickname == Vendedor::getNickname()) {
            for (auto prod: Producto::getProductos()) {
                cout << Producto::getId() << endl;
                cout << Producto::getNombre() << endl;
            }
        }
    }
}


//Funcion para ver si existe un producto dentro de la promocion
bool productoEnPromoExistente(int id) {
    for (auto promo: promocionesVigentes) {
        for (auto productos: Promocion::getProductosDentroDePromo()) {
            if (id == Producto::getId()) {
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
        if (nickname == Vendedor::getNickname()) {
            for (auto prod: Vendedor::getProductos()) {
                if (productoEnPromoExistente(id)) {
                    cout << "Este producto no se puede agregar a la promoción ya que ya pertenece a una promoción"
                } else {
                    promoNueva->productosDentroDePromo.insert(prod);
                    //Indiquemos la cantidad minima para la promocion por producto
                    for (auto promocion: promoNueva->productosDentroDePromo) {
                        if (id == Producto::getId()) {
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

//Faltaria funcion para dar de alta la promocion en el sistema que tengo dudas para hacerlo

void crearPromocion() {

}