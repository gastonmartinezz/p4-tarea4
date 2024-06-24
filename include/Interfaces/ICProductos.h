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
class Contenido;

class ICProductos {
public:
    virtual ~ICProductos() = default;
    virtual void listarProductos() = 0;
    virtual vector<DTProducto> listarProductos2() = 0;
    virtual map<int, Producto*> getListaProductos() = 0;
    virtual void agregarALaLista(int id,Producto* prod) = 0;
    virtual void listarVendedor() = 0;
    virtual void listarProductosVendedor(string nickname, vector<DTVendedor> lista) = 0;
    virtual void eliminarLinkComentario(int comentarioId) = 0;
    virtual void agregarProducto(const Producto &producto) = 0;
    virtual void ponerProductosLibres() = 0;
    virtual void ingresarDatos(const string &nombre, float precio, int stock) = 0;
    virtual void crearPromocion(const string &nombre, float descuento, const DTFecha &fechaVen) = 0;
    virtual float sumaDeLosPrecios() const = 0;
    virtual bool productoEstaEnDetalleCompra(int productoId, int compraId) const = 0;
    virtual void agregarProductoACarrito(int productoId) = 0;
    virtual void cancelar() = 0;
    virtual void confirmarCompra() = 0;
    virtual void registrarCompra(const Compra &compra) = 0;
    virtual void desplegarCompra(int compraId) const = 0;
    virtual void obtenerProductosDeVendedor(string nickname) = 0;
    virtual DTFecha getFecha() = 0;
    virtual int getContador() = 0;
    virtual void setContador(int valorContador) = 0;
    virtual void incrementarContador() = 0;
    virtual void AddComentario(Comentario *coment, int producto) = 0;
    virtual vector<Promocion*> getpromocionesSistemaVigentes() = 0;
    virtual vector<Promocion*> getpromocionesSistema() = 0;
    virtual void setPromocionesSistemaVigentes(vector<Promocion*> promoSisV) = 0;
    virtual void setPromocionesSistema(vector<Promocion*> promoSis) = 0;
    virtual void obtenerPromocionesActivas(DTFecha fecha) = 0;
    virtual void setFecha(DTFecha fecha) = 0;
    virtual bool productoEnPromoExistente(int id) = 0;
    virtual bool compararFechas(DTFecha fecha1, DTFecha fecha2) = 0;
    virtual void seleccionarPromocion(string nombre) = 0;
    virtual void imprimirProductosDentroDePromo(vector<Contenido*>Promocion) = 0;
    virtual void confirmarAltaPromocion(float descuento, string nombre, string desc, DTFecha fecha_ven, string ref) = 0;
    virtual void cargarDatosPromocion() = 0;
    /*virtual void cargarDatosContenido() = 0;s
    virtual void confirmarAltaContenido() = 0;*/
};
#endif // ICPRODUCTOS_H