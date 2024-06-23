#include <ControladorUsuario.h>
#include <iostream>
#include <stdexcept>
#include "../include/Controladores/ControladorUsuario.h"
#include "../include/Cliente.h"
#include "../include/Vendedor.h"
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

// void obtenerProductosDeVendedor(string nickname) {
//     transform(nickname.begin(), nickname.end(), nickname.begin(), ::toupper);

//     for (auto p: vendedoresSistema) {
//         string nicknameVendedorTemporal = p->getNickname();
//         transform(nicknameVendedorTemporal.begin(), nicknameVendedorTemporal.end(), nicknameVendedorTemporal.begin(), ::toupper);

//         if (nickname == nicknameVendedorTemporal) {
//             for (auto prod: p->getProductos()) {
//                 cout << prod.getId() << endl;
//                 cout << prod.getNombre() << endl;
//             }
//         }
//     }
// }

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
    /*  if (ListaUsuarios.find(nickname) != ListaUsuarios.end())
      {
          throw std::invalid_argument("El nickname ya está en uso.");
      }

      Usuario *nuevoUsuario = new Cliente(nickname, password, fechaNacimiento, direccion);
      // ListaClientes[nickname] = dynamic_cast<Cliente *>(nuevoUsuario);
      ListaUsuarios[nickname] = nuevoUsuario;
     */
}

void ControladorUsuario::confirmarAltaCliente(string nickname, string password, DTFecha fechaNacimiento, DTDireccion direccion)
{
    Cliente *nuevoCliente = new Cliente(nickname, password, fechaNacimiento, direccion);
    ListaClientes.insert({nickname, nuevoCliente});
    ListaUsuarios.insert({nickname, nuevoCliente});
}

void ControladorUsuario::confirmarAltaVendedor(string nickname, string password, const DTFecha fechaNacimiento, std::string codigoRUT)
{
    Vendedor *nuevoVendedor = new Vendedor(nickname, password, fechaNacimiento, codigoRUT);
    ListaVendedores.insert({nickname, nuevoVendedor});
    ListaUsuarios.insert({nickname, nuevoVendedor});
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
        aux.push_back(it->second->toDataType());
    }
    return aux;
}
Producto *ControladorUsuario::AddProducto(int id, int stock, float precio, std::string nombre, std::string descripcion, Categoria cat, std::string vendedorNickname)
{
    // Buscar el vendedor por su nickname
    Vendedor *vendedor = findVendedor(vendedorNickname);
    if (vendedor == nullptr)
    {
        std::cerr << "Vendedor no encontrado." << std::endl;
        return nullptr;
    }

    // Crear el producto
    Producto *nuevoProducto = new Producto(id, stock, precio, nombre, descripcion, cat, vendedor); // Asumimos que el ID es generado automáticamente o es irrelevante para este ejemplo

    // Agregar el producto al vendedor
    vendedor->agregarProducto(nuevoProducto);

    // Opcionalmente, agregar el producto a una colección global si existe
    // productosSistema.push_back(nuevoProducto);

    return nuevoProducto;
}
Comentario *ControladorUsuario::AddComentario(std::string texto_comentario, DTFecha fecha, std::string nickname)
{
    Usuario *usuario = findUsuario(nickname);
    if (usuario)
    {
        incrementarContador();
        int comentario_id = getContador();
        Comentario *nuevoComentario = new Comentario(comentario_id, texto_comentario, fecha);
        nuevoComentario->setQuienComenta(usuario);
        usuario->addComentario(nuevoComentario);
        return nuevoComentario;
    }
    return nullptr;
}

Usuario *ControladorUsuario::findUsuario(std::string nickname)
{
    auto it = ListaUsuarios.find(nickname);
    if (it != ListaUsuarios.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

Vendedor *ControladorUsuario::findVendedor(std::string nickname)
{
    auto it = ListaVendedores.find(nickname);
    if (it != ListaVendedores.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
}

Cliente *ControladorUsuario::findCliente(std::string nickname)
{
    auto it = ListaClientes.find(nickname);
    if (it != ListaClientes.end())
    {
        return it->second;
    }
    else
    {
        return nullptr;
    }
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

void ControladorUsuario::agregarSuscripcion(Cliente *cliente, Vendedor *vendedor)
{
    if (!(vendedor->getSuscriptores().count(cliente) > 0))
    {
        vendedor->getSuscriptores().insert(cliente);
    }
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

vector<DTVendedor> ControladorUsuario::obtenerVendedoresNoSuscriptos(Cliente *cliente)
{
    vector<DTVendedor> vendedores = {};
    vector<DTVendedor> vendedoresNoSuscriptos = {};

    for (auto it = vendedores.begin(); it != vendedores.end(); ++it)
    {
        if (!(it->getSuscriptores().count(cliente) > 0))
        {
            vendedoresNoSuscriptos.push_back(*it);
        }
    }

    return vendedoresNoSuscriptos;
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

// void obtenerListaVendedoresSistema()
// {
//     for (auto p : vendedoresSistema)
//     {
//         cout << p->getNickname() << endl;
//     }
// }

void ControladorUsuario::incrementarContador()
{
    contador_id_comentario++;
}

void ControladorUsuario::decrementarContador()
{
    if (contador_id_comentario > 0)
    {
        contador_id_comentario--;
    }
}

int ControladorUsuario::getContador()
{
    return contador_id_comentario;
}

void ControladorUsuario::cargarDatosPrueba()
{
    DTFecha fechaAna(15, 5, 1988);
    DTFecha fechaCarlos(18, 6, 1986);
    DTFecha fechaDiegom(28, 7, 1993);
    // Continuar con otras fechas...

    // Direcciones predefinidas
    DTDireccion direccionJuan("Montevideo", "Rondeau", 1617);
    DTDireccion direccionLaura("Montevideo", "Av. Brasil", 1011);
    DTDireccion direccionNatalia("Salto", "Paysandú", 2021);
    // Continuar con otras direcciones...

    // Alta de vendedores
    confirmarAltaVendedor("ana23", "qwer1234", fechaAna, "212345678001");
    confirmarAltaVendedor("carlos78", "asdfghj", fechaCarlos, "356789012345");
    confirmarAltaVendedor("diegom", "zxcvbn", fechaDiegom, "190123456789");
    // Continuar con otros vendedores...

    // Alta de clientes
    confirmarAltaCliente("juan87", "1qaz2wsx", DTFecha(20, 10, 1992), direccionJuan);
    confirmarAltaCliente("laura", "3edc4rfv", DTFecha(22, 9, 1979), direccionLaura);
    confirmarAltaCliente("natalia", "poiuyt", DTFecha(14, 4, 1982), direccionNatalia);
    // Continúa con los demás clientes
}
