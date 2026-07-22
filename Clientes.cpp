#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include "Clientes.h"
#include "ArchivoClientes.h"

using namespace std;

void Clientes::cargar(){

    cin.ignore();

    char nombre[40];
    bool miembro;
    int dni;
    char telefono[20];
    char mail[60];

    ArchivoClientes archivo;

    set_idCliente(archivo.Contar());

    do{
        cout<<"Alta de Clientes - Nombre"<<endl;
        cout<<"========================"<<endl;
        cout<<"Ingrese el nombre del Cliente: ";
        cin.getline(nombre,40);

        if(strlen(nombre)==0){
            cout<<"No puede quedar vacío."<<endl;
        }

    }while(strlen(nombre)==0);

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
    cin.ignore();
    cin.getline(telefono,20);

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

    cout<<left;
    cout<<setw(6)<<idCliente;
    cout<<setw(35)<<nombreCliente;
    cout<<setw(12)<<dniCliente;
    cout<<setw(20)<<telefonoCliente;
    cout<<setw(40)<<mailCliente;

    if(miembroCliente == true){

        cout<<setw(8)<<"   SI";
    }
    else if(miembroCliente == false){

        cout<<setw(8)<<"   NO";
    }

    if(estadoCliente == true){

        cout<<setw(8)<<" ACTIVO";
    }
    else if(estadoCliente == false){

        cout<<setw(8)<<" INACTIVO";
    }

    cout<<endl;


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

void Clientes::set_estadoCliente(bool estadoIngresado){

    estadoCliente = estadoIngresado;
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

bool Clientes::get_estadoCliente(){

    return estadoCliente;
}

void Clientes::darAlta(){

    estadoCliente = true;
}

void Clientes::darBaja(){

    estadoCliente = false;
}
