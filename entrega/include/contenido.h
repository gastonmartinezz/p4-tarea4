#include <Promocion.h>
#include <Producto.h>

//Esta clase es la clase producto/promocion

class Contenido {
    private:
    Producto* producto;
    Promocion* promo;

    public:
    int cantidad_minima;

    Contenido(Producto* prod, Promocion* promo);
    ~Contenido();

    int getCantMinima();
    Producto* getProducto();

    void setCantMinima(int cantMinima);
};