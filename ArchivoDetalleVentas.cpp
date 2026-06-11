#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#include "ArchivoDetalleVentas.h"

ArchivoDetalleVentas::ArchivoDetalleVentas(){

    strcpy(nombreArchivo, "DetalleVentas.dat");
}

bool ArchivoDetalleVentas::guardar(DetalleVentas detalleVenta){

    FILE *DVArchivo;

    DVArchivo = fopen(nombreArchivo, "ab");

    if(DVArchivo == nullptr){

        cout<<"No se pudo abrir el archivo.";
        return false;
    }

    bool escribio = fwrite(&detalleVenta, sizeof(DetalleVentas), 1, DVArchivo);

    fclose(DVArchivo);

    return escribio;
}

DetalleVentas ArchivoDetalleVentas::Leer(int posicion){

    DetalleVentas detalleVenta;

    FILE *DVArchivo;

    DVArchivo = fopen(nombreArchivo, "rb");

    if(DVArchivo == nullptr){

        cout<<"No se pudo abrir el archivo.";
        return detalleVenta;
    }

    fseek(DVArchivo, posicion * sizeof(DetalleVentas), SEEK_SET);

    fread(&detalleVenta, sizeof(DetalleVentas), 1, DVArchivo);

    fclose(DVArchivo);

    return detalleVenta;
}

int ArchivoDetalleVentas::contarRegistros(){

    int contador = 0;

    FILE *DVArchivo;

    DetalleVentas detalleVenta;

    DVArchivo = fopen (nombreArchivo, "rb");

    if (DVArchivo == nullptr){

        return 0;
    }

    while(fread(&detalleVenta, sizeof(DetalleVentas), 1, DVArchivo) == 1){

        contador++;
    }

    fclose(DVArchivo);

    return contador;
}

int ArchivoDetalleVentas::Buscar(int id){

    DetalleVentas detalleVenta;

    FILE *DVArchivo;

    DVArchivo = fopen (nombreArchivo, "rb");

    int posicion = 0;

    while(fread(&detalleVenta, sizeof(DetalleVentas), 1, DVArchivo) == 1){

        if(detalleVenta.get_idVentaDetalle() == id){

            fclose(DVArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(DVArchivo);

    return -1;
}

void ArchivoDetalleVentas::Listar(){

    DetalleVentas detalleVenta;
    ArchivoDetalleVentas archivo;

    cout<<"DETALLE VENTAS"<<endl<<"======================="<<endl;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){

        detalleVenta = archivo.Leer(i);
        detalleVenta.mostrar();
        cout<<endl;
    }
}
