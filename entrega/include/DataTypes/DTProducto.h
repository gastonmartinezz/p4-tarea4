#ifndef DTPRODUCTO_H
#define DTPRODUCTO_H

#include <iostream>
#include <string>

using namespace std;

class DTProducto {
private:
    int id;
    int stock;
    float precio;
    string nombre;
    string descripcion;
    string categoria;
    string vendedor;

public:
    DTProducto(int id, int stock, float precio, string nombre, string descripcion, string categoria, string vendedor);
    int getId();
    int getStock();
    float getPrecio();
    string getNombre();
    string getDescripcion();
    string getCategoria();
    string getVendedor();
    ~DTProducto();
};

ostream& operator<<(ostream& os, DTProducto dtProducto);

#endif // DTPRODUCTO_H
