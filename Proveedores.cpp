#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include "Proveedores.h"
#include "ArchivoProveedores.h"
using namespace std;

void Proveedores::cargar(){
    cin.ignore();
    char rubroEmpresa[55];
    char nombreEmpresa[60];
    char paisEmpresa[40];
    char telefonoEmpresa[20];
    char locacionEmpresa[40];

    ArchivoProveedores archivo;

    set_idProveedor(archivo.Contar());

    cout<<"Alta de Proveedores - Nombre"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el nombre del Proveedor: ";
    cin.getline(nombreEmpresa,60);

    set_nombreEmpresa(nombreEmpresa);

    system("cls");

    cout<<"Alta de Proveedores - Rubro"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el nombre del Rubro: ";
    cin.getline(rubroEmpresa,55);

    set_rubroEmpresa(rubroEmpresa);

    system("cls");

    cout<<"Alta de Proveedores - Pais"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el Pais del Proveedor: ";
    cin.getline(paisEmpresa,40);

    set_paisEmpresa(paisEmpresa);

    system("cls");

    cout<<"Alta de Proveedores - Localidad"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese la Localidad del Proveedor: ";
    cin.getline(locacionEmpresa,40);

    set_locacionEmpresa(locacionEmpresa);

    system("cls");

    cout<<"Alta de Proveedores - Telefono"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el telefono del Proveedor: ";
    cin.getline(telefonoEmpresa,20);

    set_telefonoEmpresa(telefonoEmpresa);

    system("cls");
}

void Proveedores::mostrar(){

    cout<<left;
    cout<<setw(6)<<idProveedor;
    cout<<setw(40)<<nombreEmpresa;
    cout<<setw(30)<<rubroEmpresa;
    cout<<setw(30)<<paisEmpresa;
    cout<<setw(30)<<locacionEmpresa;
    cout<<setw(20)<<telefonoEmpresa;

    if(estadoProveedor == true){

        cout<<setw(8)<<" ACTIVO";
    }
    else if(estadoProveedor == false){

        cout<<setw(8)<<" INACTIVO";
    }

    cout<<endl;
}

void Proveedores::set_idProveedor(int id){

    if(id >= 0){

        idProveedor = id;
    }
}

void Proveedores::set_rubroEmpresa(char rubroIngresado[]){

    if(strlen(rubroIngresado) <= 55 && strlen(rubroIngresado) > 1){

        strcpy(rubroEmpresa, rubroIngresado);
    }

    for(int i = 0; rubroEmpresa[i] != '\0'; i ++){ ///ESTE FOR PUEDE ESTAR DE MAS

        rubroEmpresa[i] = toupper(rubroEmpresa[i]);
    }
}

void Proveedores::set_nombreEmpresa(char nombreIngresado[]){

    if(strlen(nombreIngresado) <= 60 && strlen(nombreIngresado) > 1){

        strcpy(nombreEmpresa, nombreIngresado);
    }

    for(int i = 0; nombreEmpresa[i] != '\0'; i ++){ ///ESTE FOR PUEDE ESTAR DE MAS

        nombreEmpresa[i] = toupper(nombreEmpresa[i]);
    }

}

void Proveedores::set_paisEmpresa(char paisIngresado[]){

    if(strlen(paisIngresado) <= 40 && strlen(paisIngresado) > 1){

        strcpy(paisEmpresa, paisIngresado);
    }

    for(int i = 0; paisEmpresa[i] != '\0'; i ++){ ///ESTE FOR PUEDE ESTAR DE MAS

        paisEmpresa[i] = toupper(paisEmpresa[i]);
    }
}

void Proveedores::set_telefonoEmpresa(char telefonoIngresado[]){

    if(strlen(telefonoIngresado) <= 20){

        strcpy(telefonoEmpresa, telefonoIngresado);
    }
}

void Proveedores::set_locacionEmpresa(char locacionIngresada[]){

    if(strlen(locacionIngresada) <= 40 && strlen(locacionIngresada) > 1){

        strcpy(locacionEmpresa, locacionIngresada);
    }

    for(int i = 0; locacionEmpresa[i] != '\0'; i ++){ ///ESTE FOR PUEDE ESTAR DE MAS

        locacionEmpresa[i] = toupper(locacionEmpresa[i]);
    }
}

void Proveedores::set_estadoProveedor(bool estadoIngresado){

    estadoProveedor = estadoIngresado;
}

int Proveedores::get_idProveedor(){

    return idProveedor;
}

char* Proveedores::get_rubroEmpresa(){

    return rubroEmpresa;
}

char* Proveedores::get_nombreEmpresa(){

    return nombreEmpresa;
}

char* Proveedores::get_paisEmpresa(){

    return paisEmpresa;
}

char* Proveedores::get_telefonoEmpresa(){

    return telefonoEmpresa;
}

char* Proveedores::get_locacionEmpresa(){

    return locacionEmpresa;
}

bool Proveedores::get_estadoProveedor(){

    return estadoProveedor;
}

void Proveedores::darAlta(){

    estadoProveedor = true;
}

void Proveedores::darBaja(){

    estadoProveedor = false;
}
