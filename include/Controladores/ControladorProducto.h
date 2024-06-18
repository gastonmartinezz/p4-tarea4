#ifndef CONTROLADORPRODUCTO_H
#define CONTROLADORPRODUCTO_H

#include <string>
#include <vector>
#include <set>
#include  "../include/Producto.h"
#include  "../include/Promocion.h"
#include  "../include/Comentario.h"
#include  "../include/Compra.h"
#include  "../include/DataTypes/DTFecha.h"
using namespace std;

class Producto;
class Promocion;
class Comentario;
class Compra;

class ControladorProducto {
private:
    // Constructor privado para el patrón Singleton
    ControladorProducto() = default;
    static ControladorProducto *instancia;

public:
    // Métodos estáticos para obtener la instancia única
    static ControladorProducto *getInstancia();

    // Métodos del diagrama UML
    vector<Producto*> listarProductos();
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

vector<Producto*> arrayProductos; //Array donde guardamos los productos del sistema.

#endif // CONTROLADORPRODUCTO_H