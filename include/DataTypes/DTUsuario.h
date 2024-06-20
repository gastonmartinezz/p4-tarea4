#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>
#include "../include/DataTypes/DTFecha.h"
using namespace std;

class DTUsuario
{
protected:
    std::string nickname;
    DTFecha fechaNacimiento;
    std::string password;

public:
    DTUsuario(string nombre, DTFecha fechaNacimiento, string password = "");
    string getNombre();
    DTFecha getFechaNacimiento();
    string getPassword();
    ~DTUsuario();
};

#endif