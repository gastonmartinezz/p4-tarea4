#ifndef DTUSUARIO
#define DTUSUARIO 

#include <string>

using namespace std;

class DtUsuario{
    protected:
        string nombre;
        string fechaNacimiento;
    public:
        DtUsuario(string, string);
        string getNombre();
        string getFechaNacimiento();        
        ~DtUsuario();
};

#endif