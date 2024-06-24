#include "../include/Vendedor.h"
#include "../include/DataTypes/DTVendedor.h"
#include <iostream>
#include <set>

Vendedor::Vendedor(const string &nickname, const string &password, const DTFecha &fechaDeNacimiento, std::string codigoRut)
    : Usuario(nickname, password, fechaDeNacimiento), codigoRut(codigoRut) {}

string Vendedor::getNickname()
{
    return nickname;
}

string Vendedor::getCodigoRut()
{
    return codigoRut;
}

set<Cliente *>& Vendedor::getSuscriptores()
{
    return suscriptores;
}

vector<Producto *> Vendedor::getProductos()
{
    return productos;
}

vector<Promocion *> Vendedor::getPromociones()
{
    return promociones;
}

void Vendedor::setCodigoRut(int codigoRut)
{
    this->codigoRut = codigoRut;
}

void Vendedor::agregarSuscriptor(Cliente *cliente)
{
    suscriptores.insert(cliente);
}

void Vendedor::eliminarSuscriptor(Cliente *cliente)
{
    suscriptores.erase(cliente);
}

void Vendedor::agregarProducto(Producto *producto)
{
    productos.push_back(producto);
}

void Vendedor::agregarPromocion(Promocion *promocion)
{
    promociones.push_back(promocion);
}

void Vendedor::mostrarInformacionVendedor() {
    // Implementación de la función para mostrar la información del vendedor
};

DTVendedor Vendedor::toDataType()
{
    return DTVendedor(getNickname(), getCodigoRut(), getFechaDeNacimiento(), getSuscriptores(), getProductos(), getPromociones());
};

Vendedor::~Vendedor()
{
    // Liberar memoria de los productos
    for (auto producto : productos)
    {
        delete producto;
    }
    productos.clear();

    // Liberar memoria de las promociones
    for (auto promocion : promociones)
    {
        delete promocion;
    }
    promociones.clear();

    // No liberamos memoria de los suscriptores porque no somos los dueños de esos punteros,
    // asumimos que otra parte del programa es responsable de ello.
    suscriptores.clear();
}