//Caso de Uso: Consultar Producto

string mostrarInfoProductos() {
    for (auto p: productosSistemas) {
        cout << "Id: " << p->id << endl;    
        cout << "Nombre: " << p->nombre << endl;
    }
}

void seleccionaYMostrarDataProductos(int id) {
    for (auto p: productosSistemas) {
        if (id == p->id) {
            cout << "Precio: " << p->precio << endl;
            cout << "Stock: " << p->stock << endl;
            cout << "Descripcion: " << p->descripcion << endl;
            cout << "Vendedor: " << p->vendedor->nickname << endl;
        }
    }
}
