#include "../include/Vendedor.h"
#include "../include/DataTypes/DTVendedor.h"
#include <iostream>
#include <set>

Vendedor::Vendedor(const string &nickname, const string &password, const DTFecha &fechaDeNacimiento, int codigoRut): 
Usuario(nickname, password, fechaDeNacimiento), codigoRut(codigoRut) {}

int Vendedor::getCodigoRut() const {
    return codigoRut;
}

set<Cliente*> Vendedor::getSuscriptores() const {
    return suscriptores;
}

vector<Producto*> Vendedor::getProductos() const {
    return productos;
}

vector<Promocion*> Vendedor::getPromociones() const {
    return promociones;
}

void Vendedor::setCodigoRut(int codigoRut) {
    this->codigoRut = codigoRut;
}

void Vendedor::agregarSuscriptor(const Cliente &cliente) {
    suscriptores.insert(cliente);
}

void Vendedor::eliminarSuscriptor(const Cliente &cliente) {
    suscriptores.erase(cliente);
}

void Vendedor::agregarProducto(const Producto &producto) {
    productos.push_back(producto);
}

void Vendedor::agregarPromocion(const Promocion &promocion) {
    promociones.push_back(promocion);
}

void Vendedor::mostrarInformacion() const {
    // Implementación de la función para mostrar la información del vendedor
};
DTVendedor Vendedor::toDataType() {
    DTVendedor(getCodigoRut(), getProductos(), getPromociones());
};
