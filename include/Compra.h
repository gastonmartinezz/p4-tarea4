#ifndef COMPRA_H
#define COMPRA_H

#include <vector>
#include  "Producto.h"
#include  "../include/DataTypes/DTFecha.h"

class Compra {
private:
    int id;
    DTFecha fecha;
    std::vector<Producto> productos;

public:
    Compra(int id, const DTFecha& fecha, const std::vector<Producto>& productos);

    int getId() const;
    DTFecha getFecha() const;
    std::vector<Producto> getProductos() const;
};

#endif // COMPRA_H