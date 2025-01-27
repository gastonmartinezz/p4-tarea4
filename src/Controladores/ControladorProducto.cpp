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

//Funcion para comparar fechas
bool ControladorProducto::compararFechas(DTFecha fecha1, DTFecha fecha2) {
    //Retorna true si fecha2 > fecha1
    if (fecha1.getAnio() < fecha2.getAnio()) return true;
    if (fecha1.getAnio() > fecha2.getAnio()) return false;
    if (fecha1.getMes() < fecha2.getMes()) return true;
    if (fecha1.getMes() > fecha2.getMes()) return false;
    if (fecha1.getDia() < fecha2.getDia()) return true;
    if (fecha1.getDia() > fecha2.getDia()) return false;
    return false;
}

void ControladorProducto::obtenerPromocionesActivas(DTFecha fecha) {
    promocionesSistemaVigentes.clear();

    for (auto f: promocionesSistema) {
        if (compararFechas(fecha, f->getFechaVencimiento())) {
            vector<Promocion*> promocionesVigentes = getpromocionesSistemaVigentes();
            promocionesVigentes.push_back(f);
            setPromocionesSistemaVigentes(promocionesVigentes);
        }
    }

    for (auto promociones: promocionesSistemaVigentes) {
        cout << "Promociones Vigentes: " << endl;
        cout << "----------------------" << endl;
        cout << "Nombre de la promocion: " << promociones->getNombre() << endl;
        cout << "Descripcion de la promocion: " << promociones->getDescripcion() << endl;
        cout << "Descuento de la promocion: " << promociones->getDescuento() << endl;
        cout << "Fecha de Vencimiento de la promocion: " << promociones->getFechaVencimiento().toString() << endl;
        cout << "Vendedor de la promocion: " << promociones->getVendedor()->getNickname() << endl;
    } 
}

void ControladorProducto::confirmarAltaPromocion(float descuento, string nombre, string desc, DTFecha fecha_ven, string ref) {
    vector<Promocion*> promociones;

    Promocion* nP = new Promocion(descuento, nombre, desc, fecha_ven);
    nP->setReferencia(ref);
    vector<Promocion*> promocionesVigentes = getpromocionesSistema();
    promocionesVigentes.push_back(nP);
    setPromocionesSistema(promocionesVigentes);
}

void ControladorProducto::cargarDatosPromocion() {
    DTFecha fechaPM1 = DTFecha(25,10, 2024);
    DTFecha fechaPM2 = DTFecha(26,10, 2024);
    DTFecha fechaPM3 = DTFecha(26,10, 2024);
    DTFecha fechaPM4 = DTFecha(26,3, 2024);

    string descPM1 = "Para que puedas ahorrar en la casa nueva";
    string descPM2 = "Para que no te quedes sin ropa para las fiestas";
    string descPM3 = "Para modernizar tu casa";
    string descPM4 = "Hasta agotar stock";

    string nombrePM1 = "Casa nueva";
    string nombrePM2 = "Fiesta";
    string nombrePM3 = "Domotica";
    string nombrePM4 = "Liquidacion";
    
    string refPM1 = "PM1";
    string refPM2 = "PM2";
    string refPM3 = "PM3";
    string refPM4 = "PM4";

    confirmarAltaPromocion(30, nombrePM1, descPM1, fechaPM1, refPM1);
    confirmarAltaPromocion(20, nombrePM2, descPM2, fechaPM2, refPM2);
    confirmarAltaPromocion(10, nombrePM3, descPM3, fechaPM3, refPM3);
    confirmarAltaPromocion(10, nombrePM4, descPM4, fechaPM4, refPM4);

    for (auto promo : promocionesSistema) {
        cout << "Promoción agregado con éxito: " << endl ;
        cout << "Nombre de la promoción: " << promo->getNombre() << endl;
        cout << "Descripción de la promoción: " << promo->getDescripcion() << endl;
        cout << "Referencia de la promoción: " << promo->getReferencia() << endl;
    }
}
/*
void ControladorProducto::confirmarAltaContenido(Producto* prod, int cantMin, string refCont) {
    vector<Promocion*> promociones;

    Contenido* cP = new Contenido(prod, cantMin);
    cP->setReferencia(refCont);
    vector<Promocion*> promocionesVigentes = getpromocionesSistema();
    promocionesVigentes.push_back(nP);
    setPromocionesSistema(promocionesVigentes);
}

void ControladorProducto::cargarDatosContenido() {

    string descPM1 = "Para que puedas ahorrar en la casa nueva";
    string descPM2 = "Para que no te quedes sin ropa para las fiestas";
    string descPM3 = "Para modernizar tu casa";
    string descPM4 = "Hasta agotar stock";

    string nombrePM1 = "Casa nueva";
    string nombrePM2 = "Fiesta";
    string nombrePM3 = "Domotica";
    string nombrePM4 = "Liquidacion";

    string refPP1 = "PP1";
    string refPP2 = "PP2";
    string refPP3 = "PP3";
    string refPP4 = "PP4";
    string refPP5 = "PP5";
    string refPP6 = "PP6";
    string refPP7 = "PP7";

    Producto* nV1 = new Producto();
    Producto* nV2 = new Producto();
    Producto* nV3 = new Producto();
    Producto* nV4 = new Producto();
    Producto* nV5 = new Producto();
    Producto* nV6 = new Producto();
    Producto* nV7 = new Producto();

    confirmarAltaContenido(nV1, 1, refPP1);
    confirmarAltaContenido(nV2, 1, refPP2);
    confirmarAltaContenido(nV3, 1, refPP3);
    confirmarAltaContenido(nV4, 2, refPP4);
    confirmarAltaContenido(nV5, 3, refPP5);
    confirmarAltaContenido(nV6, 2, refPP6);
    confirmarAltaContenido(nV7, 1, refPP7);
    


    for (auto promo : promocionesSistema) {
        cout << "Promoción agregado con éxito: " << endl ;
        cout << "Nombre de la promoción: " << promo->getNombre() << endl;
        cout << "Descripción de la promoción: " << promo->getDescripcion() << endl;
    }
}*/

