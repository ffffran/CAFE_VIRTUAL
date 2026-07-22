#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#include "ArchivoCompras.h"

ArchivoCompras::ArchivoCompras(){

    strcpy(nombreArchivo, "Compras.dat");
}

bool ArchivoCompras::guardar(Compras compra){

    FILE *CArchivo;

    CArchivo = fopen(nombreArchivo, "ab");

    if(CArchivo == nullptr){

        cout<<"No se pudo abrir el archivo";
        return false;
    }

    bool escribio = fwrite(&compra, sizeof(Compras), 1, CArchivo);

    fclose(CArchivo);

    return escribio;
}

Compras ArchivoCompras::Leer(int posicion){

    Compras compra;

    FILE *CArchivo;

    CArchivo = fopen(nombreArchivo, "rb");

    if(CArchivo == nullptr){

        cout<<"No se pudo abrir el archivo";
        return compra;
    }

    fseek(CArchivo, posicion * sizeof(Compras), SEEK_SET);

    fread(&compra, sizeof(Compras), 1, CArchivo);

    fclose(CArchivo);

    return compra;
}

int ArchivoCompras::contarRegistros(){

    int contador = 0;

    Compras compra;

    FILE *CArchivo;

    CArchivo = fopen(nombreArchivo, "rb");

    if(CArchivo == nullptr){

        return 0;
    }

    while(fread(&compra, sizeof(Compras), 1, CArchivo) == 1){

        contador++;
    }

    fclose(CArchivo);

    return contador;
}

int ArchivoCompras::Buscar(int id){

    int posicion = 0;

    Compras compra;

    FILE *CArchivo;

    CArchivo = fopen(nombreArchivo, "rb");

    if(CArchivo == nullptr){

        cout<<"No se pudo abrir el archivo";
        return 0;
    }

    while(fread(&compra, sizeof(Compras), 1, CArchivo) == 1){

        if(compra.get_idCompra() == id){

            fclose(CArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(CArchivo);

    return -1;

}

void ArchivoCompras::Listar(){

    Compras compra;
    ArchivoCompras archivo;

    cout<<"COMPRAS"<<endl<<"======================="<<endl;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){

        compra = archivo.Leer(i);
        compra.mostrar();
        cout<<endl<<endl;
    }
}

