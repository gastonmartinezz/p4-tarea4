#include <Promocion.h>
#include <Vendedor.h>
#include <contenido.h>
using namespace std;

Promocion::Promocion(float descuento, string nombre, string descripcion, DTFecha fecha_vencimiento)
    : descuento(descuento), nombre(nombre), descripcion(descripcion), fecha_vencimiento(fecha_vencimiento), 
    vendedor() {} //revisar constructor default en vendedor.h

Promocion::~Promocion() {
    for (auto prod: productosDentroDePromo) {
        delete prod;
    }

    productosDentroDePromo.clear();
}

// Métodos de acceso 'Get'
float Promocion::getDescuento() {
    return descuento;
}

string Promocion::getNombre() {
    return nombre;
}

string Promocion::getDescripcion() {
    return descripcion;
}

DTFecha Promocion::getFechaVencimiento() {
    return fecha_vencimiento;
}

set<Contenido*> Promocion::getProductosDentroDePromo() {
    return productosDentroDePromo;
}

Vendedor* Promocion::getVendedor() {
    return vendedor;
}

//Métodos de acceso 'Set'
void Promocion::setDescuento(float descuento) {
    this->descuento = descuento;
}

void Promocion::setNombre(string nombre) {
    this->nombre = nombre;
}

void Promocion::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Promocion::setFechaVencimiento(DTFecha fecha) {
    this->fecha_vencimiento = fecha;
    //Corregir esto mas adelante cuando tengamos bien implementado DTFecha (corregir tambien en el .h). A su vez, fijarse bien como implementar bien la fecha como atributo ya que puede haber problema con el formato dentro de la clase.
}

void Promocion::setVendedor(Vendedor* vendedor) {
    this->vendedor = vendedor;
}

// Otros métodos
void Promocion::agregarProducto(Contenido *contenido) {
    productosDentroDePromo.insert(contenido);
}
