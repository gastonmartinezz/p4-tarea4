#ifndef CONTROLADORPRODUCTO_H
#define CONTROLADORPRODUCTO_H

#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <map>
#include "../include/Producto.h"
#include "../include/Promocion.h"
#include "../include/Comentario.h"
#include "../include/Compra.h"
#include "../include/contenido.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/DataTypes/DTProducto.h"
#include "../include/DataTypes/DTVendedor.h"
#include "../Interfaces/ICProductos.h"
using namespace std;

class Producto;
class Promocion;
class Comentario;
class Compra;
class DTProducto;
class DTVendedor;
class Contenido;

class ControladorProducto /* : public ICProductos */
{
private:
    // Constructor privado para el patrón Singleton
    ControladorProducto() = default;
    static ControladorProducto *instance;
    map<int, Producto*> listaProductos;
    vector<Promocion*> promocionesSistemaVigentes;
    vector<Promocion*> promocionesSistema;
    int contador_id_producto = 0;

public:
    // Métodos estáticos para obtener la instancia única
    static ControladorProducto *getInstance();

    // Métodos del diagrama UML
    vector<DTProducto> listarProductos2();
    Producto* getProducto(int idProducto);
    map<int, Producto*> getListaProductos();
    void listarProductos(); // es un void ya que es hacer 'cout'
    void agregarALaLista(int id,Producto* prod);
    void confirmarAltaPromocion();
    void ingresarDatosPromocion(const string &nombre, float descuento, const DTFecha &fechaVen);
    void listarProductosVendedor(string nickname, std::vector<DTVendedor> lista);
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
    
    //void obtenerProductosDeVendedor(string nickname);
    void ingresarPromocionASistema(Promocion promo);
    void AddComentario(Comentario *coment, int producto);
    void incrementarContador();
    int getContador();
    Contenido* seleccionarProductosParaPromocion(vector<DTVendedor>lista, string nickname, Producto* prod, int cant_minima, int id);
    vector<Promocion*> getpromocionesSistemaVigentes();
    vector<Promocion*> getpromocionesSistema();
    //Contenido* seleccionarProductosParaPromocion(string nickname, Producto* prod, int cant_minima); 

    //map<int, Producto*> getListaProductos();
    //map<int, Contenido*> getPromocionesSistema();
    //map<int, Contenido*> getPromocionesSistemaVigentes();
    //void ingresarPromocionVigente(Promocion* promo, int cant_minima, map<int, Contenido*> promocionesSistemaVigentes);
    //void obtenerPromocionesActivas(DTFecha fecha);
    bool productoEnPromoExistente(int id);
    //bool compararFechas(DTFecha fecha1, DTFecha fecha2);
    //void seleccionarPromocion(string nombre);
};

#endif // CONTROLADORPRODUCTO_H