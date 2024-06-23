#include "../include/Promocion.h"
#include "../include/Producto.h"

// Producto::Producto() : id(0), stock(0), precio(0.0f), nombre(""), descripcion("") {}

Producto::Producto(int id, int stock, float precio, string nombre, string descripcion, Categoria categoria, Vendedor *quienVende) : id(id), precio(precio), nombre(nombre), descripcion(descripcion), categoria(categoria), quienVende(quienVende){};

int Producto::getId() { return id; }

int Producto::getStock() { return stock; }

float Producto::getPrecio() { return precio; }

std::string Producto::getNombre() { return nombre; }

std::string Producto::getDescripcion() { return descripcion; }

Vendedor *Producto::getVendedor() { return quienVende; }

std::map<int, Comentario *> Producto::getComentarios()
{
    return Comentarios;
};

void Producto::setId(int id) { this->id = id; }

void Producto::setStock(int stock) { this->stock = stock; }

void Producto::setPrecio(float precio) { this->precio = precio; }

void Producto::setNombre(const string &nombre) { this->nombre = nombre; }

void Producto::setDescripcion(const string &descripcion) { this->descripcion = descripcion; }

void Producto::setVendedor(Vendedor *vendedor) { this->quienVende = vendedor; }

DTProducto Producto::toDataType()
{
    return DTProducto(getId(), getNombre(), getComentarios());
}

void Producto::addComentario(Comentario *coment)
{
    Comentarios[coment->getId()] = coment;
}

Producto::~Producto() {}