#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <Vendedor.h>
using namespace std;

class Producto {
private:
    int id;
    int stock;
    float precio;
    string nombre;
    string descripcion;
    Vendedor vendedor;

public:
    enum class Categoria { Ropa, Electrodomesticos, Otros }; // Enum declarado dentro de la clase Producto

    Producto(int id, int stock, float precio, string nombre, string descripcion, Categoria categoria);
    ~Producto();
     
    int getId();
    int getStock();
    float getPrecio();
    string getNombre();
    string getDescripcion();
    ~Producto();
    Vendedor getVendedor(); 

    void setId(int id);
    void setStock(int stock);
    void setPrecio(float precio);
    void setNombre(const string& nombre);
    void setDescripcion(const string& descripcion);
    void setVendedor(const Vendedor& vendedor);
};

set<Producto *> productosSistema; //Set donde guardamos todos los productos del sistema, ordenados por ID (Codigo identificador)

#endif // PRODUCTO_H




