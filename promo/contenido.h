#include <promocion.h>

class Contenido {
    private:
    Producto producto;
    Promocion promo;

    public:
    int cantidad_minima;

    int getCantMinima();
    ~Contenido();
};