void ControladorProducto::seleccionarPromocion(string nombre) {
    transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper); //transformar el string de minúscula a mayúscula

    bool encontrada = false;
    for (auto promo: promocionesSistemaVigentes) {
        string nombrePromocion = promo->getNombre();

        transform(nombrePromocion.begin(), nombrePromocion.end(), nombrePromocion.begin(), ::toupper);

        if (nombre == nombrePromocion) {
            DTPromocion promoNueva = promo->toDataType();
            DTVendedor vendedor = promo->getVendedor()->toDataType();

            promoNueva.setVendedor(promo->getVendedor());
            cout << "Nombre de la promocion: " << promoNueva.getNombre() << endl;
            cout << "Vendedor de la promocion: " << vendedor.getNickname() << endl;
            cout << "RUT del vendedor: " << vendedor.getRut() << endl;

            for (auto productos: promo->getProductosDentroDePromo()) {
                DTProducto prod = productos->getProducto()->toDataType();
                prod.setStock(productos->getProducto()->getStock());
                prod.setDescripcion(productos->getProducto()->getDescripcion());

                DTContenido contenidou = productos->toDataType();

                cout << "Nombre del producto: " << prod.getNombre() << endl;
                cout << "Id del producto: " << prod.getId() << endl;
                cout << "Descripcion del producto: " << prod.getDescripcion() << endl;
                cout << "Stock del producto: " << prod.getStock() << endl;
                cout << "Cantidad mínima para la promoción: " << contenidou.getCantMinima() << endl;
            }
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "No se encontró ninguna promoción con ese nombre." << endl;
    }
}

bool ControladorProducto::productoEnPromoExistente(int id) {
    if (promocionesSistemaVigentes.empty()) {
        return false;
    }

    for (Promocion* promocion : promocionesSistemaVigentes) {

        for (Contenido* contenido : promocion->getProductosDentroDePromo()) {
            Producto* producto = contenido->getProducto();

            if (producto) {
                if (producto->getId() == id) {
                    return true;
                }
            } 
        }
    }

    return false;
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
        DTContenido contenidou = contenido->toDataType();
        DTProducto producto = contenido->getProducto()->toDataType();

        cout << "Producto: " << producto.getNombre() << endl;
        cout << "Cantidad mínima: " << contenidou.getCantMinima() << endl;
    }
}

void ControladorProducto::setPromocionesSistemaVigentes(vector<Promocion*> promoSisV) {
    this->promocionesSistemaVigentes = promoSisV;
}

void ControladorProducto::setPromocionesSistema(vector<Promocion*> promoSis) {
    this->promocionesSistema = promoSis;
}