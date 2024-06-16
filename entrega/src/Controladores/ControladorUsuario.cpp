#include "ControladorUsuario.h"
#include <iostream>

// Inicialización de la instancia singleton
ControladorUsuario *ControladorUsuario::instancia = nullptr;

ControladorUsuario *ControladorUsuario::getInstancia()
{
    if (instancia == nullptr)
    {
        instancia = new ControladorUsuario();
    }
    return instancia;
}

void ControladorUsuario::ingresarDatosUsuario(const std::string &nickname, const std::string &password, const DTFecha &fechaNacimiento)
{
    // Implementación para ingresar datos de usuario
}

void ControladorUsuario::datosVendedor(const std::string &codigoRUT)
{
    // Implementación para ingresar datos de vendedor
}

void ControladorUsuario::datosCliente(const std::string &direccion, const std::string &ciudad)
{
    // Implementación para ingresar datos de cliente
}

void ControladorUsuario::confirmarAltaUsuario()
{
    // Implementación para confirmar alta de usuario
}

std::vector<DTUsuario> ControladorUsuario::listarUsuarios()
{
}

std::vector<DTUsuario> ControladorUsuario::listarClientes()
{
    // Implementación para listar clientes
}

void ControladorUsuario::listarComentarios()
{
    // Implementación para listar comentarios
}

void ControladorUsuario::eliminarComentarioYRespuestas(int comentarioId)
{
    // Implementación para eliminar comentario y respuestas
}

void ControladorUsuario::obtenerVendedoresNoSuscriptos()
{
    // Implementación para obtener vendedores no suscriptos
}

void ControladorUsuario::agregarSuscripcion(const std::string &nickname)
{
    // Implementación para agregar suscripción
}

bool ControladorUsuario::validarPassword(const std::string &nickname, const std::string &password)
{
    // Implementación para validar contraseña
    return false; // Valor de retorno por defecto, cambiar según implementación
}

void ControladorUsuario::listarComentariosUsuarioSeleccionado(const std::string &nickname)
{
    // Implementación para listar comentarios de usuario seleccionado
}

std::set<DTUsuario> ControladorUsuario::listaVendedor()
{
    // Implementación para obtener lista de vendedores
    return std::set<DTUsuario>(); // Valor de retorno por defecto, cambiar según implementación
}

void ControladorUsuario::eliminarComentarioYRespuestas(int comentarioId)
{
    // Implementación para eliminar comentario y respuestas
}

void ControladorUsuario::eliminarComentario(int comentarioId)
{
    // Implementación para eliminar comentario
}

void ControladorUsuario::eliminarLinkComentario(int comentarioId)
{
    // Implementación para eliminar link de comentario
}

std::vector<Vendedor> ControladorUsuario::obtenerVendedoresNoSuscriptos()
{
    // Implementación para obtener vendedores no suscriptos
    return std::vector<Vendedor>(); // Valor de retorno por defecto, cambiar según implementación
}

void ControladorUsuario::agregarSuscripcion(const std::string &vendedorNickname)
{
    // Implementación para agregar suscripción
}

std::vector<Vendedor> ControladorUsuario::obtenerListaDeVendedoresSuscriptos()
{
    // Implementación para obtener lista de vendedores suscriptos
    return std::vector<Vendedor>(); // Valor de retorno por defecto, cambiar según implementación
}

void ControladorUsuario::suscribirse(const std::string &vendedorNickname)
{
    // Implementación para suscribirse a un vendedor
}

std::vector<std::string> ControladorUsuario::obtenerNotificaciones(const std::string &nickname)
{
    // Implementación para obtener notificaciones
    return std::vector<std::string>(); // Valor de retorno por defecto, cambiar según implementación
}

void ControladorUsuario::mostrarYEliminarNotificacion(const std::string &nickname)
{
    // Implementación para mostrar y eliminar notificación
}

void ControladorUsuario::eliminarNotificaciones(const std::string &nickname)
{
    // Implementación para eliminar notificaciones
}

std::vector<std::string> ControladorUsuario::getNotificaciones(const std::string &nickname)
{
    // Implementación para obtener notificaciones
    return std::vector<std::string>(); // Valor de retorno por defecto, cambiar según implementación
}

std::vector<Vendedor> ControladorUsuario::obtenerVendedoresSuscritos(const std::string &clienteNickname)
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