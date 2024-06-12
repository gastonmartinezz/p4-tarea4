#include <iostream>
#include <string>
#include <set>
#include <vector>

struct DTInfoEstudiante {
    int ci;
    std::string NombreEst;
    int IdentificadorInfo;

    friend std::ostream& operator<<(std::ostream& os, const DTInfoEstudiante& estudiante);
};

struct DTFecha {
    int dia;
    int mes;
    int año;
};

//////////// DEFINICION DE LAS CLASES
class Estudiante;


//////////// CLASE INFORMACION
class Informacion {
private:
    int identificador;
    DTFecha fecha;
    std::vector<Estudiante *> vector_est;

public:
    Informacion();
    Informacion(int num, DTFecha fecha);
    std::vector<Estudiante *> obtener_est();
    void agregar_est(Estudiante *info);
    virtual std::string toString() = 0;
    int obtener_id();
    DTFecha obtener_fecha();
    std::string obtener_fecha_string();
    ~Informacion();
};

//////////// CLASE PAGINAWEB

class Paginaweb : public Informacion {
private:
    std::string titulo;
    std::string text;
    std::string link;

public:
    Paginaweb();
    Paginaweb(int num, const DTFecha &fecha, const std::string &titulo, const std::string &text, const std::string &link);

    std::string obtenerTitulo();
    std::string obtenerLink();
    std::string obtenerText();
    ~Paginaweb();
    std::string toString(); // const override
};

//////////// CLASE CHATGPT

class Chatgpt : public Informacion {
private:
    std::string pregunta;
    std::string respuesta;

public:
    Chatgpt(int num, DTFecha fecha, const std::string &pregunta, const std::string &respuesta);

    std::string obtenerPregunta();
    std::string obtenerRespuesta();
    std::string toString();
    ~Chatgpt();
};

//////////// CLASE LIBRO

class Libro : public Informacion {
private:
    std::string titulo;
    std::set<std::string> autores;
    std::string resumen;

public:
    Libro(int num, const DTFecha &fecha, const std::string &titulo, const std::set<std::string> &autores, const std::string &resumen);
    std::string obtenerTitulo();
    std::set<std::string> obtenerAutores();
    std::string obtenerResumen();
    std::string toString();
    ~Libro();
};

//////////// CLASE ESTUDIANTE

class Estudiante {
private:
    std::string nombre;
    int ci;
    std::string email;
    std::vector<Informacion *> vector_info;

public:
    Estudiante(const std::string nombre, int ci, const std::string email);
    std::vector<Informacion *> obtenerInfo();
    void agregar_info(Informacion *info);
    void eliminar_info(int id_info);
    std::string toString();
    std::string obtenerNombre();
    int obtenerCi();
    std::string obtenerEmail();
    std::set<std::string> listarInfo(DTFecha desde);
    ~Estudiante();
};