#include "controladorProducto.h"
#include <iostream>

// Agregar un Producto al map
void ProductoController::addProducto(Producto *producto)
{
    if (productos.find(producto->getId()) == productos.end())
    {
        productos[producto->getId()] = producto;
        std::cout << "Producto con ID " << producto->getId() << " agregado exitosamente." << std::endl;
    }
    else
    {
        std::cout << "El producto con ID " << producto->getId() << " ya existe." << std::endl;
    }
}

// Eliminar un Producto por su id
void ProductoController::eliminarProducto(int id)
{
    auto it = productos.find(id);
    if (it != productos.end())
    {
        delete it->second; // Liberar la memoria del objeto Producto
        productos.erase(it);
        std::cout << "Producto con ID " << id << " eliminado exitosamente." << std::endl;
    }
    else
    {
        std::cout << "El producto con ID " << id << " no existe." << std::endl;
    }
}

// Encontrar un Producto por su id
Producto *ProductoController::find(int id)
{
    auto it = productos.find(id);
    if (it != productos.end())
    {
        return it->second;
    }
    std::cout << "El producto con ID " << id << " no existe." << std::endl;
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
