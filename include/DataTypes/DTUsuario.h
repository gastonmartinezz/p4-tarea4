#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>
#include "../include/DataTypes/DTFecha.h"
using namespace std;

class DTUsuario
{
protected:
    string nickname;
    DTFecha fechaNacimiento;
    string password;

public:
    DTUsuario(string nombre, DTFecha fechaNacimiento, string password = "");
    string getNombre();
    DTFecha getFechaNacimiento();
    string getPassword();
    ~DTUsuario();
};

#endif