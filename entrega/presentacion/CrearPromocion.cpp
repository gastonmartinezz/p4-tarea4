#include <Vendedor.h>
#include <iostream>
#include <string>
#include <set>
#include <Promocion.h>
#include <contenido.h>
using namespace std;

set<Vendedor*> vendedoresSistema; //Set donde guardamos todos los vendedores del sistema

string obtenerListaVendedores() {
    for (auto p: vendedoresSistema) {
        cout << p->getNickname() << endl;
    }
}

void seleccionarVendedorYObtenerProductos(string nickname) {
    for (auto p: vendedoresSistema) {
        if (nickname == p->getNickname()) {
            for (auto prod: p->getProductos()) {
                cout << prod.getId() << endl; //Ver si el contenedor de productos es un objeto o no.
                cout << prod.getNombre() << endl;
            }
        }
    }
}

//Funcion para ver si existe un producto dentro de la promocion
bool productoEnPromoExistente(int id) {
    for (auto promo: promocionesVigentes) {
        for (auto productos: promo->getProductosDentroDePromo()) {
            if (id == productos->getProducto()->getId()) { //Preciso ayuda con este.
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
        if (nickname == p->getNickname()) {
            for (auto prod: p->getProductos()) {
                if (productoEnPromoExistente(id)) {
                    cout << "Este producto no se puede agregar a la promoción ya que ya pertenece a otra promoción vigente." << endl;
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
    string nombre, desc, nombreVendedor;
    float descuento;
    int dia, mes, anio;
    DTFecha fechaVencimiento;
    Vendedor* vendedor;

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
    cout<< "Ingresa el nombre del vendedor de la promocion: " << endl;
    cin >> nombreVendedor;
    //La idea de esto es buscar al vendedor por nombre en los vendedores del sistema y copiar esa memoria (o si les parece mejor que apunte )

    fechaVencimiento->dia = dia;
    fechaVencimiento->mes = mes;
    fechaVencimiento->anio = anio;

    Promocion* promoNueva = new Promocion();
    promoNueva->setDescripcion(desc);
    promoNueva->setNombre(nombre);
    promoNueva->setDescuento(descuento);
    promoNueva->setFechaVencimiento(fechaVencimiento);
    promoNueva-
}