#include <iostream>
#include <stdexcept>
#include "../include/Interfaces/ICProductos.h"
#include "../include/CasosDeUso.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/Producto.h"
#include "../include/Fabrica.h"
using namespace std;

void clearScreen()
{
    cout << "\033[2J\033[1;1H"; // ANSI escape sequence to clear the console
}

void displayAndProcessMenu()
{
    int option = -1;

    while (option != 0)
    {
        clearScreen();
        cout << endl;
        cout << "  __  __ ___ _  _ _   _      " << endl;
        cout << " |  \\/  | __| \\| | | |  " << endl;
        cout << " | |\\/| | _|| .` | |_| | " << endl;
        cout << " |_|  |_|___|_|\\_|\\___/" << endl;
        cout << endl;
        cout << "MENU" << endl;
        cout << "0.  Salir" << endl;
        cout << "1.  Alta de Usuario" << endl;
        cout << "2.  Alta Producto" << endl;
        cout << "3.  Consultar Producto" << endl;
        cout << "4.  Consultar Promocion" << endl;
        cout << "5.  Crear Promocion" << endl;
        cout << "6.  Dejar Comentario" << endl;
        cout << "7.  Eliminar Suscripcion" << endl;
        cout << "8.  Expediente de Usuario" << endl;
        cout << "9.  Lista de Usuarios" << endl;
        cout << "10. Suscribirse a Notificaciones" << endl;
        cout << "11. Consulta de Notificaciones" << endl;
        cout << "12. Realizar Compra" << endl;
        cout << "13. Carga de datos de prueba" << endl;
        cout << "14. Fecha" << endl;
        cout << endl;
        cout << "Ingrese el numero de opcion que desea ejecutar: ";

        cin >> option;

        if (option != 0)
        {
            try
            {
                switch (option)
                {
                case 1:
                    altaUsuario();
                    break;
                case 2:
                    AltaProducto();
                    break;
                case 3:
                    consultarProducto();
                    break;
                // case 4:
                //     consultarPromocion();
                //     break;
                case 5:
                    crearPromocion();
                    break;
                case 6:
                    DejarComentario();
                    break;
                // case 7:
                //     eliminarSuscripcion();
                //     break;
                case 8:
                    ExpedienteUsuario();
                    break;
                case 9:
                    listaUsuarios();
                    break;
                case 10:
                    suscribirseANotificaciones();
                    break;
                case 12:
                    RealizarCompra();

                    break;
                case 13:
                    cargaDatosDePrueba();
                    AltaProductoTest();
                    break;
                case 14:
                    Fecha();
                    break;
                default:
                    throw invalid_argument("Opcion no valida. Intente de nuevo.");
                }
            }
            catch (const exception &e)
            {
                cerr << e.what() << '\n';
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    displayAndProcessMenu();
    return 0;
}