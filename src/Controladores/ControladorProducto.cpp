#include "../include/Controladores/ControladorProducto.h"
#include "../include/DataTypes/DTVendedor.h"
#include "../include/Interfaces/ICProductos.h"
#include "../include/contenido.h"
#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;
class Contenido;

// Inicialización de la instancia singleton
ControladorProducto *ControladorProducto::instance = nullptr;

ControladorProducto *ControladorProducto::getInstance() {
    if (!instance) {
        instance = new ControladorProducto();
    }
    return instance;

}

DTFecha ControladorProducto::fecha = DTFecha(24, 6, 2024);

DTFecha ControladorProducto::getFecha() {
    return this->fecha;
}
void ControladorProducto::setFecha(DTFecha fecha) {
    this->fecha = fecha;
}

void ControladorProducto::agregarALaLista(int id, Producto *prod) {
    listaProductos.insert(std::make_pair(id, prod));
}

void ControladorProducto::listarProductos() {
    try {
        long unsigned int i;
        if (listaProductos.size() == 0 ) {
            cout << "No hay productos registrados en el sistema." << endl;
            //throw invalid_argument("No hay productos registrados en el sistema.");
        } else {
            cout << "Lista de los productos registrados en el sistema: " << endl;
            cout << "-------------------------------------------------" << endl;

            for (i = 1; i <= listaProductos.size(); i++) {
                DTProducto prod = listaProductos[i]->toDataType();
                prod.setDescripcion(listaProductos[i]->getDescripcion());

                cout << "Id: " << prod.getId() << endl;
                cout << "Nombre: " << prod.getNombre() << endl;
                cout << "Descripción: " << prod.getDescripcion() << endl;
            }
        }
    } catch (const std::exception &e) {
        cerr << e.what() << '\n';
    };
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get(); // Espera que el usuario presione Enter 
}

vector<DTProducto> ControladorProducto::listarProductos2()
{
    vector<DTProducto> aux;

    for (auto it = listaProductos.begin(); it != listaProductos.end(); it++)
    {
        aux.push_back(it->second->toDataType());
    }
    return aux;
}

void ControladorProducto::confirmarAltaPromocion()
{
    // Implementación para confirmar alta de promoción
}

void ControladorProducto::ingresarDatosPromocion(const string &nombre, float descuento, const DTFecha &fechaVen)
{
    // Implementación para ingresar datos de promoción
}

void ControladorProducto::listarProductosVendedor(string nickname, vector<DTVendedor> lista) {
    for (vector<DTVendedor>::size_type i = 0; i < lista.size(); ++i) {
        if (nickname == lista[i].getNickname()) {
            cout << "Productos del Vendedor " << nickname << endl;
            cout << "-----------------------" << endl;

            for (vector<Producto *>::size_type h = 0; h < lista[i].getProductos().size(); ++h) {
                if (lista[i].getProductos().size() != 0) {
                    cout << "Id de Producto: " << lista[i].getProductos()[h]->getId() << endl;
                    cout << "Nombre de Producto: " << lista[i].getProductos()[h]->getNombre() << endl;
                }
                else {
                    cout << "Este vendedor no tiene productos para mostrar." << endl;
                }
            }
        }
    }
}

void ControladorProducto::eliminarLinkComentario(int comentarioId)
{
    // Implementación para eliminar link de comentario
}

void ControladorProducto::agregarProducto(const Producto &producto)
{
    // Implementación para agregar producto
}

void ControladorProducto::ponerProductosLibres()
{
    // Implementación para poner productos libres
}

void ControladorProducto::ingresarDatos(const string &nombre, float precio, int stock)
{
    // Implementación para ingresar datos de producto
}

void ControladorProducto::crearPromocion(const string &nombre, float descuento, const DTFecha &fechaVen)
{
    // Implementación para crear promoción
}

float ControladorProducto::sumaDeLosPrecios() const
{
    // Implementación para sumar los precios de los productos
    return 0.0; // Valor de retorno por defecto, cambiar según implementación
}

bool ControladorProducto::productoEstaEnDetalleCompra(int productoId, int compraId) const
{
    // Implementación para verificar si el producto está en el detalle de la compra
    return false; // Valor de retorno por defecto, cambiar según implementación
}

void ControladorProducto::agregarProductoACarrito(int productoId)
{
    // Implementación para agregar producto al carrito
}

void ControladorProducto::cancelar()
{
    // Implementación para cancelar operación
}

void ControladorProducto::confirmarCompra()
{
    // Implementación para confirmar compra
}

void ControladorProducto::registrarCompra(const Compra &compra)
{
    // Implementación para registrar compra
}

void ControladorProducto::desplegarCompra(int compraId) const
{
    // Implementación para desplegar detalles de una compra
}

void ControladorProducto::AddComentario(Comentario *coment, int productoId)
{
    // Buscar el producto por su ID en la lista de productos
    auto it = listaProductos.find(productoId);
    if (it != listaProductos.end())
    {
        Producto *producto = it->second;
        producto->addComentario(coment);
    }
    else
    {
        // Manejar caso donde el producto no existe
        cout << "Error: Producto con ID " << productoId << " no encontrado." << endl;
    }
}

int ControladorProducto::getContador() {
    return this->contador_id_producto;
}

void ControladorProducto::setContador(int valorContador) {
    contador_id_producto = valorContador;
}

void ControladorProducto::incrementarContador() {
    contador_id_producto++;
}

/* int ControladorProducto::getContador()
{
    return contador_id_producto;
}; */

