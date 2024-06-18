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
    std::map<int, Comentario *> Comentarios;

public:
    DTProducto(int id, int stock, float precio, string nombre, string descripcion, string categoria, string vendedor, std::map<int, Comentario *> Comentarios;);
    int getId();
    int getStock();
    float getPrecio();
    string getNombre();
    string getDescripcion();
    string getCategoria();
    string getVendedor();
    std::map<int, Comentario *> getComentarios();
    void addComentario(Comentario *) ~DTProducto();
};

ostream &operator<<(ostream &os, DTProducto dtProducto);

#endif // DTPRODUCTO_H
