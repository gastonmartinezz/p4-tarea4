#include "../include/Fabrica.h"
#include "../include/DataTypes/DTFecha.h"
#include <iostream>
#include <string>
#include <limits>

void altaUsuario() {
    Fabrica *fabrica = Fabrica::getInstancia();
    ICUsuario *controladorUsuario = fabrica->getICUsuario();

    std::string nickname, password, direccion, ciudad, codigoRUT;
    int dia, mes, anio;
    char tipoUsuario;

    std::cout << "Ingrese nickname: ";
    std::cin >> nickname;
    std::cout << "Ingrese contraseña (al menos 6 caracteres): ";
    std::cin >> password;

    // Verificación de la longitud de la contraseña
    while (password.length() < 6) {
        std::cerr << "Error: La contraseña debe tener al menos 6 caracteres." << std::endl;
        std::cout << "Ingrese contraseña (al menos 6 caracteres): ";
        std::cin >> password;
    }

    std::cout << "Ingrese fecha de nacimiento (DD MM AAAA): ";
    std::cin >> dia >> mes >> anio;
    DTFecha fechaNacimiento(dia, mes, anio);

    try {
        controladorUsuario->ingresarDatosUsuario(nickname, password, fechaNacimiento);

        std::cout << "¿Es cliente o vendedor? (C/V): ";
        std::cin >> tipoUsuario;

        if (tipoUsuario == 'C' || tipoUsuario == 'c') {
            std::cout << "Ingrese direccion: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
            std::getline(std::cin, direccion);
            std::cout << "Ingrese ciudad: ";
            std::getline(std::cin, ciudad);
            controladorUsuario->confirmarAltaUsuario(nickname, password, fechaNacimiento, direccion, ciudad);
        } else if (tipoUsuario == 'V' || tipoUsuario == 'v') {
            std::cout << "Ingrese código RUT (12 caracteres): ";
            std::cin >> codigoRUT;

            // Verificación de la longitud del código RUT
            while (codigoRUT.length() != 12) {
                std::cerr << "Error: El código RUT debe tener 12 caracteres." << std::endl;
                std::cout << "Ingrese código RUT (12 caracteres): ";
                std::cin >> codigoRUT;
            }

            controladorUsuario->confirmarAltaVendedor(nickname, password, fechaNacimiento, codigoRUT);
        } else {
            std::cerr << "Tipo de usuario no válido." << std::endl;
            return;
        }

        std::cout << "Usuario registrado con éxito." << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
