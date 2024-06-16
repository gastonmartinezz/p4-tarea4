#ifndef DTFECHAHORA
#define DTFECHAHORA

#include <iostream>
using namespace std;

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        DtFecha();
        DtFecha(int,int,int);
        int getDia();
        int getMes();	
        int getAnio();
       
        bool operator>(DtFecha);
        bool esNula();
        ~DtFecha();
};

ostream& operator<<(ostream&, DtFecha);

#endif