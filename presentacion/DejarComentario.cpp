
#include "../include/Fabrica.h"
#include "../include/CasosDeUso.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/Comentario.h"
#include "../include/Usuario.h"
#include "../include/Producto.h"
#include <iostream>
#include <string>

#include <limits>

using std::numeric_limits;
using std::streamsize;

using std::cin;
using std::cout;
using std::endl;
using std::string;

void DejarComentario()
{

    cout << " DejarComentario" << endl;
    cout << "___________________" << endl;
    cout << endl;

    ICUsuario *CUsuario = Fabrica::getICUsuario();
    ControladorProducto *CProducto = Fabrica::getICProductos();

    try
    {
        int comentario_respondido;
        vector<DTUsuario>::size_type i_usuario;

        vector<DTUsuario> usuarios = CUsuario->listarUsuarios();

        cout << " Usuarios" << endl;
        cout << "___________________" << endl;
        cout << endl;

        if (usuarios.size() == 0)
        {
            throw invalid_argument("No hay usuarios registrados.");
        }
        for (vector<DTUsuario>::size_type i = 0; i < usuarios.size(); ++i)
        {
            cout << i << "-";
            cout << usuarios[i].getNombre() << endl;
        }

        cout << "Indique el usuario" << endl;
        ;
        cin >> i_usuario;

        if (i_usuario > usuarios.size() || i_usuario < 0)
        {
            throw invalid_argument("Seleccion invalida");
        }

        cout << " Productos" << endl;
        cout << "___________________" << endl;
        cout << endl;

        vector<DTProducto> productos = CProducto->listarProductos2();

        if (productos.size() == 0)
        {
            throw invalid_argument("No hay productos registrados.");
        }
        for (vector<DTProducto>::size_type i = 0; i < productos.size(); ++i)
        {
            cout << i << "-";
            cout << productos[i].getNombre() << endl;
        }
        long unsigned int i_producto;
        cout << "Indique el Producto" << endl;
        ;
        cin >> i_producto;

        if (i_producto > productos.size() || i_producto < 0)
        {
            throw invalid_argument("Seleccion invalida");
        }

        int opcion;
        cout << "1- Realizar un comentario nuevo" << endl;
        ;
        cout << "2- Responder un comentario" << endl;
        ;
        cin >> opcion;
        if (opcion != 1 && opcion != 2)
        {
            throw invalid_argument("Seleccion invalida");
        }

        std::map<int, Comentario *> comentarios_all;
        if (opcion == 2)
        {
            std::map<int, Comentario *> comentarios_raiz = productos[i_producto].getComentarios();

            for (std::map<int, Comentario *>::iterator it = comentarios_raiz.begin(); it != comentarios_raiz.end(); ++it)
            {
                std::map<int, Comentario *> aux = it->second->printComentarios();
                comentarios_all.insert(aux.begin(), aux.end());
            }

            cout << "Indique el id del comentario a responder" << endl;
            cin >> comentario_respondido;
            if (!(std::is_same<decltype(comentario_respondido), int>::value))
            {
                throw invalid_argument("Seleccion invalida");
            }
            auto iter = comentarios_all.find(comentario_respondido);
            if (iter == comentarios_all.end())
            {
                throw invalid_argument("Seleccion invalida");
            }
        }

        string texto_comentario;
        cout << "Ingrese el comentario" << endl;
        ;
        cin >> texto_comentario;
        DTFecha fecha = DTFecha(1, 1, 1);

        Comentario *new_coment = CUsuario->AddComentario(texto_comentario, fecha, usuarios[i_usuario].getNombre());

        if (opcion == 2)
        {
            comentarios_all.find(comentario_respondido)->second->setRespuesta(new_coment);
        }
        if (opcion == 1)
        {
            CProducto->AddComentario(new_coment, i_producto);
        }
    }

    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    };
    std::cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    std::cin.get(); // Espera que el usuario presione Enter
}