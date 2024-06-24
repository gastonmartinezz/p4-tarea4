#include "DTPromocion.h"

DTPromocion::DTPromocion(float descuento, string nombre, string descripcion, DTFecha fechaVencimiento)
    : descuento(descuento), nombre(nombre), descripcion(descripcion), fechaVencimiento(fechaVencimiento) {}

float DTPromocion::getDescuento()
{
    return descuento;
}

string DTPromocion::getNombre()
{
    return nombre;
}

string DTPromocion::getDescripcion()
{
    return descripcion;
}

DTFecha DTPromocion::getFechaVencimiento()
{
    return fechaVencimiento;
}

DTPromocion::~DTPromocion() {}

ostream &operator<<(ostream &os, DTPromocion dtPromocion)
{
    DTFecha fecha = dtPromocion.getFechaVencimiento();
    os << "Descuento: " << dtPromocion.getDescuento() << ", Nombre: " << dtPromocion.getNombre() << ", Descripción: " << dtPromocion.getDescripcion() << ", Fecha de Vencimiento: " << fecha.toString();
    return os;
}

void DTPromocion::setVendedor(Vendedor* vendedor) { 
    this->vendedor = vendedor;
}

Vendedor* DTPromocion::getVendedor() {
    return vendedor;
}