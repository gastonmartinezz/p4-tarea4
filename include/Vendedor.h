#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <vector>
#include <set>
#include <string>
#include "Usuario.h"
#include "Producto.h"
#include "Promocion.h"
#include "Cliente.h"
#include "../include/DataTypes/DTVendedor.h"
using namespace std;

class Cliente;
class Producto;
class Promocion;
class DTVendedor;

class Vendedor : public Usuario
{
private:
    int codigoRut;
    set<Cliente *> suscriptores;
    vector<Producto *> productos;    // Agregar esta línea para almacenar los productos del vendedor
    vector<Promocion *> promociones; // Agregar esta línea para almacenar las promociones del vendedor

public:
    Vendedor(const string &nickname, const string &password, const DTFecha &fechaDeNacimiento, int codigoRut);

    int getCodigoRut();
    set<Cliente *> getSuscriptores();
    vector<Producto *> getProductos();    // Agregar este método para obtener los productos
    vector<Promocion *> getPromociones(); // Agregar este método para obtener las promociones
    DTVendedor toDataType();              // es un void pq en si genera un nuevo objeto en DTVendedor.cpp [REVISAR]

    void setCodigoRut(int codigoRut);

    void agregarSuscriptor(Cliente *);
    void eliminarSuscriptor(Cliente *);
    void agregarProducto(Producto *);   // Agregar este método para agregar un producto
    void agregarPromocion(Promocion *); // Agregar este método para agregar una promoción

    void mostrarInformacionVendedor();
    ~Vendedor();
};

// set<Vendedor*> vendedoresSistema; //Set donde guardamos todos los vendedores del sistema
#endif