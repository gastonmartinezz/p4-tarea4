#ifndef CONTROLADORPRODUCTO_H
#define CONTROLADORPRODUCTO_H

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <map>
#include "../include/DataTypes/DTFecha.h"
#include "../include/Producto.h"
#include "../include/Promocion.h"
#include "../include/Comentario.h"
#include "../include/Compra.h"
#include "../include/contenido.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/DataTypes/DTProducto.h"
#include "../include/DataTypes/DTVendedor.h"
#include "../Interfaces/ICProductos.h"
#include "../include/Categoria.h"
#include "../include/DataTypes/DTContenido.h"
using namespace std;

class Producto;
class Promocion;
class Comentario;
class Compra;
class DTProducto;
class DTVendedor;
class Contenido;
class DTFecha;

class ControladorProducto /* : public ICProductos */
{
private:
    // Constructor privado para el patrón Singleton
    ControladorProducto() = default;
    static ControladorProducto *instance;
    map<int, Producto*> listaProductos;
    vector<Promocion*> promocionesSistemaVigentes;
    vector<Promocion*> promocionesSistema;
    int contador_id_producto;
    static DTFecha fecha;

public:
    // Métodos estáticos para obtener la instancia única
    static ControladorProducto *getInstance();

    // Métodos del diagrama UML
    Producto* getProducto(int idProducto);
    map<int, Producto*> getListaProductos();
    vector<DTProducto> listarProductos2();
    void listarProductos(); // es un void ya que es hacer 'cout'
    void agregarALaLista(int id,Producto* prod);
    void listarProductosVendedor(string nickname, vector<DTVendedor> lista);
    void eliminarLinkComentario(int comentarioId);
    void agregarProducto(const Producto &producto);
    void ponerProductosLibres();
    void ingresarDatos(const string &nombre, float precio, int stock);
    void crearPromocion(const string &nombre, float descuento, const DTFecha &fechaVen);
    float sumaDeLosPrecios() const;
    bool productoEstaEnDetalleCompra(int productoId, int compraId) const;
    void agregarProductoACarrito(int productoId);
    void cancelar();
    void confirmarCompra();
    void registrarCompra(const Compra &compra);
    void desplegarCompra(int compraId) const;
    DTFecha getFecha();
    void setFecha(DTFecha fecha);
    int getContador();
    void setContador(int valorContador);
    void AddComentario(Comentario *coment, int producto);
    void incrementarContador();
    vector<Promocion*> getpromocionesSistemaVigentes();
    vector<Promocion*> getpromocionesSistema();
    void setPromocionesSistemaVigentes(vector<Promocion*> promoSisV);
    void setPromocionesSistema(vector<Promocion*> promoSis);
    void obtenerPromocionesActivas(DTFecha fecha);
    bool productoEnPromoExistente(int id);
    bool compararFechas(DTFecha fecha1, DTFecha fecha2);
    void seleccionarPromocion(string nombre);
    void imprimirProductosDentroDePromo(vector<Contenido*>Promocion);
};

#endif // CONTROLADORPRODUCTO_H