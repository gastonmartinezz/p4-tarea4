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

bool esCodigoValido(const std::string &codigo)
{
    // Verificar la longitud del string
    if (codigo.length() != 12)
    {
        return false;
    }

    // Verificar que todos los caracteres sean dígitos
    for (char c : codigo)
    {
        if (!std::isdigit(c))
        {
            return false;
        }
    }

    return true;
}

void altaUsuario()
{
    cout << endl;
    cout << " Alta de Usuario" << endl;
    cout << "----------------" << endl;
    cout << endl;

    // ICUsuario* ctrlUsuario = Fabrica::getICUsuario();
    ICUsuario *ctrlUsuario = Fabrica::getICUsuario();

    string nickname, contraseña, codigoRUT, ciudad_residencia, calle;

    char tipoUsuario;
    int dia, mes, anio, numero_puerta;
    DTFecha fechaNacimiento;
    DTDireccion direccion;

    try
    {
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, nickname);

        if ((ctrlUsuario->findUsuario(nickname)) != nullptr)
            throw invalid_argument("El usuario '" + nickname + "' ya existe.");

        cout << "Fecha de nacimiento " << endl;
        cout << "Ingrese día de la fecha: ";
        cin >> dia;
        while (cin.fail() || dia < 1 || dia > 31)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Día inválido. Por favor, ingrese un día entre 1 y 31: ";
            cin >> dia;
        }

        cout << "Ingrese mes: ";
        cin >> mes;
        while (cin.fail() || mes < 1 || mes > 12)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mes inválido. Por favor, ingrese un mes entre 1 y 12: ";
            cin >> mes;
        }

        cout << "Ingrese año: ";
        cin >> anio;
        while (cin.fail() || anio < 1900 || anio > 2100)
        { // Puedes ajustar el rango según tus necesidades
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Año inválido. Por favor, ingrese un año razonable: ";
            cin >> anio;
        }
        fechaNacimiento = DTFecha(dia, mes, anio);

        cout << "Contraseña: " << endl;
        cin >> contraseña;
        //getline(cin, contraseña);
        while (contraseña.length() < 6)
        {
            std::cout << "Error: La contraseña debe tener al menos 6 caracteres." << std::endl;
            std::cout << "Ingrese contraseña (al menos 6 caracteres): ";
            std::cin >> contraseña;
        }

        std::cout << "¿Es cliente o vendedor? (C/V): ";
        std::cin >> tipoUsuario;

        if (tipoUsuario == 'C' || tipoUsuario == 'c')
        {

            std::cout << "Ingrese direccion:" << std::endl;
            cout << "Ingrese la ciudad de residencia: ";
            std::cin >> ciudad_residencia;

            cout << "Ingrese la calle: ";
            std::cin >> calle;

            cout << "Ingrese el número de puerta: ";
            std::cin >> numero_puerta;
            while (std::cin.fail() || numero_puerta <= 0)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Número de puerta inválido. Por favor, ingrese un número positivo: ";
                std::cin >> numero_puerta;
            }

            direccion = DTDireccion(ciudad_residencia, calle, numero_puerta);

            ctrlUsuario->confirmarAltaCliente(nickname, contraseña, fechaNacimiento, direccion);
        }

        else if (tipoUsuario == 'V' || tipoUsuario == 'v')
        {
            std::cout << "Ingrese código RUT (12 caracteres): ";
            std::cin >> codigoRUT;
            while (!esCodigoValido(codigoRUT))
            {
                std::cerr << "Error: El código RUT debe tener 12 digitos." << std::endl;
                std::cout << "Ingrese código RUT (12 caracteres): ";
                std::cin >> codigoRUT;
            }

            ctrlUsuario->confirmarAltaVendedor(nickname, contraseña, fechaNacimiento, codigoRUT);
            Vendedor *vend = ctrlUsuario->findVendedor(nickname);

            std::cout << vend->getNickname() << endl;
        }
        else
        {
            std::cerr << "Tipo de usuario no válido." << std::endl;
            return;
        }

        std::cout << "Usuario registrado con éxito." << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get();
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