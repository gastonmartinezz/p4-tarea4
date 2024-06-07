#include <string>
#include <set>
using namespace std;

struct DTFecha {
    int dia;
    int mes;
    int anio;
}

struct DTDireccion {
    int numero_puerta;
    string calle;
    string ciudad_residencia;
}

struct DTNotificacion {
    id int;
    string texto;
    string nombre;
    string emisor;
    //hay que agregar un set llamado 'contenido' que este compuesto de objetos 'Productos'
}

enum EnumCategoria {
    ropa,
    electrodomesticos,
    otros
},

class Usuario {
    private:
    string nickname;
    string password;
    DTFecha fecha;
};

class Cliente: private Usuario {
    private:
    DTDireccion direccion;
    set<DTNotificaciones> Notificaciones: 
};

class Vendedor: private Usuario {
    private:
    int codigo_rut;
    set<> Suscriptores; //Hay que declarar el tipo de dato (o clase) en este Set.
};

class Compra {
    private:
    float monto_total;
    DTFecha fechaDeCompra;
    int ID;
};

class Producto {
    private:
    int ID;
