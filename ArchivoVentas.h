#ifndef ARCHIVOVENTAS_H_INCLUDED
#define ARCHIVOVENTAS_H_INCLUDED
#pragma once
#include "Ventas.h"

class ArchivoVentas{

    private:
        char nombreArchivo[20];

    public:
        ArchivoVentas();

        bool guardar(Ventas venta);
        Ventas Leer(int posicion);
        int contarRegistros();
        int Buscar(int id);
        void Listar();
};


#endif // ARCHIVOVENTAS_H_INCLUDED


