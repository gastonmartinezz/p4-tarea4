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