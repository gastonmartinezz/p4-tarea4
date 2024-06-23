#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <iostream>
#include <string>


using namespace std;


class DTCarro {
    private:
    int prod;
    int cantidad;

    public:

    DTCarro(int prod = 0, int cantidad = 0);
    DTCarro();

    int getProd()const;
    int getCantidad();
    void setProd(int p);
    void setCantidad(int c);
};


#endif // DTCOMENTARIO_H