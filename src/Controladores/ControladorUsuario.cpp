#include <ControladorUsuario.h>
#include <iostream>
#include <stdexcept>
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/Cliente.h"
using namespace std;

// Inicialización de la instancia singleton
ControladorUsuario *ControladorUsuario::instance = NULL;

ControladorUsuario *ControladorUsuario::getInstance()
{
    if (instance == nullptr)
    {
        instance = new ControladorUsuario();
    }
    return instance;
}

void ControladorUsuario::ingresarDatosUsuario(const std::string &nickname, const std::string &password, const DTFecha &fechaNacimiento)
{
    if (ListaUsuarios.find(nickname) != ListaUsuarios.end())
    {
        throw std::invalid_argument("El nickname ya está en uso.");
    }
    if (password.length() < 6)
    {
        throw std::invalid_argument("La contraseña debe tener al menos 6 caracteres.");
    }

    // Aquí solo podemos validar los datos básicos del usuario.
}

void ControladorUsuario::datosVendedor(const string &codigoRUT)
{
    if (codigoRUT.length() != 12)
    {
        throw invalid_argument("El código RUT debe tener 12 caracteres.");
    }
    string codigoRUTTemp = codigoRUT;
    // bool esClienteTemp = false; !!!!!LO COMENTE PORQUE ME DABA ERROR DE COMPILACION - TONGA
}

void ControladorUsuario::datosCliente(const string &direccion, const string &ciudad)
{
    string direccionTemp = direccion;
    string ciudadTemp = ciudad;
    // esClienteTemp = true;  !!!!!LO COMENTE PORQUE ME DABA ERROR DE COMPILACION - TONGA
}

void ControladorUsuario::confirmarAltaUsuario(string &nickname, string &password, DTFecha &fechaNacimiento, DTDireccion &direccion)
{
    if (ListaUsuarios.find(nickname) != ListaUsuarios.end())
    {
        throw std::invalid_argument("El nickname ya está en uso.");
    }

    Usuario *nuevoUsuario = new Cliente(nickname, password, fechaNacimiento, direccion);
    ListaClientes[nickname] = dynamic_cast<Cliente *>(nuevoUsuario);
    ListaUsuarios[nickname] = nuevoUsuario;
}

void ControladorUsuario::confirmarAltaVendedor(string &nickname, string &password, const DTFecha &fechaNacimiento, string &codigoRUT)
{
    if (ListaUsuarios.find(nickname) != ListaUsuarios.end())
    {
        throw std::invalid_argument("El nickname ya está en uso.");
    }
    if (codigoRUT.length() != 12)
    {
        throw std::invalid_argument("El código RUT debe tener 12 caracteres.");
    }

    Usuario *nuevoUsuario = new Vendedor(nickname, password, fechaNacimiento, std::stoi(codigoRUT));
    ListaVendedores[nickname] = dynamic_cast<Vendedor *>(nuevoUsuario);
    ListaUsuarios[nickname] = nuevoUsuario;
}

vector<DTUsuario> ControladorUsuario::listarUsuarios()
{
    vector<DTUsuario> aux;

    for (auto it = ListaUsuarios.begin(); it != ListaUsuarios.end(); it++)
    {
        aux.push_back(it->second->toDataType());
    }
    return aux;
}

vector<DTCliente> ControladorUsuario::listarClientes()
{
    vector<DTCliente> aux;

    for (auto it = ListaClientes.begin(); it != ListaClientes.end(); it++)
    {
        aux.push_back(it->second->toDataType());
    }
    return aux;
}

vector<DTVendedor> ControladorUsuario::listaVendedor()
{
    vector<DTVendedor> aux;
    for (auto it = ListaVendedores.begin(); it != ListaVendedores.end(); it++)
    {
        // aux.push_back(it->second->toDataType()); !!!! LO COMENTE PORQUE NO ME DEJABA COMPILAR, HAY QUE ARREGLARLO DESPUES - TONGA
    }
    return aux;
}

void ControladorUsuario::listarComentarios()
{
    // Implementación para listar comentarios
}

void ControladorUsuario::eliminarComentarioYRespuestas(int comentarioId)
{
    // Implementación para eliminar comentario y respuestas
}

/* void ControladorUsuario::obtenerVendedoresNoSuscriptos()
{
    // Implementación para obtener vendedores no suscriptos
} */

void ControladorUsuario::agregarSuscripcion(const string &nickname)
{
    // Implementación para agregar suscripción
}

bool ControladorUsuario::validarPassword(const string &nickname, const string &password)
{
    auto it = ListaUsuarios.find(nickname);
    if (it != ListaUsuarios.end() && it->second->getPassword() == password)
    {
        return true;
    }
    return false;
}

void ControladorUsuario::listarComentariosUsuarioSeleccionado(const string &nickname)
{
    // Implementación para listar comentarios de usuario seleccionado
}

void ControladorUsuario::eliminarComentario(int comentarioId)
{
    // Implementación para eliminar comentario
}

void ControladorUsuario::eliminarLinkComentario(int comentarioId)
{
    // Implementación para eliminar link de comentario
}

vector<Vendedor> ControladorUsuario::obtenerVendedoresNoSuscriptos()
{
    // Implementación para obtener vendedores no suscriptos
    return vector<Vendedor>(); // Valor de retorno por defecto, cambiar según implementación
}

vector<Vendedor> ControladorUsuario::obtenerListaDeVendedoresSuscriptos()
{
    // Implementación para obtener lista de vendedores suscriptos
    return vector<Vendedor>(); // Valor de retorno por defecto, cambiar según implementación
}

void ControladorUsuario::suscribirse(const string &vendedorNickname)
{
    // Implementación para suscribirse a un vendedor
}

vector<std::string> ControladorUsuario::obtenerNotificaciones(const string &nickname)
{
    // Implementación para obtener notificaciones
    return std::vector<std::string>(); // Valor de retorno por defecto, cambiar según implementación
}

void ControladorUsuario::mostrarYEliminarNotificacion(const string &nickname)
{
    // Implementación para mostrar y eliminar notificación
}

void ControladorUsuario::eliminarNotificaciones(const string &nickname)
{
    // Implementación para eliminar notificaciones
}

vector<std::string> ControladorUsuario::getNotificaciones(const string &nickname)
{
    // Implementación para obtener notificaciones
    return std::vector<std::string>(); // Valor de retorno por defecto, cambiar según implementación
}

vector<Vendedor> ControladorUsuario::obtenerVendedoresSuscritos(const string &clienteNickname)
{
    // Implementación para obtener vendedores suscritos
    return std::vector<Vendedor>(); // Valor de retorno por defecto, cambiar según implementación
}

void ControladorUsuario::eliminarSuscripcion(const std::string &vendedorNickname, const std::string &clienteNickname)
{
    // Implementación para eliminar suscripción
}

void ControladorUsuario::registrarCompra(const Compra &compra)
{
    // Implementación para registrar compra
}

void obtenerListaVendedoresSistema()
{
    for (auto p : vendedoresSistema)
    {
        cout << p->getNickname() << endl;
    }
}