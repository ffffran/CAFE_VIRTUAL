#include <iostream>
#include <cstring>
#include "FUNCIONES.h"
#include "Productos.h"
#include "ArchivoProductos.h"

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

///            menuNuevaCompra();
            break;

        case 2:

            menuAbm();
            break;

        case 3:

///            menuReportes();
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

void menuAbm(){

    int Opcion;
    int Crear;
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

            altaProducto();
            break;

        case 2:

            bajaProducto();
            break;

        case 3:


            break;

        case 4:

            mostrarProductos();
            break;

        case 0:

            return;
        }
    }
}

void altaProducto(){

    Productos producto;
    ArchivoProductos archivo;
    int opcion;

    cout<<"1 - SI | 2 - NO"<<endl;
    cout<<"Quiere dar de alta un producto ya existente? ";
    cin>> opcion;

    if(opcion == 2){

        producto.cargar();
        producto.darAlta();

        if(archivo.guardar(producto)){

            cout<<"El producto se guardo correctamente! :)"<<endl;
        }
        else{

            cout<<"Error al guardar producto. :("<<endl;
        }

        system("pause");
    }
    else if (opcion == 1){

        int id;
        int posicion;

        cout<<"Ingrese el ID del producto que quiere dar de baja: ";
        cin>>id;

        posicion = archivo.Buscar(id);

        if(posicion == -1){

            cout<<"Producto NO encontrado."<<endl;
            system("pause");
            return;
        }

        producto = archivo.Leer(posicion);

        producto.darAlta();

        archivo.Modificar(producto, posicion);


        if(archivo.Leer(posicion).get_estadoProducto() == true){

            cout<<"El producto se dio de alta de nuevo correctamente! :)"<<endl;
        }
        else{

            cout<<"Error al dar de alta de nuevo el producto. :("<<endl;
        }

        system("pause");
    }

}

void bajaProducto(){

    Productos producto;
    ArchivoProductos archivo;

    int id;
    int posicion;

    cout<<"Ingrese el ID del producto que quiere dar de baja: ";
    cin>>id;

    posicion = archivo.Buscar(id);

    if(posicion == -1){

        cout<<"Producto NO encontrado."<<endl;
        system("pause");
        return;
    }

    producto = archivo.Leer(posicion);

    producto.darBaja();

    archivo.Modificar(producto, posicion);


    if(archivo.Leer(posicion).get_estadoProducto() == false){

        cout<<"El producto se dio de baja correctamente! :)"<<endl;
    }
    else{

        cout<<"Error al dar de baja el producto. :("<<endl;
    }

    system("pause");
}

void mostrarProductos(){

    Productos producto;
    ArchivoProductos archivo;

    int opcion;

    cout<<"MENU ABML"<<endl;
    cout<<"========================"<<endl;
    cout<<"1 - Activos";
    cout<<endl;
    cout<<"2 - Inactivos";
    cout<<endl;
    cout<<"3 - Todos";
    cout<<endl;
    cout<<"0 - Salir"<<endl;
    cout<<"========================"<<endl;
    cout<< "INGRESE OPCION: ";
    cin>>opcion;

    int cantidadTotal = archivo.Listar();

    for(int i = 0; i < cantidadTotal; i++){

        producto = archivo.Leer(i);

        if(opcion == 1 && producto.get_estadoProducto()){

            producto.mostrar();
        }
        else if(opcion == 2 && !producto.get_estadoProducto()){

            producto.mostrar();
        }
        else if(opcion == 3){

            producto.mostrar();
        }
    }

    system("pause");
}


/**
void mostrar productos original, puede usarse para reportes

    Productos producto;
    ArchivoProductos archivo;

    int cantidadRegistros = archivo.contarRegistros(false);

    for(int i = 0; i < cantidadRegistros; i++){

        producto = archivo.Leer(i);
        producto.mostrar();
    }


    system("pause");
*/
