#include "../include/Controladores/ControladorProducto.h"
#include "../include/Interfaces/ICProductos.h"
#include <iostream>
#include <vector>
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

void ControladorProducto::listarProductos()
{
    for (long unsigned int i = 0; i <= arrayProductos.size(); i++)
    {
        cout << "Nombre: " << arrayProductos[i]->getNombre() << endl;
        cout << "Descripción: " << arrayProductos[i]->getDescripcion() << endl;
        cout << "Id: " << arrayProductos[i]->getId() << endl;
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

void ControladorProducto::listarVendedor()
{
    // Implementación para listar vendedor
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

bool productoEnPromoExistente(int id)
{
    bool b;
    for (auto promo : promocionesVigentes)
    {
        for (auto productos : promo->getProductosDentroDePromo())
        {
            if (id == productos->getProducto()->getId())
            {
                b = true;
                break;
            }
            else
            {
                b = false;
            }
        }
    }
    return b;
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