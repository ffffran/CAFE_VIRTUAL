#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#include "ArchivoProveedores.h"

ArchivoProveedores::ArchivoProveedores(){

    strcpy(nombreArchivo, "Proveedores.dat");
}

bool ArchivoProveedores::guardar(Proveedores proveedor){

    FILE *PArchivo;

    PArchivo = fopen(nombreArchivo, "ab");

    if(PArchivo == nullptr){

        cout<<"No se pudo abrir el archivo.";
        return false;
    }

    bool escribio = fwrite(&proveedor, sizeof(Proveedores), 1, PArchivo);

    fclose(PArchivo);

    return escribio;
}

Proveedores ArchivoProveedores::Leer(int posicion){

    Proveedores proveedor;

    FILE *PArchivo;

    PArchivo = fopen(nombreArchivo, "rb");

    if(PArchivo == nullptr){

        cout<<"No se pudo abrir el archivo.";
        return proveedor;
    }

    fseek(PArchivo, posicion * sizeof(Proveedores), SEEK_SET);

    fread(&proveedor, sizeof(Proveedores), 1, PArchivo);

    fclose(PArchivo);

    return proveedor;
}

int ArchivoProveedores::contarRegistros(){

    int contador = 0;

    FILE *PArchivo;

    Proveedores proveedor;

    PArchivo = fopen (nombreArchivo, "rb");

    if (PArchivo == nullptr){

        return 0;
    }

    while(fread(&proveedor, sizeof(Proveedores), 1, PArchivo) == 1){

        contador++;
    }

    fclose(PArchivo);

    return contador;
}

int ArchivoProveedores::Buscar(int id){

    Proveedores proveedor;

    FILE *PArchivo;

    PArchivo = fopen (nombreArchivo, "rb");

    int posicion = 0;

    while(fread(&proveedor, sizeof(Proveedores), 1, PArchivo) == 1){

        if(proveedor.get_idProveedor() == id){

            fclose(PArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(PArchivo);

    return -1;
}

void ArchivoProveedores::Listar(){

    Proveedores proveedor;
    ArchivoProveedores archivo;

    cout<<"DETALLE VENTAS"<<endl<<"======================="<<endl;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){

        proveedor = archivo.Leer(i);
        proveedor.mostrar();
        cout<<endl;
    }
}

bool ArchivoProveedores::Modificar(Proveedores proveedor, int posicion){

    FILE *PArchivo;

    PArchivo = fopen (nombreArchivo, "rb+");

    bool escribio;

    if(PArchivo == nullptr){

        cout<<"No se pudo abrir el archivo";
        return false;
    }

    fseek(PArchivo, posicion * sizeof(Proveedores), SEEK_SET);

    escribio = fwrite(&proveedor, sizeof(Proveedores), 1, PArchivo);

    fclose(PArchivo);

    return escribio;
}
