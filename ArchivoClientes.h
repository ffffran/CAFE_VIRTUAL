#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED
#pragma once
#include "Clientes.h"

class ArchivoClientes{

    private:
        char nombreArchivo[20];

    public:
        ArchivoClientes();

        bool guardar(Clientes cliente);
        Clientes Leer(int posicion);
        int contarRegistros(bool estado);
        int Contar();
        int Buscar(int id);
        bool Modificar(Clientes cliente, int posicion);
        int Listar();
};



#endif // ARCHIVOCLIENTES_H_INCLUDED
