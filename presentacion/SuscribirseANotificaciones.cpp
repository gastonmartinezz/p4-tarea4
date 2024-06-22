#include <iostream>
#include "../include/Fabrica.h"
#include "../include/CasosDeUso.h"
#include "../include/DataTypes/DTCliente.h"
#include "../include/DataTypes/DTVendedor.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
#include "../include/Controladores/ControladorUsuario.h"
#include <string>


void suscribirseANotificaciones() {

    ICUsuario *ControladorUsuario = Fabrica::getICUsuario();

    cout << "Suscribirse a Notificaciones" << endl;
    cout << "___________________" << endl;
    cout << endl;


    try{
         
        std::string nicknameCliente;
        std::string nicknameVendedor;
        vector<DTCliente> clientes = ControladorUsuario->listarClientes();
        bool clienteRegistrado = false;
        bool vendedorRegistrado = false;
        vector<DTVendedor> vendedoresNoSuscriptos = {};

        cout << "Ingrese nickname del cliente" << endl;;
        cin >> nicknameCliente;

        for (auto it = clientes.begin(); it != clientes.end(); ++it) {
            if(!clienteRegistrado) {
                clienteRegistrado = (it->getNickname() == nicknameCliente);
            }
        }
        
        if(!clienteRegistrado) {
            throw invalid_argument("El cliente no esta registrado");
        }

        Cliente* cliente = ControladorUsuario->findCliente(nicknameCliente);
        vendedoresNoSuscriptos = ControladorUsuario->obtenerVendedoresNoSuscriptos(cliente);
        

        if(vendedoresNoSuscriptos.size() == 0) {
            throw invalid_argument("El cliente esta suscripto a todos los vendedores");
        }
        
        cout << "Vendedores a los que el cliente no esta suscripto:" << endl;    

        for (auto it = vendedoresNoSuscriptos.begin(); it != vendedoresNoSuscriptos.end(); ++it) {
            cout << it->getNickname() << endl;
        }

        cout << "Vendedor al que se quiere suscribir:" << endl;
        cin >> nicknameVendedor;

        for (auto it = vendedoresNoSuscriptos.begin(); it != vendedoresNoSuscriptos.end(); ++it) {
            if(!vendedorRegistrado) {
                vendedorRegistrado = (it->getNickname() == nicknameVendedor);
            }
        }

        if(!vendedorRegistrado) {
            throw invalid_argument("No existe vendedor con ese nickname");
        }

        Vendedor* vendedor = ControladorUsuario->findVendedor(nicknameVendedor);
        ControladorUsuario->agregarSuscripcion(cliente, vendedor);


    }

    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    };

}
