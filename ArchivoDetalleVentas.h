#ifndef ARCHIVODETALLEVENTAS_H_INCLUDED
#define ARCHIVODETALLEVENTAS_H_INCLUDED
#pragma once
#include "DetalleVentas.h"

class ArchivoDetalleVentas{

    private:
        char nombreArchivo[20];

    public:
        ArchivoDetalleVentas();

        bool guardar(DetalleVentas detalleVenta);
        DetalleVentas Leer(int posicion);
        int contarRegistros();
        int Buscar(int id);
        void Listar();
};




#endif // ARCHIVODETALLEVENTAS_H_INCLUDED
