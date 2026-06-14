#include <iostream>
#include <cstring>
#include <cctype>
#include "Proveedores.h"
#include "ArchivoProveedores.h"
using namespace std;

void Proveedores::cargar(){

    char rubroEmpresa[55];
    char nombreEmpresa[60];
    char paisEmpresa[40];
    char telefonoEmpresa[20];
    char locacionEmpresa[40];

    ArchivoProveedores archivo;

    set_idProveedor(archivo.contarRegistros());

    cout<<"Alta de Proveedores - Nombre"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el nombre del Proveedor: ";
    cin>> nombreEmpresa;

    set_nombreEmpresa(nombreEmpresa);

    system("cls");

    cout<<"Alta de Proveedores - Rubro"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el nombre del Rubro: ";
    cin>> rubroEmpresa;

    set_rubroEmpresa(rubroEmpresa);

    system("cls");

    cout<<"Alta de Proveedores - Pais"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el Pais del Proveedor: ";
    cin>> paisEmpresa;

    set_paisEmpresa(paisEmpresa);

    system("cls");

    cout<<"Alta de Proveedores - Localidad"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese la Localidad del Proveedor: ";
    cin>> locacionEmpresa;

    set_locacionEmpresa(locacionEmpresa);

    system("cls");

    cout<<"Alta de Proveedores - Telefono"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el telefono del Proveedor: ";
    cin>> telefonoEmpresa;

    set_telefonoEmpresa(telefonoEmpresa);

    system("cls");
}

void Proveedores::mostrar(){

    cout<<"ID: "<<idProveedor<<endl;
    cout<<"NOMBRE: "<<nombreEmpresa<<endl;
    cout<<"RUBRO: "<<rubroEmpresa<<endl;
    cout<<"PAIS: "<<paisEmpresa<<endl;
    cout<<"LOCALIDAD: "<<locacionEmpresa<<endl;
    cout<<"TELEFONO: "<<telefonoEmpresa<<endl;
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


