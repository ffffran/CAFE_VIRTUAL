#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#include "ArchivoDetalleCompras.h"

ArchivoDetalleCompras::ArchivoDetalleCompras(){

    strcpy(nombreArchivo, "DetalleCompras.dat");
}

bool ArchivoDetalleCompras::guardar(DetalleCompras detalleCompra){

    FILE *DCArchivo;

    DCArchivo = fopen(nombreArchivo, "ab");

    if(DCArchivo == nullptr){

        cout<<"No se pudo abrir el archivo.";
        return false;
    }

    bool escribio = fwrite(&detalleCompra, sizeof(DetalleCompras), 1, DCArchivo);

    fclose(DCArchivo);

    return escribio;
}

DetalleCompras ArchivoDetalleCompras::Leer(int posicion){

    DetalleCompras detalleCompra;

    FILE *DCArchivo;

    DCArchivo = fopen(nombreArchivo, "rb");

    if(DCArchivo == nullptr){

        cout<<"No se pudo abrir el archivo.";
        return detalleCompra;
    }

    fseek(DCArchivo, posicion * sizeof(DetalleCompras), SEEK_SET);

    fread(&detalleCompra, sizeof(DetalleCompras), 1, DCArchivo);

    fclose(DCArchivo);

    return detalleCompra;
}

int ArchivoDetalleCompras::contarRegistros(){

    int contador = 0;

    FILE *DCArchivo;

    DetalleCompras detalleCompra;

    DCArchivo = fopen (nombreArchivo, "rb");

    if (DCArchivo == nullptr){

        return 0;
    }

    while(fread(&detalleCompra, sizeof(DetalleCompras), 1, DCArchivo) == 1){

        contador++;
    }

    fclose(DCArchivo);

    return contador;
}

int ArchivoDetalleCompras::Buscar(int id){

    DetalleCompras detalleCompra;

    FILE *DCArchivo;

    DCArchivo = fopen (nombreArchivo, "rb");

    int posicion = 0;

    while(fread(&detalleCompra, sizeof(DetalleCompras), 1, DCArchivo) == 1){

        if(detalleCompra.get_idCompraDetalle() == id){

            fclose(DCArchivo);
            return posicion;
        }

        posicion++;
    }

    fclose(DCArchivo);

    return -1;
}

void ArchivoDetalleCompras::Listar(){

    DetalleCompras detalleCompra;
    ArchivoDetalleCompras archivo;

    cout<<"DETALLE COMPRAS"<<endl<<"======================="<<endl;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){

        detalleCompra = archivo.Leer(i);
        detalleCompra.mostrar();
        cout<<endl;
    }
}

void ArchivoDetalleCompras::Mostrar1(int id){

    DetalleCompras detalle;

    int cantidad = contarRegistros();

    bool encontrado = false;

    for(int i = 0; i < cantidad; i++){

        detalle = Leer(i);

        if(detalle.get_idCompraDetalle() == id){

            detalle.mostrar();
            cout << endl;
            encontrado = true;

        }
    }

    if(!encontrado){

        cout<<"El id buscado no pertenece a ninguna compra."<<endl;
    }

    system("pause");
}


