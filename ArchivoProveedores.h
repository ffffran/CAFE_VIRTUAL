#ifndef ARCHIVOPROVEEDORES_H_INCLUDED
#define ARCHIVOPROVEEDORES_H_INCLUDED
#pragma once
#include "Proveedores.h"

class ArchivoProveedores{

    private:
        char nombreArchivo[20];

    public:
        ArchivoProveedores();

        bool guardar(Proveedores proveedor);
        Proveedores Leer(int posicion);
        int contarRegistros();
        int Buscar(int id);
        void Listar();
        bool Modificar(Proveedores proveedor, int posicion);
        int Contar();

};



#endif // ARCHIVOPROVEEDORES_H_INCLUDED
