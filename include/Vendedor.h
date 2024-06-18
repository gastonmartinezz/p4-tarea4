#ifndef VENDEDOR_H
#define VENDEDOR_H

#include <Usuario.h>
#include <Producto.h>
#include <Promocion.h>
#include <Cliente.h>
#include <vector>
#include <set>
#include <string>
#include "../include/DataTypes/DTVendedor.h"
using namespace std;

class Vendedor : public Usuario {
private:
    int codigoRut;
    set<Cliente> suscriptores;
    vector<Producto> productos;    // Agregar esta línea para almacenar los productos del vendedor
    vector<Promocion> promociones; // Agregar esta línea para almacenar las promociones del vendedor

public:
    Vendedor(); //revisar este constructor en conjunto - tonga
    Vendedor(const string &nickname, const string &password, const DTFecha &fechaDeNacimiento,int codigoRut);

    int getCodigoRut() const;
    set<Cliente> getSuscriptores() const;
    vector<Producto> getProductos() const;    // Agregar este método para obtener los productos
    vector<Promocion> getPromociones() const; // Agregar este método para obtener las promociones
    DTVendedor Vendedor::toDataType();

    void setCodigoRut(int codigoRut);

    void agregarSuscriptor(const Cliente &cliente);
    void eliminarSuscriptor(const Cliente &cliente);
    void agregarProducto(const Producto &producto);    // Agregar este método para agregar un producto
    void agregarPromocion(const Promocion &promocion); // Agregar este método para agregar una promoción

    void mostrarInformacion() const override;
};

#endif