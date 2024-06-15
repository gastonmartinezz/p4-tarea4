#include <Vendedor.h>
#include <string>
#include <producto.h>

using namespace std;

class Promocion {
    private:
    float descuento;
    string nombre;
    string descripcion;
    DTFecha fecha_vencimiento;
    set<Contenido*> productosDentroDePromo;
    Vendedor Vendedour;

    public:
    Promocion(float descuento, string nombre, string desc, DTFecha fecha_ven);
    ~Promocion();
    set<Contenido*> getProductosDentroDePromo();
    float getDescuento();
    void agregarProducto(Producto* prod);
    DTFecha getFechaVencimiento();
    Vendedor getVendedor();
};