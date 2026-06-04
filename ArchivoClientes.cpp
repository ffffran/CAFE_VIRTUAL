#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#include "ArchivoClientes.h"

ArchivoClientes::ArchivoClientes(){

    strcpy(nombreArchivo, "Clientes.dat");
}

bool ArchivoClientes::guardar(Clientes cliente){

    FILE *CArchivo;

    CArchivo = fopen(nombreArchivo, "ab");

    if(CArchivo == nullptr){

        ///cout<<"No se pudo guardar el registro";
        return false;
    }

    bool escribio = fwrite(&cliente, sizeof(Clientes), 1, CArchivo);

    fclose(CArchivo);

    return escribio;

}

Clientes ArchivoClientes::Leer(int posicion){

    Clientes cliente;

    FILE *CArchivo;

    CArchivo = fopen (nombreArchivo, "rb");

    if(CArchivo == nullptr){

        ///cout<<"No se pudo leer el archivo";
        return cliente;
    }

    fseek(CArchivo, posicion * sizeof(Clientes), SEEK_SET);

    fread(&cliente, sizeof(Clientes), 1, CArchivo);

    fclose(CArchivo);

    return cliente;
}

int  ArchivoClientes::contarRegistros(bool estado){

    int contador = 0;

    FILE *CArchivo;

    Clientes cliente;

    CArchivo = fopen (nombreArchivo, "rb");

    if (CArchivo == nullptr){

        return 0;
    }

    while(fread(&cliente, sizeof(Clientes), 1, CArchivo) == 1){

        if(cliente.get_miembroCliente() == estado){

            contador++;
        }
    }

    fclose(CArchivo);

    return contador;
}

int ArchivoClientes::Buscar(int id){

    Clientes cliente;

    FILE *CArchivo;

    CArchivo = fopen (nombreArchivo, "rb");

    int posicion = 0;

    while(fread(&cliente, sizeof(Clientes), 1, CArchivo) == 1){

        if(cliente.get_idCliente() == id){

            fclose(CArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(CArchivo);

    return -1;
}

bool ArchivoClientes::Modificar(Clientes cliente, int posicion){

    FILE *CArchivo;

    CArchivo = fopen (nombreArchivo, "rb+");

    bool escribio;

    if(CArchivo == nullptr){

        cout<<"No se pudo abrir el archivo";
        return false;
    }

    fseek(CArchivo, posicion * sizeof(Clientes), SEEK_SET);

    escribio = fwrite(&cliente, sizeof(Clientes), 1, CArchivo);

    fclose(CArchivo);

    return escribio;
}


int ArchivoClientes::Listar(){

    FILE *CArchivo;

    CArchivo = fopen(nombreArchivo, "rb");

    int cantidad;

    if(CArchivo == nullptr){

        cout<<"No se pudo abrir el archivo";
        return false;
    }

    fseek(CArchivo, 0, SEEK_END);

    cantidad = ftell(CArchivo) / sizeof(Clientes);

    fclose(CArchivo);

    return cantidad;
}



