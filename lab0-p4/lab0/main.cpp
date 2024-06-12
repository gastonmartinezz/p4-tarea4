#include "include/lab0.h"
#include <iostream>
#include <string>
#include <vector>


std::ostream& operator<<(std::ostream& os, const DTInfoEstudiante& estudiante) {
    os << estudiante.ci << ", " << estudiante.NombreEst << ", " << estudiante.IdentificadorInfo;
    return os;
}

DTFecha crearFechas(int dia, int mes, int anio) {
    DTFecha fecha;
    fecha.dia = dia;
    fecha.mes = mes;
    fecha.año = anio;

    return fecha;
}

static std::string set_to_string(std::set<std::string> myset) {

    // Iterar sobre los elementos del conjunto
    std::string concatenatedString;
    for (auto it = myset.begin(); it != myset.end(); ++it) {
        // Concatenar el elemento actual al string
        concatenatedString += *it;

        // Agregar un separador (coma y espacio) si no es el último elemento
        if (std::next(it) != myset.end()) {
            concatenatedString += ", ";
        }
    }
    return concatenatedString;
}

void eliminar_info(std::vector<Informacion *> &aux_infos, int id_info) {
    int i = 0;
    int tam = aux_infos.size();
    while (i < tam && aux_infos[i]->obtener_id() != id_info) {
        i = i + 1;
    }

    for (Estudiante *estudiante : aux_infos[i]->obtener_est()) {
        estudiante->eliminar_info(id_info);
    }

    aux_infos[i]->~Informacion();
    aux_infos.erase(aux_infos.begin() + i);
    std::cout << "Se eliminó la informacion" << id_info << std::endl;
}

int main() {
    std::vector<Informacion *> infos_aux;

    Paginaweb *pagina1 = new Paginaweb(1, crearFechas(7, 3, 2024), "Programación 4 Guía Semana 1 (4/3)", "https://eva.fing.edu.uy/pluginfile.php/468051/mod_resource/content/4/Guia01_P42024_IntroCBasicos.pdf", "El objetivo de esta semana es contextualizar el paradigma de Orientación a Objetos (OO) en el marco de la Ingeniería de Software, así como comenzar a ver sus conceptos básicos y cómo éstos se implementan en C++");
    Paginaweb *pagina2 = new Paginaweb(2, crearFechas(5, 3, 2024), "Programación orientada a objetos", "https://es.wikipedia.org/wiki/Programaci%C3%B3n_orientada_a_objetos", "La programación orientada a objetos (POO, en español) es un paradigma de programación que parte del concepto de ""objetos"" como base, los cuales contienen información en forma de campos (a veces también referidos como atributos o propiedades) y código en forma de métodos. Algunas características clave de la programación orientada a objetos son herencia, cohesión, abstracción, polimorfismo, acoplamiento y encapsulamiento.");
    
    infos_aux.push_back(pagina1);
    infos_aux.push_back(pagina2);

    Chatgpt *chat1 = new Chatgpt(3, crearFechas(8, 3, 2024), "¿Qué es el polimorfismo en orientación a objetos?", "El polimorfismo en programación orientada a objetos se refiere a la capacidad de un objeto de tomar múltiples formas. Puede ser estático, resuelto en tiempo de compilación, basado en la herencia, o dinámico, resuelto en tiempo de ejecución, asociado a interfaces o métodos abstractos. En esencia, permite que objetos de diferentes clases respondan a la misma interfaz de manera coherente, facilitando la flexibilidad y extensibilidad del código.");
    Chatgpt *chat2 = new Chatgpt(4, crearFechas(5, 3, 2024), " ¿Qué es el acoplamiento en orientación a objetos?", "El acoplamiento en programación orientada a objetos se refiere al grado de dependencia entre las clases o módulos de un sistema. Un bajo acoplamiento es deseable, ya que implica que las clases son independientes entre sí, lo que facilita la modificación, mantenimiento y reutilización del código. Por otro lado, un alto acoplamiento indica una fuerte interdependencia entre las clases, lo que puede hacer que el sistema sea más difícil de entender, modificar y mantener.");
    
    infos_aux.push_back(chat1);
    infos_aux.push_back(chat2);

    Libro *libro1 = new Libro(5, crearFechas(15, 3, 2024), "Applying UML and Patterns: An Introduction to Object-Oriented Analysis and Design and Iterative Development", {"Craig Larman"}, "Applying UML and Patterns is the world’s #1 business and college introduction to “thinking in objects”―and using that insight in real-world object- oriented analysis and design. Building on two widely acclaimed previous editions, Craig Larman has updated this book to fully reflect the new UML 2 standard, to help you master the art of object design, and to promote high-impact, iterative, and skillful agile modeling practices.");
    infos_aux.push_back(libro1);

    std::string imp;
    int largo = infos_aux.size();
    for (int i = 0; i < largo; ++i) {
        imp = infos_aux[i]->toString();
        std::cout << imp << std::endl;
    }

    std::vector<Estudiante *> estudiantes_aux;

    Estudiante *est1 = new Estudiante("Alex García", 52365899, "ag5678@gmail.com");
    Estudiante *est2 = new Estudiante("Betina Gonzalez", 49891239, "beg999@gmail.com");

    estudiantes_aux.push_back(est1);
    estudiantes_aux.push_back(est2);

    for (int i = 0; i < largo; ++i) {
        switch (infos_aux[i]->obtener_id())
        {
        case 1:
            infos_aux[i]->agregar_est(est1);
            est1->agregar_info(infos_aux[i]);
            break;
        case 2:
            infos_aux[i]->agregar_est(est1);
            est1->agregar_info(infos_aux[i]);
            break;
        case 3:
            infos_aux[i]->agregar_est(est1);
            est1->agregar_info(infos_aux[i]);
            infos_aux[i]->agregar_est(est2);
            est2->agregar_info(infos_aux[i]);
            break;
        case 4:
            infos_aux[i]->agregar_est(est2);
            est2->agregar_info(infos_aux[i]);
            break;
        case 5:
            infos_aux[i]->agregar_est(est2);
            est2->agregar_info(infos_aux[i]);
            break;
        default:
            break;
        }
    }

    std::string imprimir2;
    std::set<std::string> estudia;
    int tam = estudiantes_aux.size();
    for (int i = 0; i < tam; ++i)
    {
        estudia = estudiantes_aux[i]->listarInfo(crearFechas(8, 3, 2024));
        imprimir2 = set_to_string(estudia);
        std::cout << imprimir2 << std::endl;
    }

    std::vector<DTInfoEstudiante> estudiantesConPolimorfismo;
    for (Informacion *info : infos_aux) {
        std::string infoString = info->toString();
        if (infoString.find("polimorfismo") != std::string::npos)
        {
            std::vector<Estudiante *> aux = info->obtener_est();
            for (Estudiante *estudiante : aux)
            {
                DTInfoEstudiante dtEstudiante;
                dtEstudiante.ci = estudiante->obtenerCi();
                dtEstudiante.NombreEst = estudiante->obtenerNombre();
                dtEstudiante.IdentificadorInfo = info->obtener_id();
                estudiantesConPolimorfismo.push_back(dtEstudiante);
            }
        };
    }

    for (const auto &estudiante : estudiantesConPolimorfismo) {
        std::cout << estudiante << std::endl;
    }
    
    eliminar_info(infos_aux, 3);

    std::string imp1;
    int largo1 = infos_aux.size();
    for (int i = 0; i < largo1; ++i) {
        imp1 = infos_aux[i]->toString();
        std::cout << imp1 << std::endl;
    }

    return 0;
}