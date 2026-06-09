#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#include "ArchivoVentas.h"

ArchivoVentas::ArchivoVentas(){

    strcpy(nombreArchivo, "Ventas.dat");
}

bool ArchivoVentas::guardar(Ventas venta){

    FILE *VArchivo;

    VArchivo = fopen(nombreArchivo, "ab");

    if(VArchivo == nullptr){

        cout<<"No se pudo abrir el archivo :(";
        return false;
    }

    bool escribio = fwrite(&venta, sizeof(Ventas), 1, VArchivo);

    fclose(VArchivo);

    return escribio;
}

Ventas ArchivoVentas::Leer(int posicion){

    Ventas venta;

    FILE *VArchivo;

    VArchivo = fopen(nombreArchivo, "rb");

    if(VArchivo == nullptr){

        cout<<"No se pudo abrir el archivo :(";
        return venta;
    }

    fseek(VArchivo, posicion * sizeof(Ventas), SEEK_SET);

    fread(&venta, sizeof(Ventas), 1, VArchivo);

    fclose(VArchivo);

    return venta;
}

int ArchivoVentas::contarRegistros(){

    int contador = 0;

    FILE *VArchivo;

    Ventas venta;

    VArchivo = fopen (nombreArchivo, "rb");

    if (VArchivo == nullptr){

        return 0;
    }

    while(fread(&venta, sizeof(Ventas), 1, VArchivo) == 1){

        contador++;
    }

    fclose(VArchivo);

    return contador;
}

int ArchivoVentas::Buscar(int id){

    Ventas venta;

    FILE *VArchivo;

    VArchivo = fopen (nombreArchivo, "rb");

    int posicion = 0;

    while(fread(&venta, sizeof(Ventas), 1, VArchivo) == 1){

        if(venta.get_idVenta() == id){

            fclose(VArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(VArchivo);

    return -1;
}

void ArchivoVentas::Listar(){

    Ventas venta;
    ArchivoVentas archivo;

    cout<<"VENTAS"<<endl<<"======================="<<endl;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){

        venta = archivo.Leer(i);
        venta.mostrar();
        cout<<endl;
    }
}

