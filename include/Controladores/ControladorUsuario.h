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

class ControladorUsuario : public ICUsuario {
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
    void ingresarDatosUsuario(const std::string &nickname, const std::string &password, const DTFecha &fechaNacimiento);
    void confirmarAltaUsuario(const std::string &direccion, const std::string &ciudad);
    void confirmarAltaVendedor(const std::string &codigoRUT);
    std::vector<DTUsuario> listarUsuarios();
    std::vector<DTCliente> listarClientes();
    std::vector<DTVendedor> listaVendedor();

    void listarComentarios();
    void datosVendedor(const string &codigoRUT);
    void datosCliente(const string &direccion, const string &ciudad);
    void eliminarComentarioYRespuestas(int comentarioId);
    virtual std::vector<Vendedor> obtenerVendedoresNoSuscriptos();
    bool validarPassword(const std::string &nickname, const std::string &password);
    void listarComentariosUsuarioSeleccionado(const std::string &nickname);
    void confirmarAltaUsuario(std::string &nickname, std::string &password, DTFecha &fechaNacimiento, DTDireccion &direccion); //Le saque ciudad pq no me compilaba - Tonga
    void eliminarComentario(int comentarioId);
    void eliminarLinkComentario(int comentarioId);
    void agregarSuscripcion(const std::string &vendedorNickname);
    std::vector<Vendedor> obtenerListaDeVendedoresSuscriptos();
    void suscribirse(const std::string &vendedorNickname);
    std::vector<std::string> obtenerNotificaciones(const std::string &nickname);
    void mostrarYEliminarNotificacion(const std::string &nickname);
    void eliminarNotificaciones(const std::string &nickname);
    std::vector<std::string> getNotificaciones(const std::string &nickname);
    std::vector<Vendedor> obtenerVendedoresSuscritos(const std::string &clienteNickname);
    void eliminarSuscripcion(const std::string &vendedorNickname, const std::string &clienteNickname);
    void registrarCompra(const Compra &compra);
};

#endif // CONTROLADORUSUARIO_H