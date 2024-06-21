#ifndef ICUSUARIO_H
#define ICUSUARIO_H

#include <string>
#include <vector>
#include <set>
#include "DataTypes/DTFecha.h"
#include "DataTypes/DTCliente.h"
#include "Usuario.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "Comentario.h"

class ICUsuario
{
public:
    virtual ~ICUsuario() = default;

    virtual void ingresarDatosUsuario(const std::string &nickname, const std::string &password, const DTFecha &fechaNacimiento) = 0;
    virtual void datosVendedor(const std::string &codigoRUT) = 0;
    virtual void datosCliente(const std::string &direccion, const std::string &ciudad) = 0;
    virtual void confirmarAltaUsuario(string &nickname, string &password, DTFecha &fechaNacimiento, DTDireccion &direccion) = 0;
    virtual std::vector<DTUsuario> listarUsuarios() = 0;
    virtual std::vector<DTCliente> listarClientes() = 0;
    virtual std::vector<DTVendedor> listaVendedor() = 0;

    virtual void listarComentarios() = 0;
    virtual void eliminarComentarioYRespuestas(int comentarioId) = 0;

    virtual void agregarSuscripcion(const std::string &nickname) = 0;
    virtual bool validarPassword(const std::string &nickname, const std::string &password) = 0;
    virtual void listarComentariosUsuarioSeleccionado(const std::string &nickname) = 0;
    virtual void eliminarComentario(int comentarioId) = 0;
    virtual void eliminarLinkComentario(int comentarioId) = 0;
    virtual std::vector<Vendedor> obtenerVendedoresNoSuscriptos() = 0;
    virtual std::vector<Vendedor> obtenerListaDeVendedoresSuscriptos() = 0;
    virtual void suscribirse(const std::string &vendedorNickname) = 0;
    virtual std::vector<std::string> obtenerNotificaciones(const std::string &nickname) = 0;
    virtual void mostrarYEliminarNotificacion(const std::string &nickname) = 0;
    virtual void eliminarNotificaciones(const std::string &nickname) = 0;
    virtual std::vector<std::string> getNotificaciones(const std::string &nickname) = 0;
    virtual std::vector<Vendedor> obtenerVendedoresSuscritos(const std::string &clienteNickname) = 0;
    virtual void eliminarSuscripcion(const std::string &vendedorNickname, const std::string &clienteNickname) = 0;
    virtual void registrarCompra(const Compra &compra) = 0;
    virtual Usuario *findUsuario(string nickname) = 0;
    virtual Comentario *AddComentario(std::string texto_comentario, DTFecha fecha, std::string nickname) = 0;
};

#endif // ICUSUARIO_H
