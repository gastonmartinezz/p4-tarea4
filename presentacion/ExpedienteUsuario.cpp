#include "../include/Fabrica.h"
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/Controladores/ControladorProducto.h"
#include "../include/DataTypes/DTUsuario.h"
#include "../include/DataTypes/DTProducto.h"
#include "../include/DataTypes/DTCompra.h"
#include "../include/Usuario.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using std::numeric_limits;
using std::streamsize;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

std::vector<std::string> convertirPromocionesAVectorDeStrings(const std::vector<Promocion*>& promociones) {
    std::vector<std::string> descripciones;
    for (const Promocion* promo : promociones) {
        if (promo) {
            descripciones.push_back(promo->getDescripcion());
        }
    }
    return descripciones;
}

void ExpedienteUsuario()
{
    cout << endl;
    cout << " Expediente de Usuario" << endl;
    cout << "----------------------" << endl;
    cout << endl;

    ICUsuario *ctrlUsuario = Fabrica::getICUsuario();
    //ControladorProducto *ctrlProducto = Fabrica::getICProductos(); Lo comento ya que no no lo estamos utilizando

    try
    {
        vector<DTUsuario> usuarios = ctrlUsuario->listarUsuarios();

        cout << " Usuarios" << endl;
        cout << "----------------------" << endl;
        cout << endl;

        if (usuarios.size() == 0)
        {
            throw invalid_argument("No hay usuarios registrados.");
        }

        for (vector<DTUsuario>::size_type i = 0; i < usuarios.size(); ++i)
        {
            cout << i << "- " << usuarios[i].getNombre() << endl;
        }

        vector<DTUsuario>::size_type i_usuario;
        cout << "Seleccione el usuario: ";
        cin >> i_usuario;

        if (i_usuario >= usuarios.size() || i_usuario < 0)
        {
            throw invalid_argument("Selección inválida.");
        }

        DTUsuario usuarioSeleccionado = usuarios[i_usuario];
        cout << endl;
        cout << "Información del Usuario" << endl;
        cout << "-----------------------" << endl;
        cout << "Nickname: " << usuarioSeleccionado.getNombre() << endl;//??????
        cout << "Fecha de Nacimiento: " << usuarioSeleccionado.getFechaNacimiento().toString() << endl;//??????

        Usuario* usuarioPtr = ctrlUsuario->findUsuario(usuarioSeleccionado.getNombre());

        if (Vendedor* vendedor = dynamic_cast<Vendedor*>(usuarioPtr))
        {   
            vector<Producto*> listaProductos = vendedor->getProductos();
           // ctrlProducto->obtenerProductosDeVendedor(vendedor->getNickname());
            //vector<DTProducto> productos = ctrlProducto->listarProductos2(); // Asumiendo que lista productos del vendedor actual
            std::vector<std::string> promociones = convertirPromocionesAVectorDeStrings(vendedor->getPromociones()); 
          //  vector<string> promociones = vendedor->getPromociones(); // O usa otro método para obtener promociones del vendedor

            cout << endl;
            cout << "Productos a la Venta" << endl;
            cout << "--------------------" << endl;
            if (listaProductos.empty())
            {
                cout << "No tiene productos a la venta." << endl;
            }
            else
            {
                for (const auto& producto : listaProductos)
                {
                    cout << "- " << producto->getNombre() << endl;
                }
            }

            cout << endl;
            cout << "Promociones Vigentes" << endl;
            cout << "--------------------" << endl;
            if (promociones.empty())
            {
                cout << "No tiene promociones vigentes." << endl;
            }
            else
            {
                for (const auto& promocion : promociones)
                {
                    cout << "- " << promocion << endl;
                }
            }
        }
        else if (Cliente* cliente = dynamic_cast<Cliente*>(usuarioPtr))
        {
            vector<Compra*> compras = cliente->getCompras();

            cout << endl;
            cout << "Compras Realizadas" << endl;
            cout << "------------------" << endl;
            if (compras.empty())
            {
                cout << "No ha realizado compras." << endl;
            }
            else
            {
                for (const auto& compra : compras)
                {
                    cout << "Compra - Fecha: " << compra->getFecha_de_la_compra().toString() << endl;
                    vector<DTCarro> carrito = compra->getCarrito();
                    for (const auto& item : carrito)
                    {
                        cout << "  Producto: " << item.getProd() << endl;
                    }
                }
            }
        }
        else
        {
            cerr << "Tipo de usuario no reconocido." << endl;
            return;
        }
    }
    catch (const std::exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "Presiona Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}