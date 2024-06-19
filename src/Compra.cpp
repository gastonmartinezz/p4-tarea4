#include <string>
#include <iostream>
#include <ctime>
#include "../include/Compra.h"

Compra::Compra(float monto_total, DTFecha fecha, vector<carro>& carrito)
    : monto_total(monto_total), fecha(fecha), carrito(carrito) {
    // Constructor: inicialización de atributos
}

float Compra::getMonto_total() const {
    return monto_total;
}

DTFecha Compra::getFecha_de_la_compra() const {
    return fecha;
}

vector<carro> Compra::getCarrito() const {
    return carrito;
}

void Compra::setMonto_total(float monto_total) {
    this->monto_total = monto_total;
}

void Compra::setFecha_de_la_compra(DTFecha fecha) {
    this->fecha = fecha;
}

void Compra::setCarrito(const vector<carro>& carrito) {
    this->carrito = carrito;
}

Compra::~Compra() {
    // Destructor: limpieza o liberación de recursos
}