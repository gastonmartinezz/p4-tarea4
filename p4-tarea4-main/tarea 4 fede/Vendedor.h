#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Usuario.h"

class Vendedor : public Usuario {
private:
    int codigoRut;
    std::set<Cliente> suscriptores;

public:
    Vendedor(const std::string& nickname, const std::string& password, const DTFecha& fechaDeNacimiento,
             int codigoRut);

    int getCodigoRut() const;
    std::set<Cliente> getSuscriptores() const;

    void setCodigoRut(int codigoRut);
    void agregarSuscriptor(const Cliente& cliente);
    void eliminarSuscriptor(const Cliente& cliente);

    void mostrarInformacion() const override;
};

#endif // VENDEDOR_H
