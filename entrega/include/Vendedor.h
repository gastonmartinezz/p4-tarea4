#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Usuario.h"
#include "Producto.h"
#include "Promocion.h"
#include "Cliente.h"
#include <vector>
#include <set>
#include <string>

class Vendedor : public Usuario
{
private:
    int codigoRut;
    std::set<Cliente> suscriptores;
    std::vector<Producto> productos;    // Agregar esta línea para almacenar los productos del vendedor
    std::vector<Promocion> promociones; // Agregar esta línea para almacenar las promociones del vendedor

public:
    Vendedor(const std::string &nickname, const std::string &password, const DTFecha &fechaDeNacimiento,
             int codigoRut);

    int getCodigoRut() const;
    std::set<Cliente> getSuscriptores() const;
    std::vector<Producto> getProductos() const;    // Agregar este método para obtener los productos
    std::vector<Promocion> getPromociones() const; // Agregar este método para obtener las promociones

    void setCodigoRut(int codigoRut);
    void agregarSuscriptor(const Cliente &cliente);
    void eliminarSuscriptor(const Cliente &cliente);
    void agregarProducto(const Producto &producto);    // Agregar este método para agregar un producto
    void agregarPromocion(const Promocion &promocion); // Agregar este método para agregar una promoción

    void mostrarInformacion() const override;
};

#endif