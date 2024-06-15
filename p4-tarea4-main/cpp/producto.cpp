#include <producto.h>
#include <iostream>
#include <string>

Producto::Producto(int id, int stock, float precio, std::string nombre, std::string descripcion, categoria) : id(id), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), categoria(categoria) {};

int Producto::getId() { return id; };
int Producto::getStock() { return stock; };
std::string Producto::getNombre() { return nombre; };
std::string Producto::getDescripcion() { return descripcion; };
Producto::~Producto(){};