#ifndef DTFECHAHORA
#define DTFECHAHORA

#include <iostream>
using namespace std;

class DTFecha {
    private:
        int dia;
        int mes;
        int anio;
        
    public:
        DTFecha();
        DTFecha(int,int,int);
        int getDia();
        int getMes();
        int getAnio();
       
        bool operator>(DTFecha);
        bool esNula();
        ~DTFecha();
};

ostream& operator<<(ostream&, DTFecha);

#endif