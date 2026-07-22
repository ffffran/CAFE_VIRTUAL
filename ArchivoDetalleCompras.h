#ifndef ARCHIVODETALLECOMPRAS_H_INCLUDED
#define ARCHIVODETALLECOMPRAS_H_INCLUDED
#pragma once
#include "DetalleCompras.h"

class ArchivoDetalleCompras{

    private:
        char nombreArchivo[20];

    public:
        ArchivoDetalleCompras();

        bool guardar(DetalleCompras detalleCompra);
        DetalleCompras Leer(int posicion);
        int contarRegistros();
        int Buscar(int id);
        void Listar();
        void Mostrar1(int id);
};




#endif // ARCHIVODETALLECOMPRAS_H_INCLUDED
