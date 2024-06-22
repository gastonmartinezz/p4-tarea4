#include <iostream>
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Fabrica.h"
#include <string>
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/DataTypes/DTDireccion.h"
#include "../include/Usuario.h"
#include <limits>
using std::numeric_limits;
using std::streamsize;
using namespace std;

void altaUsuario() {
    cout << endl;
    cout << " Alta de Usuario" << endl;
    cout << "----------------" << endl;
    cout << endl;

    //ICUsuario* ctrlUsuario = Fabrica::getICUsuario();
    ControladorUsuario *ctrlUsuario = Fabrica::getICUsuario();

    string nickname, contraseña, codigoRUT;
    char tipoUsuario;
    DTFecha fechaNacimiento;
    DTDireccion direccion; 

    try
    {
        cin.ignore();
        cout << "Nombre: ";    
        getline(cin, nickname);
        
        if ((ctrlUsuario->findUsuario(nickname))!=NULL)
            throw invalid_argument("El usuario '" + nickname + "' ya existe.");

        
        
        std::cout << "Introduce la fecha de nacimiento (dd/mm/yyyy): ";
        std::cin >> fechaNacimiento;

        cout << "Contraseña: ";
        getline(cin, contraseña);
        while  (contraseña.length() < 6) {
        std::cerr << "Error: La contraseña debe tener al menos 6 caracteres." << std::endl;
        std::cout << "Ingrese contraseña (al menos 6 caracteres): ";
        std::cin >> contraseña;}


        std::cout << "¿Es cliente o vendedor? (C/V): ";
        std::cin >> tipoUsuario;

        if (tipoUsuario == 'C' || tipoUsuario == 'c') {

            std::cout << "Ingrese direccion:" << std::endl;
            std::cin >> direccion;
            
            ctrlUsuario->confirmarAltaCliente(nickname, contraseña, fechaNacimiento, direccion);
        }
        
         else if (tipoUsuario == 'V' || tipoUsuario == 'v') {
            std::cout << "Ingrese código RUT (12 caracteres): ";
            std::cin >> codigoRUT;
            while (codigoRUT.length() != 12) {
                std::cerr << "Error: El código RUT debe tener 12 caracteres." << std::endl;
                std::cout << "Ingrese código RUT (12 caracteres): ";
                std::cin >> codigoRUT;
            }

            ctrlUsuario->confirmarAltaVendedor(nickname, contraseña, fechaNacimiento, codigoRUT);
        } else {
            std::cerr << "Tipo de usuario no válido." << std::endl;
            return;
        }

        std::cout << "Usuario registrado con éxito." << std::endl;
    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}





/* 
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
 */