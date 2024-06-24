#include <iostream>
#include "../include/Fabrica.h"
#include "../include/CasosDeUso.h"
#include "../include/DataTypes/DTCliente.h"
#include "../include/DataTypes/DTVendedor.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
#include "../include/Controladores/ControladorUsuario.h"
#include <string>
#include <limits>


void suscribirseANotificaciones() {

    ICUsuario *ControladorUsuario = Fabrica::getICUsuario();

    cout << "Suscribirse a Notificaciones" << endl;
    cout << "___________________" << endl;
    cout << endl;


    try{
         
        std::string nicknameCliente;
        std::string nicknameVendedor;
        vector<DTCliente> clientes = ControladorUsuario->listarClientes();
        vector<DTVendedor> vendedoresNoSuscriptos = {};
        vector<DTVendedor> vendedoresSuscriptos = {};

        cout << "Ingrese nickname del cliente" << endl;;
        cin >> nicknameCliente;

        Cliente* cliente = ControladorUsuario->findCliente(nicknameCliente);

        if(cliente == nullptr) {
            throw invalid_argument("El cliente no esta registrado");
        }

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

        Vendedor* vendedor = ControladorUsuario->findVendedor(nicknameVendedor);

        if(vendedor == nullptr) {
            throw invalid_argument("No existe vendedor con ese nickname");
        }

        ControladorUsuario->agregarSuscripcion(cliente, vendedor);

        cout << "----------------------" << endl;
        cout << "SUSCRIPTO" << endl;
        cout << "----------------------" << endl;

        vendedoresSuscriptos = ControladorUsuario->obtenerVendedoresSuscriptos(cliente);

        cout << "Vendedores a los que el cliente esta suscripto:" << endl;  
        for (auto it = vendedoresSuscriptos.begin(); it != vendedoresSuscriptos.end(); ++it) {
            cout << it->getNickname() << endl;
        }


    }

     catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    };

    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get();

}
