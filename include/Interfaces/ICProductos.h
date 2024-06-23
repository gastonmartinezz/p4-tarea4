#ifndef ICPRODUCTOS_H
#define ICPRODUCTOS_H

#include <string>
#include <vector>
#include <set>
#include "../include/Producto.h"
#include "../include/Promocion.h"
#include "../include/Comentario.h"
#include "../include/Compra.h"
#include "../include/DataTypes/DTFecha.h"

class Compra;
class Producto;
class Promocion;
class DTFecha;
class Comentario;

class ICProductos {
public:
    virtual ~ICProductos() = default;
    virtual void listarProductos() = 0;
    virtual void agregarALaLista(int id,Producto* prod) = 0;
    virtual void confirmarAltaPromocion() = 0;
    virtual void ingresarDatosPromocion(const std::string &nombre, float descuento, const DTFecha &fechaVen) = 0;
    virtual void listarVendedor() = 0;
    virtual void eliminarLinkComentario(int comentarioId) = 0;
    virtual void agregarProducto(const Producto &producto) = 0;
    virtual void ponerProductosLibres() = 0;
    virtual void ingresarDatos(const std::string &nombre, float precio, int stock) = 0;
    virtual void crearPromocion(const std::string &nombre, float descuento, const DTFecha &fechaVen) = 0;
    virtual float sumaDeLosPrecios() const = 0;
    virtual bool productoEstaEnDetalleCompra(int productoId, int compraId) const = 0;
    virtual void agregarProductoACarrito(int productoId) = 0;
    virtual void cancelar() = 0;
    virtual void confirmarCompra() = 0;
    virtual void registrarCompra(const Compra &compra) = 0;
    virtual void desplegarCompra(int compraId) const = 0;
    virtual bool productoEnPromoExistente(int id) = 0;
    virtual void obtenerProductosDeVendedor(std::string nickname) = 0;
    virtual void ingresarPromocionASistema(Promocion promo) = 0;
    virtual void listarProductosVendedor(string nickname, std::vector<DTVendedor> lista);
    virtual vector<Promocion*> getpromocionesSistemaVigentes() = 0;
    virtual vector<Promocion*> getpromocionesSistema() = 0;
};

#endif // ICPRODUCTOS_H