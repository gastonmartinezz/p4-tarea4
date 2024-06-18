#include <iostream>
#include <include/Usuario.h>
#include <include/Cliente.h>
#include <include/Vendedor.h>
#include <include/controladorUsuario.h>
#include <include/dataTypes.h>
#include <set>


bool estaSuscripto(DTUsuario cliente, DTUsuario vendedor) {
    set<DTUsuarios> suscriptores = vendedor.getSuscriptores();

    return suscriptores.count(cliente) > 0;
}

set<DTUsuario> obtenerVendedoresNoSuscriptos(DTUsuario cliente) {
    set<DTUsuarios> vendedores = controladorUsuario.listarVendedores();
    set<DTUsuarios> vendedoresNoSuscriptos = {};

    for (auto it = vendedores.begin(); it != vendedores.end(); ++it) {
        if(!estaSuscripto(cliente, it)) {
            vendedoresNoSuscriptos.insert(it);
        }
    }

    return vendedoresNoSuscriptos;
}

//Un vendedor o varios?
void agregarSuscripcion(DTUsuario cliente, DTUsuario vendedor) {
    set<DTUsuarios> vendedoresNoSuscriptos = obtenerVendedoresNoSuscriptos(cliente);
    set<DTUsuarios> clientesSuscriptos = vendedor.getSuscripciones();

    if(vendedoresNoSuscriptos.count(vendedor) > 0) {
        clientesSuscriptos.insert(cliente);
    }
}