#include <iostream>
#include <cstring>
#include <cctype>
#include "Clientes.h"
#include "ArchivoClientes.h"

using namespace std;

void Clientes::cargar(){

    int id;
    char nombre[40];
    bool miembro;
    int dni;
    char telefono[20];
    char mail[60];

    cout<<"Alta de Clientes - IDs"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el ID del Cliente: ";
    cin>> id;

    ArchivoClientes archivo;

    if(archivo.Buscar(id) != -1){

        cout<<"El ID ingresado ya existe, por favor ingrese otro."<<endl;
        system("pause");
    }
    else{

        set_idCliente(id);
    }

    system("cls");

    cout<<"Alta de Clientes - Nombre"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el nombre del Cliente: ";
    cin>> nombre;

    set_nombreCliente(nombre);

    system("cls");

    cout<<"Alta de Clientes - Club CAFE VIRTUAL"<<endl;
    cout<<"========================"<<endl;
    cout<<"1 - SI | 0 - NO"<<endl;
    cout<<"Quiere ser miembro del club?: ";
    cin>> miembro;

    if(miembro){
        set_miembroCliente(miembro);
    }
    else if(!miembro){

        set_miembroCliente(miembro);
    }

    system("cls");

    cout<<"Alta de Clientes - DNI"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el DNI del Cliente: ";
    cin>> dni;

    set_dniCliente(dni);

    system("cls");

    cout<<"Alta de Clientes - Telefono"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el telefono del Cliente: ";
    cin>> telefono;

    set_telefonoCliente(telefono);

    system("cls");

    cout<<"Alta de Clientes - Mail"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el mail del Cliente: ";
    cin>> mail;

    set_mailCliente(mail);

    system("cls");

}

void Clientes::mostrar(){

    cout<<"ID:"<<idCliente<<endl;
    cout<<"NOMBRE: "<<nombreCliente<<endl;
    cout<<"DNI: "<<dniCliente<<endl;
    cout<<"TELEFONO: "<<telefonoCliente<<endl;
    cout<<"MAIL: "<<mailCliente<<endl;

    if(miembroCliente){
        cout<<"MIEMBRO: SI"<<endl;
    }
    else{

        cout<<"MIEMBRO: NO"<<endl;
    }
}

void Clientes::set_idCliente(int idIngresado){

    if(idIngresado >= 0){

        idCliente = idIngresado;
    }
}

void Clientes::set_nombreCliente(char nombreIngresado[]){

    if(strlen(nombreIngresado) <= 40 && strlen(nombreIngresado) > 1){

        strcpy(nombreCliente, nombreIngresado);
    }

    for(int i = 0; nombreCliente[i] != '\0'; i ++){ ///ESTE FOR PUEDE ESTAR DE MAS

        nombreCliente[i] = toupper(nombreCliente[i]);
    }
}

void Clientes::set_miembroCliente(bool miembroIngresado){

    miembroCliente = miembroIngresado;
}

void Clientes::set_dniCliente(int dniIngresado){

    if(dniIngresado >= 1000000 && dniIngresado <= 99999999){

        dniCliente = dniIngresado;
    }
    else{

        cout<<"Ingrese un DNI válido - 7 u 8 numeros"<<endl;
        system("pause");
    }
}

void Clientes::set_telefonoCliente(char telefonoIngresado[]){

    if(strlen(telefonoIngresado) <= 20){

        strcpy(telefonoCliente, telefonoIngresado);
    }
}

void Clientes::set_mailCliente(char mailIngresado[]){

    if(strlen(mailIngresado) <= 60){

        strcpy(mailCliente, mailIngresado);
    }

    for(int i = 0; mailCliente[i] != '\0'; i++){

        mailCliente[i] = tolower(mailCliente[i]);
    }
}

int Clientes::get_idCliente(){

    return idCliente;
}

char* Clientes::get_nombreCliente(){

    return nombreCliente;
}

bool Clientes::get_miembroCliente(){

    return miembroCliente;
}

int Clientes::get_dni(){

    return dniCliente;
}

char* Clientes::get_telefonoCliente(){

    return telefonoCliente;
}

char* Clientes::get_mailCliente(){

    return mailCliente;
}



