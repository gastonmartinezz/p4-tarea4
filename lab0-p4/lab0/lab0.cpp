#include "include/lab0.h"
#include <iostream>
#include <string>
#include <set>

///// IMPLEMENTACION DE LAS CLASES

static bool compararfecha(DTFecha fecha1, DTFecha fechadesde) {
    bool res = true;
    if (fecha1.año < fechadesde.año)
    {
        res = false;
    }
    else if (fecha1.mes < fechadesde.mes)
    {
        res = false;
    }
    else if (fecha1.dia < fechadesde.dia)
    {
        res = false;
    }
    return res;
};

static std::string set_to_string(std::set<std::string> myset) {
    // Iterar sobre los elementos del conjunto
    std::string concatenatedString;
    for (auto it = myset.begin(); it != myset.end(); ++it)
    {
        // Concatenar el elemento actual al string
        concatenatedString += *it;

        // Agregar un separador (coma y espacio) si no es el último elemento
        if (std::next(it) != myset.end())
        {
            concatenatedString += ", ";
        }
    }
    return concatenatedString;
};

//////////// CLASE INFORMACION
Informacion::Informacion(){};
Informacion::Informacion(int num, DTFecha fecha) : identificador(num), fecha(fecha){};

std::vector<Estudiante *> Informacion::obtener_est() { 
    return vector_est; 
}

void Informacion::agregar_est(Estudiante *est) { 
    vector_est.push_back(est); 
}

int Informacion::obtener_id() { 
    return identificador;
}

DTFecha Informacion::obtener_fecha() { 
    return fecha; 
}

std::string Informacion::obtener_fecha_string() {
    std::string output = std::to_string(obtener_fecha().dia) + "/" + std::to_string(obtener_fecha().mes) + "/" + std::to_string(obtener_fecha().año);
    return output;
}

Informacion::~Informacion(){};

//////////// CLASE PAGINAWEB
Paginaweb::Paginaweb(){};
Paginaweb::Paginaweb(int num, const DTFecha &fecha, const std::string &titulo, const std::string &text, const std::string &link): Informacion(num, fecha), titulo(titulo), text(text), link(link){};

std::string Paginaweb::obtenerTitulo() { 
    return titulo;
}

std::string Paginaweb::obtenerLink() { 
    return link; 
}
std::string Paginaweb::obtenerText() { 
    return text; 
}
std::string Paginaweb::toString() {
    std::string output = "PáginaWeb: " + std::to_string(Informacion::obtener_id()) + ", " + Informacion::obtener_fecha_string() + ", " + titulo + ", " + link + ", " + text;
    return output;
}

Paginaweb::~Paginaweb(){};

//////////// CLASE CHATGPT
Chatgpt::Chatgpt(int num, DTFecha fecha, const std::string &pregunta, const std::string &respuesta): Informacion(num, fecha), pregunta(pregunta), respuesta(respuesta){};

std::string Chatgpt::obtenerPregunta() { 
    return pregunta; 
}

std::string Chatgpt::obtenerRespuesta() { 
    return respuesta; 
}

std::string Chatgpt::toString() {
    std::string output = "chatGPT: " + std::to_string(Informacion::obtener_id()) + ", " + Informacion::obtener_fecha_string() + ", " + pregunta + ", " + respuesta;
    return output;
}

Chatgpt::~Chatgpt(){};

//////////// CLASE LIBRO
Libro::Libro(int num, const DTFecha &fecha, const std::string &titulo, const std::set<std::string> &autores, const std::string &resumen): Informacion(num, fecha), titulo(titulo), autores(autores), resumen(resumen){};

std::string Libro::obtenerTitulo() { 
    return titulo; 
}
std::set<std::string> Libro::obtenerAutores() { 
    return autores; 
}
std::string Libro::obtenerResumen() { 
    return resumen; 
};
std::string Libro::toString() {
    std::string output = "Libro: " + std::to_string(Informacion::obtener_id()) + ", " + Informacion::obtener_fecha_string() + ", " + titulo + ", " + set_to_string(obtenerAutores()) + ", " + obtenerResumen();
    return output;
};

Libro::~Libro(){};

/////////// CLASE ESTUDIANTE

Estudiante::Estudiante(const std::string nombre, int ci, const std::string email): nombre(nombre), ci(ci), email(email){};

std::string Estudiante::obtenerNombre() { 
    return nombre; 
}

int Estudiante::obtenerCi() { 
    return ci; 
}

std::string Estudiante::obtenerEmail() { 
    return email; 
}

std::string Estudiante::toString()
{
    return nombre + ", " + std::to_string(ci) + ", " + email;
}

std::vector<Informacion *> Estudiante::obtenerInfo() { 
    return vector_info; 
}

void Estudiante::agregar_info(Informacion *info) { 
    vector_info.push_back(info); 
}

void Estudiante::eliminar_info(int id_info) {
    int tam = vector_info.size();
    for (int i = 0; i < tam; ++i)
    {
        if (vector_info[i]->obtener_id() == id_info)
        {
            vector_info.erase(vector_info.begin() + i);
            break;
        }
    }
}

std::set<std::string> Estudiante::listarInfo(DTFecha desde) {
    std::set<std::string> res; // posible error al no estar inicializado
    int largo = vector_info.size();
    for (int i = 0; i < largo; ++i)
    {
        if (compararfecha(vector_info[i]->obtener_fecha(), desde))
        {
            res.insert(vector_info[i]->toString());
        }
    }
    return res;
}
Estudiante::~Estudiante(){};

///////////////// Funciones auxiliares