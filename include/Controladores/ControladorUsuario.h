#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include "../include/Usuario.h"
#include "../include/Interfaces/ICUsuario.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
#include "../include/Comentario.h"
#include "../include/DataTypes/DTFecha.h"
#include "../include/DataTypes/DTUsuario.h"
#include "../include/DataTypes/DTVendedor.h"
#include "../include/DataTypes/DTCliente.h"

class ControladorUsuario : public ICUsuario
{
private:
    // Constructor privado para el patrón Singleton
    ControladorUsuario() = default;
    static ControladorUsuario *instance;

    map<string, Usuario *> ListaUsuarios;
    map<string, Cliente *> ListaClientes;
    map<string, Vendedor *> ListaVendedores;

    // // Miembros temporales para el registro de usuarios en AltaUsuario.cpp
    // string nicknameTemp;
    // string passwordTemp;
    // DTFecha fechaNacimientoTemp;
    // string direccionTemp;
    // string ciudadTemp;
    // string codigoRUTTemp;
    // bool esClienteTemp;

public:
    /*
        // Métodos estáticos para obtener la instancia única
        static ControladorUsuario *getInstancia();

        // Métodos del diagrama UML
        void ingresarDatosUsuario(const string &nickname, const string &password, const DTFecha &fechaNacimiento);
        void datosVendedor(const string &codigoRUT);
        void datosCliente(const string &direccion, const string &ciudad);
        void confirmarAltaUsuario();
        vector<DTUsuario> listarUsuarios();
        vector<DTCliente> listarClientes();
        vector<DTVendedor> listaVendedor();
        void listarComentarios();
        void eliminarComentarioYRespuestas(int comentarioId);
        void agregarSuscripcion(const string &nickname);
        bool validarPassword(const string &nickname, const string &password);
        void listarComentariosUsuarioSeleccionado(const string &nickname);

        void eliminarComentario(int comentarioId);
        void eliminarLinkComentario(int comentarioId);
        std::vector<Vendedor> obtenerVendedoresNoSuscriptos();

        std::vector<Vendedor> obtenerListaDeVendedoresSuscriptos();
        void suscribirse(const std::string &vendedorNickname);
        std::vector<std::string> obtenerNotificaciones(const std::string &nickname);
        void mostrarYEliminarNotificacion(const std::string &nickname);
        void eliminarNotificaciones(const std::string &nickname);
        std::vector<std::string> getNotificaciones(const std::string &nickname);
        std::vector<Vendedor> obtenerVendedoresSuscritos(const std::string &clienteNickname);
        void eliminarSuscripcion(const std::string &vendedorNickname, const std::string &clienteNickname);
        void registrarCompra(const Compra &compra);
        void obtenerListaVendedoresSistema();
    };

    #endif // CONTROLADORUSUARIO_H

    */

    // Métodos estáticos para obtener la instancia única
    static ControladorUsuario *getInstance();

    // Métodos del diagrama UML
    void ingresarDatosUsuario(const string &nickname, const string &password, const DTFecha &fechaNacimiento);

    vector<DTUsuario> listarUsuarios();
    vector<DTCliente> listarClientes();
    vector<DTVendedor> listaVendedor();

    void listarComentarios();
    void datosVendedor(const string &codigoRUT);
    void datosCliente(const string &direccion, const string &ciudad);
    void eliminarComentarioYRespuestas(int comentarioId);
    vector<Vendedor> obtenerVendedoresNoSuscriptos();
    bool validarPassword(const string &nickname, const string &password);
    void listarComentariosUsuarioSeleccionado(const string &nickname);
    void confirmarAltaUsuario(string &nickname, string &password, DTFecha &fechaNacimiento, DTDireccion &direccion); // Le saque ciudad pq no me compilaba - Tonga
    void confirmarAltaVendedor(string &nickname, string &password, const DTFecha &fechaNacimiento, string &codigoRUT);
    void eliminarComentario(int comentarioId);
    void eliminarLinkComentario(int comentarioId);
    void agregarSuscripcion(const std::string &vendedorNickname);
    vector<Vendedor> obtenerListaDeVendedoresSuscriptos();
    void suscribirse(const string &vendedorNickname);
    vector<string> obtenerNotificaciones(const string &nickname);
    void mostrarYEliminarNotificacion(const string &nickname);
    void eliminarNotificaciones(const string &nickname);
    vector<string> getNotificaciones(const string &nickname);
    vector<Vendedor> obtenerVendedoresSuscritos(const string &clienteNickname);
    void eliminarSuscripcion(const string &vendedorNickname, const string &clienteNickname);
    void registrarCompra(const Compra &compra);
};

#endif // CONTROLADORUSUARIO_H