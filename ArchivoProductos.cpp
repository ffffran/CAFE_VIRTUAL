#include <cstring>
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
#include "ArchivoProductos.h"

ArchivoProductos::ArchivoProductos(){

    strcpy(nombreArchivo, "Productos.dat");
}

bool ArchivoProductos::guardar(Productos producto){

    FILE *PArchivo;

    PArchivo = fopen(nombreArchivo, "ab");

    if(PArchivo == nullptr){

        ///cout<<"No se pudo guardar el registro";
        return false;
    }

    bool escribio = fwrite(&producto, sizeof(Productos), 1, PArchivo);

    fclose(PArchivo);

    return escribio;

}

Productos ArchivoProductos::Leer(int posicion){

    Productos producto;

    FILE *PArchivo;

    PArchivo = fopen (nombreArchivo, "rb");

    if(PArchivo == nullptr){

        ///cout<<"No se pudo leer el archivo";
        return producto;
    }

    fseek(PArchivo, posicion * sizeof(Productos), SEEK_SET);

    fread(&producto, sizeof(Productos), 1, PArchivo);

    fclose(PArchivo);

    return producto;
}

int ArchivoProductos::contarRegistros(bool estado){

    int contador = 0;

    FILE *PArchivo;

    Productos producto;

    PArchivo = fopen (nombreArchivo, "rb");

    if (PArchivo == nullptr){

        return 0;
    }

    while(fread(&producto, sizeof(Productos), 1, PArchivo) == 1){

        if(producto.get_estadoProducto() == estado){

            contador++;
        }
    }

    fclose(PArchivo);

    return contador;
}

int ArchivoProductos::Buscar(int id){

    Productos producto;

    FILE *PArchivo;

    PArchivo = fopen (nombreArchivo, "rb");

    if(PArchivo == nullptr){

        cout<<"No se pudo abrir el archivo.";
        return -1;
    }

    int posicion = 0;

    while(fread(&producto, sizeof(Productos), 1, PArchivo) == 1){

        if(producto.get_idProducto() == id){

            fclose(PArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(PArchivo);

    return -1;
}

bool ArchivoProductos::Modificar(Productos producto, int posicion){

    FILE *PArchivo;

    PArchivo = fopen (nombreArchivo, "rb+");

    bool escribio;

    if(PArchivo == nullptr){

        cout<<"No se pudo abrir el archivo";
        return false;
    }

    fseek(PArchivo, posicion * sizeof(Productos), SEEK_SET);

    escribio = fwrite(&producto, sizeof(Productos), 1, PArchivo);

    fclose(PArchivo);

    return escribio;
}


int ArchivoProductos::Contar(){

    FILE *PArchivo;

    PArchivo = fopen(nombreArchivo, "rb");

    int cantidad;

    if(PArchivo == nullptr){

        cout<<"No se pudo abrir el archivo";
        return 0;
    }

    fseek(PArchivo, 0, SEEK_END);

    cantidad = ftell(PArchivo) / sizeof(Productos);

    fclose(PArchivo);

    return cantidad;
}

void ArchivoProductos::Listar(){

    Productos producto;
    ArchivoProductos parchivo;

    cout<<left;
    cout<<setw(6)<<"ID";
    cout<<setw(35)<<"NOMBRE";
    cout<<setw(12)<<"PRECIO";
    cout<<setw(15)<<"CATEGORIA";
    cout<<setw(10)<<"TAMANIO";
    cout<<setw(8)<<"STOCK";
    cout<<setw(10)<<"ESTADO";
    cout<<endl;

    cout<<string(94, '.')<<endl;

    for(int i = 0; i < parchivo.Contar(); i++){

        producto = parchivo.Leer(i);
        producto.mostrar();
    }
}

