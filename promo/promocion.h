#include <resto.cpp>

class Promocion {
    private:
    float descuento;
    string nombre;
    string desc;
    DTFecha fecha_vencimiento;

    public:
    DTPromocion crearPromocion();
    ~Promocion();
    float getDescuento();
    void agregarProducto(DTProducto prod);
    DTFecha getFechaVencimiento();
};