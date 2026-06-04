#include <iostream>
#include <cstring>
#include "FUNCIONES.h"
#include "Productos.h"
#include "ArchivoProductos.h"
#include "Clientes.h"
#include "ArchivoClientes.h"

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
        cout<<"2 - ABM - Membresia"<<endl;
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
    int OpcionAlta;
    int OpcionBaja;
    int OpcionModificar;
    int OpcionListado;

    while(true){

        system("cls");

        cout<<"MENU ABML"<<endl;
        cout<<"========================"<<endl;
        cout<<"1 - Alta";
        cout<<endl;
        cout<<"2 - Baja Productos";
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

            cout<<"MENU ALTA"<<endl;
            cout<<"========================"<<endl;
            cout<<"1 - Alta Producto";
            cout<<endl;
            cout<<"2 - Alta Cliente";
            cout<<endl;
            cout<<"0 - Salir"<<endl;
            cout<<"========================"<<endl;
            cout<< "INGRESE OPCION: ";
            cin>>OpcionAlta;

            system("cls");

            switch(OpcionAlta){

            case 1:

                altaProducto();
                break;

            case 2:

                altaCliente();
                break;

            case 0:

                break;
            }

            break;

        case 2:

            bajaProducto();
            break;

        case 3:

            cout<<"MENU MODIFICACIONES"<<endl;
            cout<<"========================"<<endl;
            cout<<"1 - Modificar Producto";
            cout<<endl;
            cout<<"2 - Modificar Cliente";
            cout<<endl;
            cout<<"0 - Salir"<<endl;
            cout<<"========================"<<endl;
            cout<< "INGRESE OPCION: ";
            cin>>OpcionModificar;

            switch(OpcionModificar){

            case 1:

                modificarProducto();
                break;

            case 2:

                modificarCliente();
                break;

            case 0:

                break;
            }

            ///modificarProveedor();  DESARROLLAR
            break;

        case 4:

            cout<<"MENU LISTADO"<<endl;
            cout<<"========================"<<endl;
            cout<<"1 - Listar Productos";
            cout<<endl;
            cout<<"2 - Listar Clientes";
            cout<<endl;
            cout<<"0 - Salir"<<endl;
            cout<<"========================"<<endl;
            cout<< "INGRESE OPCION: ";
            cin>>OpcionListado;

            system("cls");

            switch(OpcionListado){

            case 1:

                mostrarProductos();
                break;

            case 2:

                mostrarClientes();
                break;

            case 0:

                break;
            }

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

        cout<<"Ingrese el ID del producto que quiere dar de alta: ";
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

    if(posicion <= 0){

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

    int activos = archivo.contarRegistros(true);
    int inactivos = archivo.contarRegistros(false);

    if(activos == 0){

        cout<<"No hay productos Acitvos"<<endl;
        system("pause");
        return;
    }

    if(inactivos == 0){

        cout<<"No hay productos Inactivos"<<endl;
        system("pause");
        return;
    }

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

void modificarProducto(){

    Productos producto;
    ArchivoProductos archivo;

    int id;
    int posicion;

    cout<<"Ingrese el ID del producto que quiere modificar: ";
    cin>>id;

    posicion = archivo.Buscar(id);

    if(posicion < 0){

        cout<<"Producto NO encontrado."<<endl;
        system("pause");
        return;
    }

    system("cls");

    producto = archivo.Leer(posicion);

    int opcion;

    cout<<"Que campo quiere cambiar?"<<endl;
    cout<<"==========================="<<endl;
    cout<<"1 - Nombre"<<endl;
    cout<<"2 - Precio"<<endl;
    cout<<"3 - Stock Minimo"<<endl;
    cout<<"0 - Salir"<<endl;
    cout<<"==========================="<<endl;
    cin>>opcion;

    switch(opcion){

    case 1:

        char nombreNuevo[50];

        cout<<"Ingrese su nuevo nombre: ";
        cin>>nombreNuevo;

        producto.set_nombreProducto(nombreNuevo);
        break;

    case 2:

        float precioNuevo;

        cout<<"Ingrese su nuevo precio: $";
        cin>>precioNuevo;

        producto.set_precioProducto(precioNuevo);
        break;

    case 3:

        int stockMinimoNuevo;

        cout<<"Ingrese su nuevo Stock Minimo: ";
        cin>>stockMinimoNuevo;

        producto.set_stockMinimo(stockMinimoNuevo);
        break;

    case 0:

        return;
    }

    archivo.Modificar(producto, posicion);
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

void altaCliente(){

    Clientes cliente;
    ArchivoClientes archivo;

    cliente.cargar();

    if(archivo.guardar(cliente)){

        cout<<"El cliente se guardo correctamente! :)"<<endl;
    }
    else{

        cout<<"Error al guardar cliente. :("<<endl;
    }

    system("pause");
}

void mostrarClientes(){

    Clientes cliente;
    ArchivoClientes archivo;

    int opcion;

    cout<<"MENU ABML"<<endl;
    cout<<"========================"<<endl;
    cout<<"1 - Miembros";
    cout<<endl;
    cout<<"2 - No Miembros";
    cout<<endl;
    cout<<"3 - Todos";
    cout<<endl;
    cout<<"0 - Salir"<<endl;
    cout<<"========================"<<endl;
    cout<< "INGRESE OPCION: ";
    cin>>opcion;

    int cantidadTotal = archivo.Listar();

    int activos = archivo.contarRegistros(true);
    int inactivos = archivo.contarRegistros(false);

    if(activos == 0){

        cout<<"Ningun cliente es miembro"<<endl;
        system("pause");
        return;
    }

    if(inactivos == 0){

        cout<<"Todos los clientes son miembros"<<endl;
        system("pause");
        return;
    }

    for(int i = 0; i < cantidadTotal; i++){

        cliente = archivo.Leer(i);

        if(opcion == 1 && cliente.get_miembroCliente()){

            cliente.mostrar();
        }
        else if(opcion == 2 && !cliente.get_miembroCliente()){

            cliente.mostrar();
        }
        else if(opcion == 3){

            cliente.mostrar();
            cout<<endl;
        }

    }

    system("pause");
}

void modificarCliente(){

    Clientes cliente;
    ArchivoClientes archivo;

    int id;
    int posicion;

    cout<<"Ingrese el ID de cliente que quiere modificar: ";
    cin>>id;

    posicion = archivo.Buscar(id);

    if(posicion < 0){

        cout<<"Cliente NO encontrado."<<endl;
        system("pause");
        return;
    }

    system("cls");
    cliente = archivo.Leer(posicion);

    int opcion;

    cout<<"Que campo quiere cambiar?"<<endl;
    cout<<"==========================="<<endl;
    cout<<"1 - Nombre"<<endl;
    cout<<"2 - DNI"<<endl;
    cout<<"3 - Telefono"<<endl;
    cout<<"4 - Mail"<<endl;
    cout<<"0 - Salir"<<endl;
    cout<<"==========================="<<endl;
    cin>>opcion;

    switch(opcion){

    case 1:

        char nombreNuevo[40];

        cout<<"Ingrese su nuevo nombre: ";
        cin>>nombreNuevo;

        cliente.set_nombreCliente(nombreNuevo);
        break;

    case 2:

        int dniNuevo;

        cout<<"Ingrese su nuevo dni: ";
        cin>>dniNuevo;

        cliente.set_dniCliente(dniNuevo);
        break;

    case 3:

        char telefonoNuevo[20];

        cout<<"Ingrese su nuevo telefono: ";
        cin>>telefonoNuevo;

        cliente.set_telefonoCliente(telefonoNuevo);
        break;

    case 4:

        char mailNuevo[60];

        cout<<"Ingrese su nuevo mail: ";
        cin>>mailNuevo;

        cliente.set_mailCliente(mailNuevo);
        break;

    case 0:

        return;
    }

    archivo.Modificar(cliente, posicion);
}
