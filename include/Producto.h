#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <map>
#include "Vendedor.h"
#include "Comentario.h"
#include "../include/Controladores/ControladorProducto.h"
using namespace std;

class Producto {
private:
    int id;
    int stock;
    float precio;
    string nombre;
    string descripcion;
    Vendedor vendedor;
    map<int, Comentario *> Comentarios;

public:
    enum class Categoria
    {
        Ropa,
        Electrodomesticos,
        Otros
    }; // Enum declarado dentro de la clase Producto

    Producto(int id, int stock, float precio, string nombre, string descripcion, Categoria categoria);
    ~Producto();

    int getId();
    int getStock();
    float getPrecio();
    string getNombre();
    string getDescripcion();
    Vendedor getVendedor();
    std::map<int, Comentario *> getComentarios();

    void setId(int id);
    void setStock(int stock);
    void setPrecio(float precio);
    void setNombre(const string &nombre);
    void setDescripcion(const string &descripcion);
    void setVendedor(const Vendedor &vendedor);
    void setComentario(Comentario *);
};

vector<Producto *> productosSistema; // Set donde guardamos todos los productos del sistema, ordenados por ID (Codigo identificador)

#endif // PRODUCTO_H
