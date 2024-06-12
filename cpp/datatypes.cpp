#include <dataTypes.h>

struct DTFecha {
    int dia;
    int mes;
    int anio;
};

struct DTDireccion {
    int numero_puerta;
    string calle;
    string ciudad_residencia;
};

struct DTPromocion {
    float descuento;
    string nombre;
    string desc;
    DTFecha fecha_vencimiento;
    Vendedor vendedor;
};

struct DTProducto {
    int id;
    int stock;
    float precio;
    string nombre;
    string desc;
    EnumCategoria cat;
    DTVendedor vendedor;
};

struct DTVendedor {
    string rut;
    set<DTProducto> Productos;
    set<DTPromocion> Promociones;
};

struct DTNotificacion {
    int id;
    string texto;
    string nombre;
    string emisor;
    //hay que agregar un set llamado 'contenido' que este compuesto de objetos 'Productos'
};

enum EnumCategoria {
    ropa,
    electrodomesticos,
    otros
};
