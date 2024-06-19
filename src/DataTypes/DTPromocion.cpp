#include "DTPromocion.h"

DTPromocion::DTPromocion(float descuento, string nombre, string descripcion, DTFecha fechaVencimiento)
    : descuento(descuento), nombre(nombre), descripcion(descripcion), fechaVencimiento(fechaVencimiento) {}

float DTPromocion::getDescuento() {
    return descuento;
}

string DTPromocion::getNombre() {
    return nombre;
}

string DTPromocion::getDescripcion() {
    return descripcion;
}

DTFecha DTPromocion::getFechaVencimiento() {
    return fechaVencimiento;
}

DTPromocion::~DTPromocion() {}

ostream& operator<<(ostream& os, DTPromocion dtPromocion) {
    os << "Descuento: " << dtPromocion.getDescuento() << ", Nombre: " << dtPromocion.getNombre() << ", Descripción: " << dtPromocion.getDescripcion() << ", Fecha de Vencimiento: " << dtPromocion.getFechaVencimiento();
    return os;
}