#ifndef FABRICA
#define FABRICA


#include "Interfaces/ICProductos.h"
#include "Interfaces/ICUsuario.h"

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