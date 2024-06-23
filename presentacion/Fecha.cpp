#include "../include/Controladores/ControladorProducto.h"
#include "../include/DataTypes/DTVendedor.h"
#include "../include/Interfaces/ICProductos.h"
#include "../include/contenido.h"
#include "../include/DataTypes/DTFecha.h"
#include <iostream>
#include <vector>
#include <map>
#include "../include/Fabrica.h"
#include <limits>
#include "../include/CasosDeUso.h"

using namespace std;

// Función para verificar si un año es bisiesto
bool esBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return true;
    }
    return false;
}

// Función para obtener la cantidad de días en un mes dado un año
int diasEnMes(int mes, int anio) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return esBisiesto(anio) ? 29 : 28;
        default:
            return 0; // Esto nunca debería suceder si mes está entre 1 y 12
    }
}

void Fecha() {
    ControladorProducto *ctrlProducto = Fabrica::getICProductos();
    try {
        int dia, mes, anio;

        // Solicitar año y validarlo
        cout << "Ingrese el anio: " << endl;
        cin >> anio;
        while (cin.fail() || anio < 1900 || anio > 2100) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Año inválido. Por favor, ingrese un año razonable: ";
            cin >> anio;
        }

        // Solicitar mes y validarlo
        cout << "Ingrese el mes: " << endl;
        cin >> mes;
        while (cin.fail() || mes < 1 || mes > 12) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mes inválido. Por favor, ingrese un mes entre 1 y 12: ";
            cin >> mes;
        }

        // Solicitar día y validarlo según el mes y el año
        cout << "Ingrese el dia: " << endl;
        cin >> dia;
        int maxDia = diasEnMes(mes, anio);
        while (cin.fail() || dia < 1 || dia > maxDia) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Día inválido. Por favor, ingrese un día entre 1 y " << maxDia << ": ";
            cin >> dia;
        }

        // Aquí puedes continuar con el uso de la fecha validada
        cout << "Fecha ingresada: " << dia << "/" << mes << "/" << anio << endl;

        DTFecha fecha = DTFecha(dia, mes, anio);
        ctrlProducto->setFecha(fecha);

    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get(); // Espera que el usuario presione Enter
}
