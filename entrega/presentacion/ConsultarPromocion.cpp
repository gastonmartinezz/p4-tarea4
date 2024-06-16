//Caso de Uso: Consultar Promocion

DataPromocion obtenerPromocionesActivas(DTFecha fecha) {
    for (auto f: promociones) {
        for (auto p: Promocion) {
            if (compararFechas(getFechaVencimiento(p)), fecha) {
                promocionesVigentes.insert(p);
            }
        }
    }
}

set<DTPromocion> seleccionarPromocion(string nombre) {
    string nombreNuevo = (string)toupper(nombre);

    for (auto p: promocionesVigentes) {
        if (nombreNuevo == (string)toupper(p->vendedour->nombre)) {
            //Imprimir datos del vendedor y los productos de la promocion (fijarse en cambiar el tipo de devolucion de la funcion)
        }
    }
}

