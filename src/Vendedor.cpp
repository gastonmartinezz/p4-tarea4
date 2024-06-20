#include "../include/Vendedor.h"
#include "../include/DataTypes/DTVendedor.h"
#include <iostream>
#include <set>

Vendedor::Vendedor(const string &nickname, const string &password, const DTFecha &fechaDeNacimiento, int codigoRut): 
Usuario(nickname, password, fechaDeNacimiento), codigoRut(codigoRut) {}

int Vendedor::getCodigoRut() {
    return codigoRut;
}

set<Cliente*> Vendedor::getSuscriptores() {
    return suscriptores;
}

vector<Producto*> Vendedor::getProductos() {
    return productos;
}

vector<Promocion*> Vendedor::getPromociones() {
    return promociones;
}

void Vendedor::setCodigoRut(int codigoRut) {
    this->codigoRut = codigoRut;
}

void Vendedor::agregarSuscriptor(Cliente* cliente) {
    suscriptores.insert(cliente);
}

void Vendedor::eliminarSuscriptor(Cliente* cliente) {
    suscriptores.erase(cliente);
}

void Vendedor::agregarProducto(Producto* producto) {
    productos.push_back(producto);
}

void Vendedor::agregarPromocion(Promocion* promocion) {
    promociones.push_back(promocion);
}

void Vendedor::mostrarInformacionVendedor() {
    // Implementación de la función para mostrar la información del vendedor
};

void Vendedor::toDataType() {
    DTVendedor(getCodigoRut(), getProductos(), getPromociones());
};