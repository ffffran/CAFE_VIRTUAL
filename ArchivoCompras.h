#ifndef ARCHIVOCOMPRAS_H_INCLUDED
#define ARCHIVOCOMPRAS_H_INCLUDED
#pragma once
#include "Compras.h"

class ArchivoCompras{

    private:
        char nombreArchivo[20];

    public:
        ArchivoCompras();

        bool guardar(Compras compra);
        Compras Leer(int posicion);
        int contarRegistros();
        int Buscar(int id);
        void Listar();
};




#endif // ARCHIVOCOMPRAS_H_INCLUDED
