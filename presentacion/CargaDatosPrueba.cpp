

#include <iostream>
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Fabrica.h"
#include "../include/CasosDeUso.h"

#include <limits>

using std::numeric_limits;
using std::streamsize;
using namespace std;

void cargaDatosDePrueba()
{
    cout << endl;
    cout << " Datos de prueba" << endl;
    cout << "----------------" << endl;
    cout << endl;

    ICUsuario *ctrlUsuario = Fabrica::getICUsuario();
    ctrlUsuario->cargarDatosPrueba();
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get();
}
