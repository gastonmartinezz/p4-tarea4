#include <iostream>
#include <vector>
#include "../include/Fabrica.h"
#include "../include/Usuario.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
#include "../include/Producto.h"
#include "../include/Promocion.h"
#include "../include/Compra.h"

void expedienteUsuario() {
    ICUsuario* controladorUsuario = Fabrica::getICUsuario();
    ICProductos* controladorProducto = Fabrica::getICProductos();

    // Listar todos los usuarios
    std::vector<Usuario*> usuarios = controladorUsuario->listarUsuarios();
    std::cout << "Lista de Usuarios: " << std::endl;
    for (size_t i = 0; i < usuarios.size(); ++i) {
        std::cout << i + 1 << ". " << usuarios[i]->getNickname() << std::endl;
    }

    // Simular la selección de un usuario por parte del administrador
    size_t seleccion;
    std::cout << "Seleccione un usuario (ingrese el número correspondiente): ";
    std::cin >> seleccion;

    if (seleccion < 1 || seleccion > usuarios.size()) {
        std::cout << "Selección no válida." << std::endl;
        return;
    }

    Usuario* usuarioSeleccionado = usuarios[seleccion - 1];
    std::cout << "Información del Usuario Seleccionado:" << std::endl;
    std::cout << "Nickname: " << usuarioSeleccionado->getNickname() << std::endl;
    std::cout << "Fecha de Nacimiento: " << usuarioSeleccionado->getFechaDeNacimiento().toString() << std::endl;

    Cliente* cliente = dynamic_cast<Cliente*>(usuarioSeleccionado);
    if (cliente) {
        std::cout << "Direccion: " << cliente->getDireccion().calle << ", "
                  << cliente->getDireccion().ciudad << ", "
                  << cliente->getDireccion().pais << std::endl;

        // Listar compras del cliente
        std::vector<Compra> compras = cliente->getCompras();
        std::cout << "Compras Realizadas:" << std::endl;
        for (const Compra& compra : compras) {
            std::cout << "Compra ID: " << compra.getId() << std::endl;
            std::cout << "Fecha: " << compra.getFecha().toString() << std::endl;
            std::cout << "Productos:" << std::endl;
            for (const Producto& producto : compra.getProductos()) {
                std::cout << "- " << producto.getNombre() << ", Precio: " << producto.getPrecio() << std::endl;
            }
        }
    }

    Vendedor* vendedor = dynamic_cast<Vendedor*>(usuarioSeleccionado);
    if (vendedor) {
        std::cout << "Codigo RUT: " << vendedor->getCodigoRut() << std::endl;

        // Listar productos del vendedor
        std::vector<Producto> productos = vendedor->getProductos();
        std::cout << "Productos a la Venta:" << std::endl;
        for (const Producto& producto : productos) {
            std::cout << "- " << producto.getNombre() << ", Precio: " << producto.getPrecio() << std::endl;
        }

        // Listar promociones del vendedor
        std::vector<Promocion> promociones = vendedor->getPromociones();
        std::cout << "Promociones Vigentes:" << std::endl;
        for (const Promocion& promocion : promociones) {
            std::cout << "- " << promocion.getNombre() << ", Descuento: " << promocion.getDescuento() << std::endl;
        }
    }
}
