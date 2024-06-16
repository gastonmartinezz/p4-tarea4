#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

class DTNotificacion {
private:
    string emisor;
    string nombre;
    int id;
    string texto;
    set<string> contenido;

public:
    DTNotificacion(string emisor, string nombre, int id, string texto, set<string> contenido);
    string getEmisor();
    string getNombre();
    int getId();
    string getTexto();
    set<string> getContenido();
    ~DTNotificacion();
};

ostream& operator<<(ostream& os, DTNotificacion dtNotificacion);

#endif // DTNOTIFICACION_H
