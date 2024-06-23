#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>
#include <map>
#include "Vendedor.h"
#include "Comentario.h"
#include "Categoria.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/DataTypes/DTProducto.h"

class Vendedor;
using namespace std;

class Producto
{
private:
    int id;
    int stock;
    float precio;
    string nombre;
    string descripcion;
    Categoria categoria;
    Vendedor *quienVende;
    map<int, Comentario *> Comentarios;

public:
    Producto(int id, int stock, float precio, string nombre, string descripcion, Categoria categoria, Vendedor *quienVende);
    ~Producto();

    int getId();
    int getStock();
    float getPrecio();
    string getNombre();
    string getDescripcion();
    Vendedor *getVendedor();
    std::map<int, Comentario *> getComentarios();

    void setId(int id);
    void setStock(int stock);
    void setPrecio(float precio);
    void setNombre(const string &nombre);
    void setDescripcion(const string &descripcion);
    void setVendedor(Vendedor *vendedor);
    DTProducto toDataType();
    void addComentario(Comentario *coment);

    // void setComentario(Comentario *);
};

// vector<Producto *> productosSistema; // Set donde guardamos todos los productos del sistema, ordenados por ID (Codigo identificador)

#endif // PRODUCTO_H
