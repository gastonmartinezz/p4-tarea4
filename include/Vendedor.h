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

class Vendedor : public Usuario {
private:
    int codigoRut;
    set<Cliente*> suscriptores;
    vector<Producto*> productos;    // Agregar esta línea para almacenar los productos del vendedor
    vector<Promocion*> promociones; // Agregar esta línea para almacenar las promociones del vendedor

public:
    Vendedor();
    Vendedor(const string &nickname, const string &password, const DTFecha &fechaDeNacimiento,int codigoRut);

    int getCodigoRut() const;
    set<Cliente*> getSuscriptores() const;
    vector<Producto*> getProductos() const;    // Agregar este método para obtener los productos
    vector<Promocion*> getPromociones() const; // Agregar este método para obtener las promociones
    DTVendedor toDataType();

    void setCodigoRut(int codigoRut);

    void agregarSuscriptor(const Cliente &cliente);
    void eliminarSuscriptor(const Cliente &cliente);
    void agregarProducto(const Producto &producto);    // Agregar este método para agregar un producto
    void agregarPromocion(const Promocion &promocion); // Agregar este método para agregar una promoción

    void mostrarInformacionVendedor() const;
};

set<Vendedor*> vendedoresSistema; //Set donde guardamos todos los vendedores del sistema
#endif