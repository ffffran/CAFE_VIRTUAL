#include <cstring>
#include <cstdio>
#include <iostream>
#include <iomanip>
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

int ArchivoProveedores::contarRegistros(bool estado){

    int contador = 0;

    FILE *PArchivo;

    Proveedores proveedor;

    PArchivo = fopen (nombreArchivo, "rb");

    if (PArchivo == nullptr){

        return 0;
    }

    while(fread(&proveedor, sizeof(Proveedores), 1, PArchivo) == 1){

        if(proveedor.get_estadoProveedor() == estado){

            contador++;
        }
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

    cout<<left;
    cout<<setw(6)<<"ID";
    cout<<setw(40)<<"NOMBRE";
    cout<<setw(30)<<"RUBRO";
    cout<<setw(30)<<"PAIS";
    cout<<setw(30)<<"LOCACION";
    cout<<setw(20)<<"TELEFONO";
    cout<<setw(8)<<"ESTADO";
    cout<<endl;

    cout<<string(155, '.')<<endl;

    for(int i = 0; i < archivo.Contar(); i++){

        proveedor = archivo.Leer(i);

        if(proveedor.get_estadoProveedor()){

            proveedor.mostrar();
        }
    }

    system("pause");
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

int ArchivoProveedores::Contar(){

    FILE *PRArchivo;

    PRArchivo = fopen(nombreArchivo, "rb");

    int cantidad;

    if(PRArchivo == nullptr){

        cout<<"El archivo es nuevo";
        return 0;
    }

    fseek(PRArchivo, 0, SEEK_END);

    cantidad = ftell(PRArchivo) / sizeof(Proveedores);

    fclose(PRArchivo);
    return cantidad;
}
