#include <iostream>
#include <include/Usuario.h>
#include <include/Cliente.h>
#include <include/Vendedor.h>
#include <include/dataTypes.h>
#include <set>


void mostrarYEliminarNotificacion(DTUsuario cliente) {

    set<DTNotificacion> notificaciones = cliente.getNotificaciones();

    for (auto it = notificaciones.begin(); it != notificaciones.end(); ++it) {
        cout << "Notificacion de: " << it.getEmisor() << endl;
        cout << "Nueva promocion: " << it.getNombre() << endl;
        cout << "Productos en promocion: " << endl;

        set<string> contenido = it.getContenido();
        for (auto cont = contenido.begin(); cont != contenido.end(); ++cont) {
            cout << cont << endl;
        }

        cliente.eliminarNotificacion(it);
    }
}
