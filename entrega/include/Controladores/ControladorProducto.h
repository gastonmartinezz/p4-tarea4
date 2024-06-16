#ifndef CONTROLADORPRODUCTO_H
#define CONTROLADORPRODUCTO_H

#include <string>
#include <vector>
#include <set>
#include "Producto.h"
#include "Promocion.h"
#include "Comentario.h"
#include "Compra.h"
#include "DataTypes/DTFecha.h"

class ControladorProducto
{
private:
    // Constructor privado para el patrón Singleton
    ControladorProducto() = default;
    static ControladorProducto *instancia;

public:
    // Métodos estáticos para obtener la instancia única
    static ControladorProducto *getInstancia();

    // Métodos del diagrama UML
    void listarProductos();
    void confirmarAltaPromocion();
    void ingresarDatosPromocion(const std::string &nombre, float descuento, const DTFecha &fechaVen);
    void listarVendedor();
    void eliminarLinkComentario(int comentarioId);
    void agregarProducto(const Producto &producto);
    void ponerProductosLibres();
    void ingresarDatos(const std::string &nombre, float precio, int stock);
    void crearPromocion(const std::string &nombre, float descuento, const DTFecha &fechaVen);
    float sumaDeLosPrecios() const;
    bool productoEstaEnDetalleCompra(int productoId, int compraId) const;
    void agregarProductoACarrito(int productoId);
    void cancelar();
    void confirmarCompra();
    void registrarCompra(const Compra &compra);
    void desplegarCompra(int compraId) const;
};

#endif // CONTROLADORPRODUCTO_H