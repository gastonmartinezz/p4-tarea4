#include "../include/Promocion.h"
#include "../include/Producto.h"

Producto::Producto() : id(0), stock(0), precio(0.0f), nombre(""), descripcion("") {}

Producto::Producto(int id, int stock, float precio, std::string nombre, std::string descripcion, Categoria categoria, const Vendedor& vendedor)
    : id(id), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), vendedor(vendedor) {
    // Aquí deberías inicializar la categoría, pero como no la estás usando, la puedes eliminar
}

int Producto::getId() { return id; }

int Producto::getStock() { return stock; }

float Producto::getPrecio() { return precio; }

std::string Producto::getNombre() { return nombre; }

std::string Producto::getDescripcion() { return descripcion; }

Vendedor Producto::getVendedor() { return vendedor; }

void Producto::setId(int id) { this->id = id; }

void Producto::setStock(int stock) { this->stock = stock; }

void Producto::setPrecio(float precio) { this->precio = precio; }

void Producto::setNombre(const string& nombre) { this->nombre = nombre; }

void Producto::setDescripcion(const string& descripcion) { this->descripcion = descripcion; }

void Producto::setVendedor(const Vendedor& vendedor) { this->vendedor = vendedor; }

Producto::~Producto() { delete producto; }