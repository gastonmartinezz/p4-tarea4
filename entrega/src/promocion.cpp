#include "Promocion.h"
#include "Vendedor.h"

// Constructor
Promocion::Promocion(float descuento, std::string nombre, std::string descripcion, DTFecha fecha_vencimiento)
    : descuento(descuento), nombre(nombre), descripcion(descripcion), fecha_vencimiento(fecha_vencimiento) {}

// Destructor
Promocion::~Promocion() {
    // No se requiere implementación específica si no hay recursos dinámicos que liberar
}

// Métodos de acceso
float Promocion::getDescuento() {
    return descuento;
}

std::string Promocion::getNombre() const {
    return nombre;
}

DTFecha Promocion::getFechaVencimiento() {
    return fecha_vencimiento;
}

Vendedor Promocion::getVendedor() {
    return vendedor;
}

// Otros métodos
void Promocion::agregarProducto(Producto* prod) {
    productosDentroDePromo.insert(prod);
}
