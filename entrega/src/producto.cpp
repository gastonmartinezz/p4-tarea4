#include "../include/Producto.h"

Producto::Producto() : id(0), stock(0), precio(0.0f), nombre(""), descripcion("") {}

Producto::Producto(int id, int stock, float precio, std::string nombre, std::string descripcion, Categoria categoria)
    : id(id), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion) {
    // Aquí deberías inicializar la categoría, pero como no la estás usando, la puedes eliminar
}

int Producto::getId() { return id; }

int Producto::getStock() { return stock; }

float Producto::getPrecio() { return precio; }

std::string Producto::getNombre() { return nombre; }

std::string Producto::getDescripcion() { return descripcion; }

Producto::~Producto() {}
/*
#include <producto.h>
#include <iostream>
#include <string>

Producto::Producto(int id, int stock, float precio, std::string nombre, std::string descripcion, categoria) : id(id), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), categoria(categoria) {};

int Producto::getId() { return id; };
int Producto::getStock() { return stock; };
std::string Producto::getNombre() { return nombre; };
std::string Producto::getDescripcion() { return descripcion; };
Producto::~Producto(){};
*/