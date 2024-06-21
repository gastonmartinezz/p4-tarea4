#include "DTVendedor.h"

DTVendedor::DTVendedor(int rut, vector<Producto *> productos, vector<Promocion *> promociones, std::string nickname)
    : rut(rut), productos(productos), promociones(promociones), nickname(nickname) {}

int DTVendedor::getRut()
{
    return rut;
}

vector<Producto *> DTVendedor::getProductos()
{
    return productos;
}

vector<Promocion *> DTVendedor::getPromociones()
{
    return promociones;
}
std::string DTVendedor::getNickname()
{
    return nickname;
}

DTVendedor::~DTVendedor() {}

ostream &operator<<(ostream &os, DTVendedor dtVendedor)
{
    os << "RUT: " << dtVendedor.getRut() << ", Productos: ";
    for (const auto &producto : dtVendedor.getProductos())
    {
        os << producto << " ";
    }
    os << ", Promociones: ";
    for (const auto &promocion : dtVendedor.getPromociones())
    {
        os << promocion << " ";
    }
    return os;
}
