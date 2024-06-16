#include "../include/Vendedor.h"
#include "../include/DTVendedor.h"
#include <iostream>

Vendedor::Vendedor(const std::string &nickname, const std::string &password, const DTFecha &fechaDeNacimiento,
                   int codigoRut)
    : Usuario(nickname, password, fechaDeNacimiento), codigoRut(codigoRut) {}

int Vendedor::getCodigoRut() const
{
    return codigoRut;
}

std::set<Cliente> Vendedor::getSuscriptores() const
{
    return suscriptores;
}

std::vector<Producto> Vendedor::getProductos() const
{
    return productos;
}

std::vector<Promocion> Vendedor::getPromociones() const
{
    return promociones;
}

void Vendedor::setCodigoRut(int codigoRut)
{
    this->codigoRut = codigoRut;
}

void Vendedor::agregarSuscriptor(const Cliente &cliente)
{
    suscriptores.insert(cliente);
}

void Vendedor::eliminarSuscriptor(const Cliente &cliente)
{
    suscriptores.erase(cliente);
}

void Vendedor::agregarProducto(const Producto &producto)
{
    productos.push_back(producto);
}

void Vendedor::agregarPromocion(const Promocion &promocion)
{
    promociones.push_back(promocion);
}

void Vendedor::mostrarInformacion() const
{
    // Implementación de la función para mostrar la información del vendedor
}

DTVendedor Vendedor::toDataType() {

    DTVendedor(getCodigoRut(), getProductos(), getPromociones())
};
