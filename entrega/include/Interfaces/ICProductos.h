#ifndef ICPRODUCTOS_H
#define ICPRODUCTOS_H

#include <string>
#include <vector>
#include <set>
#include "Producto.h"
#include "Promocion.h"
#include "Comentario.h"
#include "Compra.h"
#include "DataTypes/DTFecha.h"

class ICProductos
{
public:
    virtual ~ICProductos() = default;

    virtual void listarProductos() = 0;
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
};

#endif // ICPRODUCTOS_H