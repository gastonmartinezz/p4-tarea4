
#include <iostream>
#include <string>

class Producto
{
private:
    int id;
    int stock;
    float precio;
    std::string nombre;
    std::string descripcion;
    enum categoria {Ropa, Electodomesticos, otros};

public:
    Producto();
    Producto(int id, int stock, float precio, std::string nombre, std::string descripcion, categoria);
    int getId();
    int getStock();
    float getPrecio();
    std::string getNombre();
    std::string getDescripcion();
    void agregarAlCarrito();
    void removeComentario();
    ~Producto();
};