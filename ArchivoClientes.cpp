#include <cstring>
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
#include "ArchivoClientes.h"

ArchivoClientes::ArchivoClientes(){

    strcpy(nombreArchivo, "Clientes.dat");
}

bool ArchivoClientes::guardar(Clientes cliente){

    FILE *CArchivo;

    CArchivo = fopen(nombreArchivo, "ab");

    if(CArchivo == nullptr){

        cout<<"No se pudo guardar el registro";
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

int ArchivoClientes::Contar(){

    FILE *CArchivo;

    CArchivo = fopen(nombreArchivo, "rb");

    int cantidad;

    if(CArchivo == nullptr){

        cout<<"El archivo es nuevo";
        return 0;
    }

    fseek(CArchivo, 0, SEEK_END);

    cantidad = ftell(CArchivo) / sizeof(Clientes);

    fclose(CArchivo);

    return cantidad;
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

    Clientes cliente;
    ArchivoClientes carchivo;

    cout<<left;
    cout<<setw(6)<<"ID";
    cout<<setw(35)<<"NOMBRE";
    cout<<setw(12)<<"DNI";
    cout<<setw(20)<<"TELEFONO";
    cout<<setw(40)<<"MAIL";
    cout<<setw(8)<<"MIEMBRO";
    cout<<endl;

    cout<<string(125, '.')<<endl;

    for(int i = 0; i < carchivo.Contar(); i++){

        cliente = carchivo.Leer(i);

        if(cliente.get_estadoCliente()){

            cliente.mostrar();
        }
    }

    system("pause");

    return 0;
}





