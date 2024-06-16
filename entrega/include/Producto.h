#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

class Producto {
private:
    int id;
    int stock;
    float precio;
    std::string nombre;
    std::string descripcion;

public:
    enum class Categoria { Ropa, Electrodomesticos, Otros }; // Enum declarado dentro de la clase Producto

    Producto();
    Producto(int id, int stock, float precio, std::string nombre, std::string descripcion, Categoria categoria);
    int getId();
    int getStock();
    float getPrecio();
    std::string getNombre();
    std::string getDescripcion();
    ~Producto();
};

#endif // PRODUCTO_H




