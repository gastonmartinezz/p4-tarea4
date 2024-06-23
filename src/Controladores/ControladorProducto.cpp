#include "../include/Controladores/ControladorProducto.h"
#include "../include/DataTypes/DTVendedor.h"
#include "../include/Interfaces/ICProductos.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Inicialización de la instancia singleton
ControladorProducto *ControladorProducto::instance = nullptr;
ControladorProducto *ControladorProducto::getInstance()

{
    if (!instance)
    {
        instance = new ControladorProducto();
    }
    return instance;
}

void ControladorProducto::agregarALaLista(int id,Producto* prod) { 
    listaProductos.insert(std::make_pair(id, prod));
}

void ControladorProducto::listarProductos()
{
    for (long unsigned int i = 0; i <= listaProductos.size(); i++)
    {
        cout << "Nombre: " << listaProductos[i]->getNombre() << endl;
        cout << "Descripción: " << listaProductos[i]->getDescripcion() << endl;
        cout << "Id: " << listaProductos[i]->getId() << endl;
        /*cout << "Precio: " << arrayProductos[i]->getPrecio() << endl;
        cout << "Stock: " << arrayProductos[i]->getStock() << endl;
        cout << "Vendedor: " << arrayProductos[i]->getVendedor() << endl;*/

        // Comento las salidas de consola de arriba ya que no se si debemos imprimir toda la información del producto
    }
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
            for (vector<Producto*>::size_type h = 0; h < lista[i].getProductos().size(); ++h) {
                if (lista[i].getProductos().size() != 0) {
                    cout << "Id de Producto: " << lista[i].getProductos()[h]->getId() << endl;
                    cout << "Nombre de Producto: " << lista[i].getProductos()[h]->getNombre() << endl;
                } else {
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
    return 0.0f; // Valor de retorno por defecto, cambiar según implementación
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

void ControladorProducto::incrementarContador()
{
    contador_id_producto++;
};
int ControladorProducto::getContador()
{
    return contador_id_producto;
};

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

// void ingresarPromocionASistema(Promocion promo) {
//     promocionesVigentes.insert(promo);
// }

//bool ControladorProducto::productoEnPromoExistente(int id) {
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

//void ControladorProducto::obtenerPromocionesActivas(DTFecha fecha) {
/*     for (auto f: promocionesSistema) {
        if (compararFechas(f->getFechaVencimiento(), fecha)) {
            promocionesSistemaVigentes.insert(f);
        }
    }

    for (auto promociones: promocionesSistemaVigentes) {
        cout << "Nombre de la promocion: " << promociones->getNombre() << endl;
        cout << "Descripcion de la promocion: " << promociones->getDescripcion() << endl;
        cout << "Descuento de la promocion: " << promociones->getDescuento() << endl;
        cout << "Fecha de Vencimiento de la promocion: " << promociones->getFechaVencimiento() << endl;
        cout << "Vendedor de la promocion: " << promociones->getVendedor() << endl;
    } */
//}

//Funcion para comparar fechas
// bool ControladorProducto::compararFechas(DTFecha fecha1, DTFecha fecha2) {
//     if (fecha1.getAnio() > fecha2.getAnio()) {
//         return true;

//     } else if (fecha1.getAnio() < fecha2.getAnio()) {
//         return false;   
        
//     } else {
//         if (fecha1.getMes() > fecha2.getMes()) {
//             return true;
//         } else if (fecha1.getMes() < fecha2.getMes()) {
//             return false;
//         } else {
//             return fecha1.getDia() > fecha2.getDia();
//         }
//     }
// }

// void ControladorProducto::seleccionarPromocion(string nombre) {    
// /*     transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper); //transformar el string de minúscula a mayúscula
    
//     for (auto promo: promocionesSistemaVigentes) {
//         string nombrePromocion = promo->getProducto()->getNombre();

//         transform(nombrePromocion.begin(), nombrePromocion.end(), nombrePromocion.begin(), ::toupper);

//         if (nombre == nombrePromocion) {
//             DTPromocion promoNueva = promo->toDataType();
//             //Imprimir datos del vendedor y los productos de la promocion 
//             //(fijarse en cambiar el tipo de devolucion de la funcion)
//             cout << "Nombre de la promocion: " << promoNueva.getNombre() << endl;
//             cout << "Vendedor de la promocion: " << promoNueva.getVendedor() << endl;
//             cout << "RUT del vendedor: " << promoNueva.getVendedor()->getCodigoRut() << endl;

//             for (auto productos: promo->getProductosDentroDePromo()) {
//                 DTProducto prod = promo->getProducto()->toDataType();
//                 cout << "Nombre del producto: " << prod->getNombre() << endl; 
//                 cout << "Id del producto: " << prod->getId() << endl;
//                 cout << "Descripcion del producto: " << prod->getDescripcion() << endl;
//                 cout << "Stock del producto: " << prod->getStock() << endl;
//             }
//         }
//     } */
// }

bool ControladorProducto::productoEnPromoExistente(int id) {
    bool b = false;
    for (vector<Promocion*>::size_type i = 0; i < promocionesSistemaVigentes.size(); ++i) {
        for (vector<Contenido*>::size_type h = 0; h < promocionesSistemaVigentes[i]->getProductosDentroDePromo().size(); ++h) {
            if (id == promocionesSistemaVigentes[i]->getProductosDentroDePromo()[h]->getProducto()->getId()) {
                b = true;
                break;
            }
        }
    }
    return b;
}

Contenido* ControladorProducto::seleccionarProductosParaPromocion(vector<DTVendedor>lista, string nickname, Producto* prod, int cant_minima, int id) {
    transform(nickname.begin(), nickname.end(), nickname.begin(), ::toupper);

    for (auto p: lista) {
        if (nickname == p.getNickname()) {
            for (auto prod: p.getProductos()) {
                if (productoEnPromoExistente(id)) {
                    cout << "Este producto no se puede agregar a la promoción ya que ya pertenece a otra promoción vigente." << endl;
                    break;
                } else {
                    Contenido* conteNuevo = new Contenido();
                    conteNuevo->setCantMinima(cant_minima);
                    conteNuevo->setProducto(prod); //Agregar metodo a contenido.h
                    return conteNuevo;
                    }
                }
            }
    }
}
 vector<Promocion*> ControladorProducto::getpromocionesSistemaVigentes() {
    return promocionesSistemaVigentes;
}
vector<Promocion*> ControladorProducto::getpromocionesSistema() {
    return promocionesSistema;
}  

Producto* ControladorProducto::getProducto(int idProducto) {
    return listaProductos[idProducto];
}

map<int, Producto*> ControladorProducto::getListaProductos() {
    return listaProductos;
}