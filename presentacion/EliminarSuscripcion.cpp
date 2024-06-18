/* #include <iostream>
#include "../include/Usuario.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
#include "../include/Controladores/ControladorUsuario.h"
//#include <include/dataTypes.h>
#include <set>

set<DTUsuario> obtenerVendedoresSuscriptos(DTUsuario cliente) {
    set<DTUsuarios> vendedores = controladorUsuario.listarVendedores();
    set<DTUsuarios> vendedoresSuscriptos = {};

    for (auto it = vendedores.begin(); it != vendedores.end(); ++it) {
        if(estaSuscripto(cliente, it)) {
            vendedoresSuscriptos.insert(it);
        }
    }

    return vendedoresSuscriptos;
}

//Un vendedor o varios?
void eliminarVendedorSuscripto(DTUsuario cliente, DTUsuario vendedor) {
    set<DTUsuarios> vendedoresSuscriptos = obtenerVendedoresSuscriptos(cliente);
    set<DTUsuarios> clientesSuscriptos = vendedor.getSuscripciones();

    if(vendedoresSuscriptos.count(vendedor) > 0) {
        clientesSuscriptos.erase(cliente);
    }

} */