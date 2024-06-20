#include "../include/DataTypes/DTCompra.h"

DTCompras::DTCompras(string nombreCliente, DTFecha fechaCompra)
    : nombreCliente(nombreCliente), fechaCompra(fechaCompra) {}

string DTCompras::getNombreCliente() {
    return nombreCliente;
}

DTFecha DTCompras::getFechaCompra() {
    return fechaCompra;
}

void DTCompras::setNombreCliente(string nombreCliente){
    this->nombreCliente = nombreCliente;
}
void DTCompras::setFechaCompra(DTFecha fecha) {
    this->fechaCompra = fecha;
}

DTCompras::~DTCompras() {}

ostream& operator<<(ostream& os, DTCompras dtCompras) {
    os << "Nombre del Cliente: " << dtCompras.getNombreCliente() << ", Fecha de Compra: " << dtCompras.getFechaCompra();
    return os;
}
