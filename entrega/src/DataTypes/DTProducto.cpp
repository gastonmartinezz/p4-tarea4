#include "DTProducto.h"
#include <map>

DTProducto::DTProducto(int id, int stock, float precio, string nombre, string descripcion, string categoria, string vendedor, std::map<int, Comentario *> Comentarios)
    : id(id), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), categoria(categoria), vendedor(vendedor), Comentarios(Comentarios) {}

int DTProducto::getId()
{
    return id;
}

int DTProducto::getStock()
{
    return stock;
}

float DTProducto::getPrecio()
{
    return precio;
}

string DTProducto::getNombre()
{
    return nombre;
}

string DTProducto::getDescripcion()
{
    return descripcion;
}

string DTProducto::getCategoria()
{
    return categoria;
}

string DTProducto::getVendedor()
{
    return vendedor;
}

DTProducto::~DTProducto() {}

ostream &operator<<(ostream &os, DTProducto dtProducto)
{
    os << "ID: " << dtProducto.getId() << ", Nombre: " << dtProducto.getNombre() << ", Precio: " << dtProducto.getPrecio() << ", Descripción: " << dtProducto.getDescripcion() << ", Categoría: " << dtProducto.getCategoria() << ", Vendedor: " << dtProducto.getVendedor();
    return os;
}