// void obtenerProductosDeVendedor(string nickname) {
//     transform(nickname.begin(), nickname.end(), nickname.begin(), ::toupper);

//     for (auto p: vendedoresSistema) {
//         string nicknameVendedorTemporal = p->getNickname();
//         transform(nicknameVendedorTemporal.begin(), nicknameVendedorTemporal.end(), nicknameVendedorTemporal.begin(), ::toupper);

//         if (nickname == nicknameVendedorTemporal) {
//             for (auto prod: p->getProductos()) {
//                 cout << prod.getId() << endl;
//                 cout << prod.getNombre() << endl;
//             }
//         }
//     }
// }

// bool ControladorProducto::productoEnPromoExistente(int id) {
/*     bool b;
    map<int, Contenido*> copiaPromocionesSistemasVigentes = getPromocionesSistemaVigentes();
    for (auto promo : copiaPromocionesSistemasVigentes) {
        for (auto productos : promo->getProductosDentroDePromo()) {
            if (id == productos->getProducto()->getId()) {
                b = true;
                break;
            } else {
                b = false;
            }
         }
     }
    return b; */
//}

//Funcion para comparar fechas
bool ControladorProducto::compararFechas(DTFecha fecha1, DTFecha fecha2) {
     if (fecha1.getAnio() > fecha2.getAnio()) {
         return true;

    } else if (fecha1.getAnio() < fecha2.getAnio()) {
        return false;

    } else {
        if (fecha1.getMes() > fecha2.getMes()) {
            return true;
        } else if (fecha1.getMes() < fecha2.getMes()) {
            return false;
        } else {
            return fecha1.getDia() > fecha2.getDia();
        }
    }
}

void ControladorProducto::obtenerPromocionesActivas(DTFecha fecha) {
    for (auto f: promocionesSistema) {
        if (compararFechas(f->getFechaVencimiento(), fecha)) {
            promocionesSistemaVigentes.push_back(f);
        }
    }

    for (auto promociones: promocionesSistemaVigentes) {
        cout << "Nombre de la promocion: " << promociones->getNombre() << endl;
        cout << "Descripcion de la promocion: " << promociones->getDescripcion() << endl;
        cout << "Descuento de la promocion: " << promociones->getDescuento() << endl;
        cout << "Fecha de Vencimiento de la promocion: " << promociones->getFechaVencimiento().toString() << endl;
        cout << "Vendedor de la promocion: " << promociones->getVendedor() << endl;
    } 
}

void ControladorProducto::seleccionarPromocion(string nombre) {
    transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper); //transformar el string de minúscula a mayúscula

    for (auto promo: promocionesSistemaVigentes) {
        string nombrePromocion = promo->getNombre();

        transform(nombrePromocion.begin(), nombrePromocion.end(), nombrePromocion.begin(), ::toupper);

        if (nombre == nombrePromocion) {
            DTPromocion promoNueva = promo->toDataType();
            //Imprimir datos del vendedor y los productos de la promocion
            //(fijarse en cambiar el tipo de devolucion de la funcion)
            promoNueva.setVendedor(promo->getVendedor());
            cout << "Nombre de la promocion: " << promoNueva.getNombre() << endl;
            cout << "Vendedor de la promocion: " << promoNueva.getVendedor() << endl;
            cout << "RUT del vendedor: " << promoNueva.getVendedor()->getCodigoRut() << endl;

            for (auto productos: promo->getProductosDentroDePromo()) {
                DTProducto prod = productos->getProducto()->toDataType();
                prod.setStock(productos->getProducto()->getStock());
                prod.setDescripcion(productos->getProducto()->getDescripcion());

                cout << "Nombre del producto: " << prod.getNombre() << endl;
                cout << "Id del producto: " << prod.getId() << endl;
                cout << "Descripcion del producto: " << prod.getDescripcion() << endl;
                cout << "Stock del producto: " << prod.getStock() << endl;
            }
        }
    } 
}

bool ControladorProducto::productoEnPromoExistente(int id) {
    bool b = false;
    if (promocionesSistemaVigentes.size() == 0) {
        return b = false;
    } else {
        for (vector<Promocion *>::size_type i = 0; i < promocionesSistemaVigentes.size(); i++) {
            for (vector<Contenido *>::size_type h = 0; h < promocionesSistemaVigentes[i]->getProductosDentroDePromo().size(); h++) {
                if (id == promocionesSistemaVigentes[i]->getProductosDentroDePromo()[h]->getProducto()->getId()) {
                    return b = true;
                    break;
                }
            }
        }
    }
    return b;
}


vector<Promocion *> ControladorProducto::getpromocionesSistemaVigentes()
{
    return promocionesSistemaVigentes;
}
vector<Promocion *> ControladorProducto::getpromocionesSistema()
{
    return promocionesSistema;
}

Producto *ControladorProducto::getProducto(int idProducto)
{
    return listaProductos[idProducto];
}

map<int, Producto *> ControladorProducto::getListaProductos()
{
    return this->listaProductos;
}

void ControladorProducto::imprimirProductosDentroDePromo(vector<Contenido*>Promocion) {
    for (auto contenido : Promocion) {
        Producto* producto = contenido->getProducto();
        if (producto != nullptr) {
            cout << "Producto: " << producto->getNombre() << endl;
            cout << "Cantidad mínima: " << contenido->getCantMinima() << endl;
        } else {
            cout << "Producto no disponible" << endl;
        }
    }
}

