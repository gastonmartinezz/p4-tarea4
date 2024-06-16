/*#include <iostream>
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Fabrica.h" //DEFINIR
#include <string>
#include "../include/ControladorUsuario.h"
#include "../include/DTFecha.h"
*/



#include "../include/Fabrica.h"
#include "../include/DataTypes/DTFecha.h"
#include <iostream>
#include <string>

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
    std::cout << "Ingrese fecha de nacimiento (DD MM AAAA): ";
    std::cin >> dia >> mes >> anio;
    DTFecha fechaNacimiento(dia, mes, anio);

    controladorUsuario->ingresarDatosUsuario(nickname, password, fechaNacimiento);

    std::cout << "¿Es cliente o vendedor? (C/V): ";
    std::cin >> tipoUsuario;

    if (tipoUsuario == 'C' || tipoUsuario == 'c') {
        std::cout << "Ingrese direccion: ";
        std::cin >> direccion;
        std::cout << "Ingrese ciudad: ";
        std::cin >> ciudad;
        controladorUsuario->datosCliente(direccion, ciudad);
    } else if (tipoUsuario == 'V' || tipoUsuario == 'v') {
        std::cout << "Ingrese código RUT (12 caracteres): ";
        std::cin >> codigoRUT;
        controladorUsuario->datosVendedor(codigoRUT);
    } else {
        std::cerr << "Tipo de usuario no válido." << std::endl;
        return;
    }

    try {
        controladorUsuario->confirmarAltaUsuario();
        std::cout << "Usuario registrado con éxito." << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}



