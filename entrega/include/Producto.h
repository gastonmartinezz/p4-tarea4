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

    Producto();
    Producto(int id, int stock, float precio, string nombre, string descripcion, Categoria categoria);
    int getId();
    int getStock();
    float getPrecio();
    string getNombre();
    string getDescripcion();
    ~Producto();
    Vendedor getVendedor(); //hay que implementar este metodo en el .cpp xq es nuevo
};

set<Producto *> productosSistema; //Set donde guardamos todos los productos del sistema, ordenados por ID (Codigo identificador)

#endif // PRODUCTO_H

/* TRABAJO MANUEL
#include <iostream>
#include <string>
#include <dataTypes.h>
#include <Vendedor.h>

class Producto {
private:
    int id;
    int stock;
    float precio;
    std::string nombre;
    std::string descripcion;
    EnumCategoria cat;
    Vendedor vendedor;

public:
    Producto();
    Producto(int id, int stock, float precio, std::string nombre, std::string descripcion, EnumCategoria categoria);
    int getId();
    int getStock();
    float getPrecio();
    std::string getNombre();
    std::string getDescripcion();
    void agregarAlCarrito();
    void removeComentario();
    ~Producto();
};
*/


