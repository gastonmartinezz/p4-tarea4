#include "DTProducto.h"
#include <map>

DTProducto::DTProducto(int id, string nombre, int stock, float precio, string descripcion, string categoria, string vendedor, std::map<int, Comentario *> Comentarios)
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

void DTProducto::setNombre(string nombre)
{
    this->nombre = nombre;
}

void DTProducto::setStock(int stock)
{
    this->stock = stock;
}

void DTProducto::setPrecio(float precio)
{
    this->precio = precio;
}

void DTProducto::setId(int id)
{
    this->id = id;
}

void DTProducto::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void DTProducto::setCategoria(string categoria)
{
    this->categoria = categoria;
}

void DTProducto::setVendedor(string vendedor)
{
    this->vendedor = vendedor;
}

DTProducto::~DTProducto() {}

ostream &operator<<(ostream &os, DTProducto dtProducto)
{
    os << "ID: " << dtProducto.getId() << ", Nombre: " << dtProducto.getNombre() << ", Precio: " << dtProducto.getPrecio() << ", Descripción: " << dtProducto.getDescripcion() << ", Categoría: " << dtProducto.getCategoria() << ", Vendedor: " << dtProducto.getVendedor();
    return os;
}
