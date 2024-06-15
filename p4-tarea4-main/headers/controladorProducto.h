#include "producto.h"
#include <map>
#include <string>
#include <vector>

class ProductoController
{
private:
    std::map<int, Producto *> productos;

public:
    // Agregar un Producto
    void addProducto(Producto *user);

    // Eliminar un Producto por su id
    void eliminarProducto(int id);

    // Encontrar un Producto por su id
    Producto *find(int id);

    std::vector<Producto *> listarProductos();
};
