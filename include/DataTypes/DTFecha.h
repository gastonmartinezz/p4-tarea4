/*

#ifndef DTFECHAHORA
#define DTFECHAHORA

#include <iostream>

using namespace std;

class DTFecha{
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

// Sobrecarga del operador de salida
    friend std::ostream& operator<<(std::ostream& os, const DTFecha& fecha);

    // Sobrecarga del operador de entrada
    friend std::istream& operator>>(std::istream& is, DTFecha& fecha);

ostream& operator<<(ostream&, DTFecha);



#endif

*/

#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
#include <string>

class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha();
    DTFecha(int d, int m, int a);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    bool operator>(const DTFecha& other) const;
    bool esNula() const;

    ~DTFecha();

    std::string toString() const ;

    // Sobrecarga del operador de salida
    friend std::ostream& operator<<(std::ostream& os, const DTFecha& fecha);

    // Sobrecarga del operador de entrada
    friend std::istream& operator>>(std::istream& is, DTFecha& fecha);
};

#endif // DTFECHA_H