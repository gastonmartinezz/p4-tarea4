#include <resto.cpp>

class Promocion {
    private:
    float descuento;
    string nombre;
    string descripcion;
    DTFecha fecha_vencimiento;
    set<Producto*> productosDentroDePromo;
    Vendedor Vendedour;

    public:
    Promocion(float descuento, string nombre, string desc, DTFecha fecha_ven);
    ~Promocion();
    float getDescuento();
    void agregarProducto(Producto* prod);
    DTFecha getFechaVencimiento();
    Vendedor getVendedor();
};