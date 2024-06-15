#include <promocion.h>
#include <producto.h>

Promocion::~Promocion() {}

float Promocion::getDescuento() {
    return descuento;
}

DTFecha Promocion::getFechaVencimiento() {
    return fecha_vencimiento;
}

//Promocion::Promocion() {}
//Tengo dudas con este constructor (tambien tengo que ver como agregar la clase vendedor de forma dinamica)
Promocion::Promocion(float descuento, string nombre, string desc, DTFecha fecha_ven) {
    /* Promocion *p = new Promocion(descuento, nombre, desc, fecha_ven);
    p->descuento = descuento;
    p->nombre = nombre;
    p->descripcion = desc;
    p->fecha_vencimiento = fecha_ven;

    set() */
    this->descuento = descuento;
    this->nombre = nombre;
    this->descripcion = desc;
    this->fecha_vencimiento = fecha_ven;
    this->productosDentroDePromo = std::set<Producto*>();
}

void Promocion::agregarProducto(Producto* prod) {
    productosDentroDePromo.insert(prod);
}