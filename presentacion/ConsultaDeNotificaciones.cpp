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

void consultaDeNotificaciones() {

    ICUsuario *ControladorUsuario = Fabrica::getICUsuario();

    cout << "Notificaciones" << endl;
    cout << "___________________" << endl;
    cout << endl;

    try{
         
        std::string nicknameCliente;
        vector<DTCliente> clientes = ControladorUsuario->listarClientes();
        vector<DTNotificacion> notificaciones = {};

        cout << "Ingrese nickname del cliente" << endl;;
        cin >> nicknameCliente;

        Cliente* cliente = ControladorUsuario->findCliente(nicknameCliente);

        if(cliente == nullptr) {
            throw invalid_argument("El cliente no esta registrado");
        }

        notificaciones = ControladorUsuario->getNotificaciones(cliente);
        
        if(notificaciones.size() == 0) {
            throw invalid_argument("No tiene notificaciones pendientes");
        }
        
        cout << "Nuevas notificaciones:" << endl;    

        for (auto it =notificaciones.begin(); it != notificaciones.end(); ++it) {
            ControladorUsuario->mostrarYEliminarNotificacion(*it, cliente);
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