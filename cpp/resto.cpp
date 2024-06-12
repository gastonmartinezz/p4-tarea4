#include <string>
#include <set>
#include <dataTypes.h>
#include <iostream>

using namespace std;

//Consultar promocion, crear promocion, consultar producto

class Usuario {
    private:
    string nickname;
    string password;
    DTFecha fecha;
};

class Cliente: private Usuario {
    private:
    DTDireccion direccion;
    //set<DTNotificacion> Notificaciones: 
};

class Vendedor: private Usuario {
    private:
    int codigo_rut;
    //set<> Suscriptores; //Hay que declarar el tipo de dato (o clase) en este Set.
};

class Compra {
    private:
    float monto_total;
    DTFecha fechaDeCompra;
};

class Usuario {
    private:
    string nickname;
    string password;
    DTFecha fecha;
};

class Cliente: private Usuario {
    private:
    DTDireccion direccion;
    //set<DTNotificaciones> Notificaciones: 
};

class Vendedor: private Usuario {
    private:
    int codigo_rut;
    //set<> Suscriptores; //Hay que declarar el tipo de dato (o clase) en este Set.
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
    int ID;
};

class Producto {
    private:
    int ID;
    int stock;
    float precio;
    string nombre;
    EnumCategoria categoria;
};