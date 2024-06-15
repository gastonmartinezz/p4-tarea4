#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <string>
#include <vector>
#include <set>
#include "Usuario.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "Comentario.h"
#include "DTFecha.h"

class ControladorUsuario {
private:
    // Constructor privado para el patrón Singleton
    ControladorUsuario() = default;
    static ControladorUsuario* instancia;

public:
    // Métodos estáticos para obtener la instancia única
    static ControladorUsuario* getInstancia();

    // Métodos del diagrama UML
    void ingresarDatosUsuario(const std::string& nickname, const std::string& password, const DTFecha& fechaNacimiento);
    void datosVendedor(const std::string& codigoRUT);
    void datosCliente(const std::string& direccion, const std::string& ciudad);
    void confirmarAltaUsuario();
    void listarUsuarios();
    void listarClientes();
    void listarComentarios();
    void eliminarComentarioYRespuestas(int comentarioId);
    void obtenerVendedoresNoSuscriptos();
    void agregarSuscripcion(const std::string& nickname);
    bool validarPassword(const std::string& nickname, const std::string& password);
    void listarComentariosUsuarioSeleccionado(const std::string& nickname);
    std::set<DTUsuario> listaVendedor();
    void eliminarComentarioYRespuestas(int comentarioId);
    void eliminarComentario(int comentarioId);
    void eliminarLinkComentario(int comentarioId);
    std::vector<Vendedor> obtenerVendedoresNoSuscriptos();
    void agregarSuscripcion(const std::string& vendedorNickname);
    std::vector<Vendedor> obtenerListaDeVendedoresSuscriptos();
    void suscribirse(const std::string& vendedorNickname);
    std::vector<std::string> obtenerNotificaciones(const std::string& nickname);
    void mostrarYEliminarNotificacion(const std::string& nickname);
    void eliminarNotificaciones(const std::string& nickname);
    std::vector<std::string> getNotificaciones(const std::string& nickname);
    std::vector<Vendedor> obtenerVendedoresSuscritos(const std::string& clienteNickname);
    void eliminarSuscripcion(const std::string& vendedorNickname, const std::string& clienteNickname);
    void registrarCompra(const Compra& compra);
};

#endif // CONTROLADORUSUARIO_H