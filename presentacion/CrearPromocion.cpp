#include <iostream>
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

void seleccionarProductosParaPromocion(string nickname, int id, int cant_minima) {

    transform(nickname.begin(), nickname.end(), nickname.begin(), ::toupper);

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
    
    //Luego de ingresar los datos para la promoción, invoco a la función obtenerListaVendedores()
    obtenerListaVendedores();


    //El usuario selecciona un vendedor de la lista por su nickname.
    string nickVendedor;
    cout << "Ingrese el nickname del vendedor para asignarle la promoción: " << endl;
    cin >> nickVendedor;

    obtenerProductosDeVendedor(nickVendedor);

    //Invoco la función para ir agregando los productos a la promoción.
    string respuesta;
    int idProducto;
    int cantMin;

    cout << "Deseas agregar un producto a la promoción? (si/no)" << endl;
    cin >> respuesta;

    while ((respuesta != "SI") or (respuesta != "s")) {
        cout << "Ingrese el Id del producto que desea agregar a la promoción: " << endl;
        cin >> idProducto;

        cout << "Ingrese la cantidad mínima de ese producto para que la promoción sea válida: " << endl;
        cin >> cantMin;

        seleccionarProductosParaPromocion(nickVendedor, idProducto, cantMin);

        cout << "Desea agregar otro producto a la promoción? (si/no)" << endl;
        cin >> respuesta;
        transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);
    }

    Promocion* promoNueva = new Promocion();
    promoNueva->setDescripcion(desc);
    promoNueva->setNombre(nombre);
    promoNueva->setDescuento(descuento);
    promoNueva->setFechaVencimiento(fechaVencimiento);
} 