#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

#include <iostream>
#include <string>
#include <Comentario.h>

using namespace std;

class DTProducto
{
private:
    int id;
    int stock;
    float precio;
    string nombre;
    string descripcion;
    string categoria;
    string vendedor;
    map<int, Comentario *> Comentarios;

public:
    // DTProducto(int id, int stock, float precio, string nombre, string descripcion, string categoria, string vendedor, std::map<int, Comentario *> Comentarios);
    DTProducto(int id = 0, std::string nombre = "", int stock = 0, float precio = 0.0, std::string descripcion = "", std::string categoria = "", std::string vendedor = "", std::map<int, Comentario *> comentarios = std::map<int, Comentario *>());

    int getId();
    int getStock();
    float getPrecio();
    string getNombre();
    string getDescripcion();
    string getCategoria();
    string getVendedor();
    std::map<int, Comentario *> getComentarios();

    void setNombre(string nombre);
    void setStock(int stock);
    void setPrecio(float precio);
    void setId(int id);
    void setDescripcion(string descripcion);
    void setCategoria(string categoria);
    void setVendedor(string vendedor);

    void addComentario(Comentario *);
    ~DTProducto();
};

ostream &operator<<(ostream &os, DTProducto dtProducto);

#endif // DTPRODUCTO_H
