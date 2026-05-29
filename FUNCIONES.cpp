#include <iostream>
#include <cstring>
#include "FUNCIONES.h"

using namespace std;


void menuPrincipal(){

    int opcion;

    while(true){

        system("cls");

        cout<<"BIENVENIDO A CAFE VIRTUAL"<<endl;
        cout<< endl;
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"========================"<<endl;
        cout<<"1 - Nueva Compra"<<endl;
        cout<<"2 - ABM Club CV"<<endl;
        cout<<"3 - Reportes"<<endl;
        cout<<"0 - Salir"<<endl;
        cout<<"========================"<<endl;
        cout<< "INGRESE OPCION: ";
        cin>>opcion;

        system("cls");

        switch(opcion){

        case 1:

            menuNuevaCompra();
            break;

        case 2:

//            menuAbml();
            break;

        case 3:

//            menuReportes();
            break;

        case 0:

            break;
        }
    }
}

void menuNuevaCompra(){

    int Opcion;
    int IdCliente;
    int CategoriaProducto;
    int MetodoPago;

    while(true){

        system("cls");

        cout<<"MENU NUEVA COMPRA"<<endl;
        cout<<"========================"<<endl;
        cout<<"1 - Ingrese ID del cliente";
        cout<<endl;
        cout<<"2 - Elija CategoriaProdcuto";
        cout<<endl;
        cout<<"3 - Elija Metodo de Pago";
        cout<<endl;
        cout<<"0 - Salir"<<endl;
        cout<<"========================"<<endl;
        cout<< "INGRESE OPCION: ";
        cin>>Opcion;

        system("cls");

        switch(Opcion){

        case 1:
            cout<<"IDs DE CLIENTES"<<endl;
            cout<<"========================"<<endl;
            cout<<"(1 para Ventas Generales)"<<endl;
            cout<<"Ingrese ID del clientes:";
            cin>>IdCliente;

            break;

        case 2:

            cout<<"CATEGORIAS DE PRODUCTOS"<<endl;
            cout<<"========================"<<endl;
            cout<<"1-Cafeteria"<<endl;
            cout<<"2-Pasteleria"<<endl;
            cout<<"3-Bebidas"<<endl;
            cout<<"========================"<<endl;
            cout<<"Seleccione su meteodo de pago: ";
            cin>>CategoriaProducto;

            break;

        case 3:

            cout<<"METODOS DE PAGO"<<endl;
            cout<<"========================"<<endl;
            cout<<"1-Efectivo"<<endl;
            cout<<"2-Debito"<<endl;
            cout<<"3-Credito"<<endl;
            cout<<"========================"<<endl;
            cout<<"Seleccione su meteodo de pago: ";
            cin>>MetodoPago;

            break;

        case 0:

            return;
        }
    }
}

void menuAbml(){

    int Opcion;
    int Alta;
    int Baja;
    int Modificacion;
    int Listado;

    while(true){

        system("cls");

        cout<<"MENU ABML"<<endl;
        cout<<"========================"<<endl;
        cout<<"1 - Alta";
        cout<<endl;
        cout<<"2 - Baja";
        cout<<endl;
        cout<<"3 - Modificacion";
        cout<<endl;
        cout<<"4 - Listar";
        cout<<endl;
        cout<<"0 - Salir"<<endl;
        cout<<"========================"<<endl;
        cout<< "INGRESE OPCION: ";
        cin>>Opcion;

        system("cls");

        switch(Opcion){

        case 1:
            cout<<"IDs DE CLIENTES"<<endl;
            cout<<"========================"<<endl;
            cout<<"(1 para Ventas Generales)"<<endl;
            cout<<"Ingrese ID del clientes:";
//            cin>>IdCliente;

            break;

        case 2:

            cout<<"CATEGORIAS DE PRODUCTOS"<<endl;
            cout<<"========================"<<endl;
            cout<<"1-Cafeteria"<<endl;
            cout<<"2-Pasteleria"<<endl;
            cout<<"3-Bebidas"<<endl;
            cout<<"========================"<<endl;
            cout<<"Seleccione su meteodo de pago: ";
//            cin>>CategoriaProducto;

            break;

        case 3:

            cout<<"METODOS DE PAGO"<<endl;
            cout<<"========================"<<endl;
            cout<<"1-Efectivo"<<endl;
            cout<<"2-Debito"<<endl;
            cout<<"3-Credito"<<endl;
            cout<<"========================"<<endl;
            cout<<"Seleccione su meteodo de pago: ";
//            cin>>MetodoPago;

            break;

        case 0:

            return;
        }
    }
}
