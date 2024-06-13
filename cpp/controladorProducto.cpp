#include "controladorProducto.h"

// Agregar un Producto
void ProductoController::addProducto(Producto *producto)
{
    productos[std::to_string(producto->getId())] = producto;
}

// Eliminar un Producto por su id
void ProductoController::eliminarProducto(int id)
{
    auto it = productos.find(std::to_string(id));
    if (it != productos.end())
    {
        delete it->second; // Liberar la memoria del objeto Producto
        productos.erase(it);
    }
}

// Encontrar un Producto por su id
Producto *ProductoController::find(int id)
{
    auto it = productos.find(std::to_string(id));
    if (it != productos.end())
    {
        return it->second;
    }
    return nullptr;
}

// Listar todos los productos
std::vector<Producto *> ProductoController::listarProductos()
{
    std::vector<Producto *> listaProductos;
    for (const auto &pair : productos)
    {
        listaProductos.push_back(pair.second);
    }
    return listaProductos;
}
