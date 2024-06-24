#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <iostream>
#include <string>
#include <set>
#include "../include/Vendedor.h"
#include "../include/Promocion.h"

class Promocion;
class Vendedor;

using namespace std;

class DTNotificacion {
private:
    Vendedor *emisor;  
    Promocion *contenido; 

public:
    DTNotificacion(Vendedor *emisor, Promocion *contenido);
    Vendedor *getEmisor();
    Promocion *getContenido();
    ~DTNotificacion();
};

#endif // DTNOTIFICACION_H
