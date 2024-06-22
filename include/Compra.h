#ifndef COMPRA_H
#define COMPRA_H

#include <vector>
#include "Producto.h"
#include "../include/DataTypes/DTProducto.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/DataTypes/DTCarro.h"
using namespace std;

class Producto;
class DTProducto;

class Compra
{
private:
    float monto_total;
    DTFecha fecha;
    vector<DTCarro> carrito;

public:
    Compra(float monto_total, DTFecha fecha, vector<DTCarro> &carrito);

    // Getters
    float getMonto_total() const;
    DTFecha getFecha_de_la_compra() const;
    vector<DTCarro> getCarrito() const;

    // Setters
    void setMonto_total(float monto_total);
    void setFecha_de_la_compra(DTFecha fecha);
    void setCarrito(const vector<DTCarro> &productos);

    // Destructor
    ~Compra();
};

#endif // COMPRA_H