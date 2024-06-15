#ifndef FABRICA
#define FABRICA


#include "Interfaces/ICProductos.h"
#include "Interfaces/ICUsuario.h"
#include "Interfaces/IReloj.h" //DEFINIR

class Fabrica{
    private:
        Fabrica();
    public:
        static ICUsuario* getICUsuario();
        static ICProductos* getICProductos();
        static IReloj* getIReloj();
        static void destruir();
};

#endif