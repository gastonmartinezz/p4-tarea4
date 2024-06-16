#include <iostream>
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Fabrica.h" //DEFINIR
#include <string>
#include "../include/ControladorUsuario.h"
#include "../include/DTFecha.h"

void altaUsuario() {
    std::string nickname, password, tipoUsuario, direccion, ciudad, codigoRUT;
    int dia, mes, anio;

    ControladorUsuario* controlador = ControladorUsuario::getInstancia();

    std::cout << "Ingrese nickname: ";
    std::cin >> nickname;

    std::cout << "Ingrese password (al menos 6 caracteres): ";
    std::cin >> password;

    if (password.length() < 6) {
        std::cerr << "Error: La contraseña debe tener al menos 6 caracteres." << std::endl;
        return;
    }

    std::cout << "Ingrese fecha de nacimiento (dd mm aaaa): ";
    std::cin >> dia >> mes >> anio;
    DTFecha fechaNacimiento(dia, mes, anio);

    std::cout << "Ingrese tipo de usuario (cliente/vendedor): ";
    std::cin >> tipoUsuario;

    controlador->ingresarDatosUsuario(nickname, password, fechaNacimiento);

    if (tipoUsuario == "cliente") {
        std::cout << "Ingrese direccion: ";
        std::cin.ignore(); // Para limpiar el buffer del newline
        std::getline(std::cin, direccion);

        std::cout << "Ingrese ciudad: ";
        std::getline(std::cin, ciudad);

        controlador->datosCliente(direccion, ciudad);
    } else if (tipoUsuario == "vendedor") {
        std::cout << "Ingrese codigo RUT (12 caracteres): ";
        std::cin >> codigoRUT;

        if (codigoRUT.length() != 12) {
            std::cerr << "Error: El codigo RUT debe tener exactamente 12 caracteres." << std::endl;
            return;
        }

        controlador->datosVendedor(codigoRUT);
    } else {
        std::cerr << "Error: Tipo de usuario no valido." << std::endl;
        return;
    }

    try {
        controlador->confirmarAltaUsuario();
        std::cout << "Usuario dado de alta exitosamente." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}





