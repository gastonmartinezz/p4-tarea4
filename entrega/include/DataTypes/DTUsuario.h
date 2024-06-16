#ifndef DTUSUARIO
#define DTUSUARIO

#include <string>

using namespace std;

class DTUsuario
{
protected:
    string nombre;
    string fechaNacimiento;

public:
    DTUsuario(string, string);
    string getNombre();
    string getFechaNacimiento();
    ~DTUsuario();
};

#endif