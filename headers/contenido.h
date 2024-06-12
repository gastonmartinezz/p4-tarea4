#include <promocion.h>

class Contenido {
    private:
    Producto producto;
    Promocion promo;

    public:
    int cantidad_minima;

    Contenido(Producto prod, Promocion promo);
    int getCantMinima();
    ~Contenido();
};