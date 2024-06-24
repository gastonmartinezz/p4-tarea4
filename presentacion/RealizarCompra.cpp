#include <iostream>
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Interfaces/ICProductos.h"
#include "../include/Fabrica.h"

#include <string>
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/DataTypes/DTCarro.h"
#include "../include/Producto.h"
#include "../include/Usuario.h"
#include <limits>

using std::numeric_limits;
using std::streamsize;

void RealizarCompra()
{

    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    ControladorUsuario *ctrlUsuario = Fabrica::getICUsuario();

    try
    {

        cout << " Realizar Compra" << endl;
        cout << "------------------" << endl;
        cout << endl;

        string nickname, clienteNickname;
        int iden, cantidad;

        std::vector<DTCliente> clientes = ctrlUsuario->listarClientes();
        std::cout << "Lista de Clientes:" << std::endl;
        if (clientes.size() == 0)
        {
            throw invalid_argument("No hay usuarios registrados.");
        }

        for (vector<DTCliente>::size_type i = 0; i < clientes.size(); ++i)
        {
            cout << i << "-";
            cout << clientes[i].getNickname() << endl;
        }

        std::cout << "Seleccione el nickname del cliente: ";
        std::cin >> clienteNickname;

        std::vector<DTProducto> productos = ctrlProducto->listarProductos2();
        std::cout << "Lista de Productos:" << std::endl;
        if (productos.size() == 0)
        {
            throw invalid_argument("No hay productos registrados.");
        }

        for (vector<DTProducto>::size_type i = 0; i < productos.size(); ++i)
        {
            cout << i << "-";
            cout << productos[i].getNombre() << endl;
            cout << productos[i].getId() << endl;
        }

        std::vector<DTCarro> carrito;

        bool seguir = true;
        string respuesta;

        while (seguir)
        {

            std::cout << "Seleccione el id del producto: ";
            std::cin >> iden;
            std::cout << "Seleccione la cantidad que quiera comprar: ";
            /// Falta validar stock
            std::cin >> cantidad;
            carrito.push_back(DTCarro(iden, cantidad));
            cout << "Desea agregar otro producto a la compra? (si/no)" << endl;
            cin >> respuesta;

            transform(respuesta.begin(), respuesta.end(), respuesta.begin(), ::toupper);

            if (!((respuesta == "SI") || (respuesta == "S")))
            {
                seguir = false;
            }
        }
        // vector<DTCarro> copia_carrito = carrito;
        // vector<Promocion*>  promociones = ctrlProducto->getpromocionesSistemaVigentes();

        // for (vector<Promocion*>::size_type i = 0; i < promociones.size(); ++i){

        // }

        // for (vector<DTCarro>::size_type i = 0; i < copia_carrito.size(); ++i)
        // {

        // }

        //////////// CHAT GPT
        // Variables necesarias

        vector<Promocion *> promociones = ctrlProducto->getpromocionesSistemaVigentes();
        float precioTotal = 0.0;

        // Aquí iría el resto de tu código para llenar el carrito...

        // Copia del carrito para manipular durante las promociones
        vector<DTCarro> copia_carrito = carrito;

        // Procesando las promociones
        for (auto &promo : promociones)
        {
            vector<Contenido *> contenidosPromo = promo->getProductosDentroDePromo();
            map<Producto *, int> productosNecesarios;

            // Construir un mapa de los productos necesarios para la promoción
            for (auto &contenido : contenidosPromo)
            {
                productosNecesarios[contenido->getProducto()] = contenido->getCantMinima();
            }

            // Verificar si todos los productos necesarios están en el carrito en la cantidad adecuada
            bool promoAplicable = true;
            map<Producto *, int> productosUsados;
            for (auto &prodNecesario : productosNecesarios)
            {
                bool encontrado = false;
                for (auto &itemCarrito : copia_carrito)
                {
                    Producto *prodEnCarrito = ctrlProducto->getProducto(itemCarrito.getProd());
                    if (prodEnCarrito == prodNecesario.first && itemCarrito.getCantidad() >= prodNecesario.second)
                    {
                        encontrado = true;
                        productosUsados[prodEnCarrito] = prodNecesario.second;
                        break;
                    }
                }
                if (!encontrado)
                {
                    promoAplicable = false;
                    productosUsados.clear();
                    break;
                }
            }

            // Si la promoción es aplicable, procesarla y calcular el descuento
            if (promoAplicable)
            {
                cout << "Aplicando promoción: " << promo->getNombre() << endl;
                float precioPromocion = 0.0;
                for (auto &productoUsado : productosUsados)
                {
                    auto it = remove_if(copia_carrito.begin(), copia_carrito.end(), [&](DTCarro &item)
                                        { return item.getProd() == productoUsado.first->getId() && item.getCantidad() >= productoUsado.second; });
                    copia_carrito.erase(it, copia_carrito.end());

                    precioPromocion += productoUsado.first->getPrecio() * productoUsado.second;
                }
                precioPromocion *= (1 - promo->getDescuento());
                precioTotal += precioPromocion;
            }
        }

        // Sumar precios de productos restantes en el carrito
        for (auto &itemCarrito : copia_carrito)
        {
            Producto *prodEnCarrito = ctrlProducto->getProducto(itemCarrito.getProd());
            precioTotal += prodEnCarrito->getPrecio() * itemCarrito.getCantidad();
        }

        // Imprimir el precio total después de aplicar todas las promociones y sumar los productos restantes
        cout << "Precio total con descuentos y productos restantes: $" << precioTotal << endl;
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    };
}
