#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>
#include "DataTypes/DTFecha.h"

using namespace std;

class DTUsuario
{
protected:
    std::string nickname;
    DTFecha fechaNacimiento;
    std::string password;

public:
    DTUsuario(std::string nombre, DTFecha fechaNacimiento, std::string password = "");
    string getNombre();
    DTFecha getFechaNacimiento();
    std::string getPassword();
    ~DTUsuario();
};

#endif