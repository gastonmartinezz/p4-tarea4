#include "Sistema.h"

int main() {
    Sistema sistema;
    DTFecha fechaNacimiento = {1, 1, 2000};
    DTDireccion direccion = {"Calle Falsa 123", "Ciudad", "Pais"};

    sistema.altaUsuario("cliente", "cliente1", "password", fechaNacimiento, direccion);
    sistema.altaUsuario("vendedor", "vendedor1", "password123", fechaNacimiento, {}, 123456789012);

    sistema.mostrarUsuarios();

    return 0;
}
