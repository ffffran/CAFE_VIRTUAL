#ifndef ARCHIVOPRODUCTOS_H_INCLUDED
#define ARCHIVOPRODUCTOS_H_INCLUDED
#pragma once
#include "Productos.h"

class ArchivoProductos{

    private:
        char nombreArchivo[20];

    public:
        ArchivoProductos();

        bool guardar(Productos producto);
        Productos Leer(int posicion);
        bool contarRegistros(bool estado);
        int Buscar(int id);
        bool Modificar(Productos producto, int posicion);
        int Listar();
};

#endif // ARCHIVOPRODUCTOS_H_INCLUDED
