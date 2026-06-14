#include <iostream>
#include <cstring>
#include "FUNCIONES.h"
#include "Productos.h"
#include "ArchivoProductos.h"
#include "Clientes.h"
#include "ArchivoClientes.h"
#include "Proveedores.h"
#include "ArchivoProveedores.h"

#include "Ventas.h"
#include "ArchivoVentas.h"
#include "DetalleVentas.h"
#include "ArchivoDetalleVentas.h"

#include "Compras.h"
#include "ArchivoCompras.h"
#include "DetalleCompras.h"
#include "ArchivoDetalleCompras.h"

using namespace std;


void menuPrincipal(){

    int opcion;

    while(true){

        system("cls");

        cout<<"BIENVENIDO A CAFE VIRTUAL"<<endl;
        cout<< endl;
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"========================"<<endl;
        cout<<"1 - Nueva Venta"<<endl;
        cout<<"2 - Nueva Compra"<<endl;
        cout<<"3 - ABM - Membresia"<<endl;
        cout<<"4 - Reportes"<<endl;
        cout<<"0 - Salir"<<endl;
        cout<<"========================"<<endl;
        cout<< "INGRESE OPCION: ";
        cin>>opcion;

        system("cls");

        switch(opcion){

        case 1:

            menuVenta();
            break;

        case 2:

            menuCompra();
            break;

        case 3:

            menuAbm();
            break;

        case 4:

            menuReportes();
            break;

        case 0:

            return;
        }
    }
}

void menuVenta(){

    ///===================================///
    /// CONFIGURACION INICIAL DE LA VENTA ///
    ///===================================///

    DetalleVentas detalleventa;     /// ESTO CONCEPTUALMENTE DEBERIA ESTAR EN EL WHILE CON CADA VUELTA.
    ArchivoDetalleVentas dvarchivo; /// POR AHORA LO VAMOS A DEJAR ACÁ PORQUE ESTÁ TODO ACOMODADO ASÍ. PERO SE PODRÍA MEJORAR CAMBIANDO ESO.

    Ventas venta;
    ArchivoVentas varchivo;

    Clientes cliente;
    ArchivoClientes carchivo;

    Productos producto;
    ArchivoProductos parchivo;

    venta.set_idVenta(varchivo.contarRegistros() + 1);

    detalleventa.set_idVentaDetalle(venta.get_idVenta());

    ///=============================///
    /// DATOS GENERALES DE LA VENTA ///
    ///=============================///

    int cantidadClientes = carchivo.Listar();
    int IdClienteIngresadoVenta;
    int IdProductoIngresadoVenta;
    int UnidadesProductoElegidoVenta;
    int MetodoPagoElegidoVenta;
    float TotalFinalVenta = 0;

    ///============================///
    /// ASOCIAR CLIENTE A LA VENTA ///
    ///============================///

    cout<<"0 Para Venta General | ID Cliente Para Asociar Su Compra"<<endl;
    cout<<"ID: ";
    cin>>IdClienteIngresadoVenta;
    cout<<endl;

    for(int i = 0; i < cantidadClientes; i++){

        cliente = carchivo.Leer(i);

        if(IdClienteIngresadoVenta == cliente.get_idCliente()){

            venta.set_idClienteVenta(IdClienteIngresadoVenta);
            cout<<"Venta asociada al cliente "<< cliente.get_nombreCliente()<<endl;
            system("pause");
            system("cls");
            break;
        }
        else if(i == cantidadClientes - 1){

            cout<<"El Cliente buscado no existe."<<endl;
            return;
        }
    }

    ///==========================================///
    /// GUARDADOS TEMPORALES                     ///
    /// SI LA VENTA SE CANCELA NO SE GUARDA NADA ///
    /// CON ESTO EVITAMOS REGISTROS SUELTOS      ///
    ///==========================================///

    bool finalizar = true;

    DetalleVentas detalles[100];  ///guarda temporalemnte los detalles, si la venta se llega a cancelar en algun punto, no impacta stock ni se genera venta ni detalle venta
    int cantidadDetalles = 0;

    int posicionesProductos[100]; /// esto es para el stock de los productos, misma idea que lo de arriba
    int cantidadesProductos[100]; /// esto a raiz de que se modifica/descuenta el stock antes de confirmar la venta
    int cantidadProductos = 0;

    ///========================///
    /// SELECCION DE PRODUCTOS ///
    ///========================///

    while(finalizar){

    ///=========================================///
    /// MOSTRAR PRODUCTOS DISPONIBLES (ACTIVOS) ///
    ///=========================================///

        system("cls");

        cout<<"MENU PRODUCTOS EN VENTA"<<endl;
        cout<<"=========================="<<endl;

        parchivo.ListarMas();
        cout<<endl<<endl;

        cout<<"0 - Para cancelar la venta."<<endl;
        cout<<"============================="<<endl;
        cout<<"Elija los productos que desea llevar (Cod. Art. / ID): ";
        cin>>IdProductoIngresadoVenta;

        ///============================///
        /// VALIDAR PRODUCTO INGRESADO ///
        ///============================///


        if(IdProductoIngresadoVenta == 0){

            cout<<"!!!VENTA CANCELADA!!!";
            system("pause");
            return;
        }

        int posicion = parchivo.Buscar(IdProductoIngresadoVenta);

        if(posicion == -1){

            cout<<"El producto deseado no existe.";
            system("pause");
            continue;
        }

        producto = parchivo.Leer(posicion);

        ///=============================///
        /// VALIDAR ESTADO DEL PRODUCTO ///
        ///=============================///

        if(!producto.get_estadoProducto()){

            cout<<"El producto seleccionado esta inactivo."<<endl;
            system("pause");
            continue;
        }

        detalleventa.set_idProductoDetalle(producto.get_idProducto());
        detalleventa.set_precioUnitarioDetalle(producto.get_precioProducto());

        bool cantidadValida = false;

        ///==================================///
        /// INGRESO Y VALIDACION DE CANTIDAD ///
        ///==================================///

        while(!cantidadValida){

            cout<<endl<<endl;
            cout<<"0 - Para cancelar la venta."<<endl;
            cout<<"============================="<<endl;
            cout<<"Cuantas unidades de "<<producto.get_nombreProducto()<<" desea llevar?"<<endl;
            cin>>UnidadesProductoElegidoVenta;

            if(UnidadesProductoElegidoVenta > producto.get_stockProducto()){

                cout<<"Ingrese una cantidad menor, no hay suficiente stock.";
                system("pause");
            }
            else{

                cantidadValida = true;
            }
        }

        if(UnidadesProductoElegidoVenta == 0){

            cout<<"!!!VENTA CANCELADA!!!";
            system("pause");
            return;
        }
        else{

            ///===================================///
            /// ALMACENAR STOCK TEMPORALMENTE///
            ///===================================///

            posicionesProductos[cantidadProductos] = posicion;
            cantidadesProductos[cantidadProductos] = UnidadesProductoElegidoVenta;

            cantidadProductos++;
        }

        ///==================================///
        /// GENERAR DETALLE Y ACUMULAR TOTAL ///
        ///==================================///

        detalleventa.set_cantidadUnidadesDetalle(UnidadesProductoElegidoVenta);
        detalleventa.set_subTotalDetalle(detalleventa.get_precioUnitarioDetalle(), detalleventa.get_cantidadUnidadesDetalle());

        TotalFinalVenta += producto.get_precioProducto()*UnidadesProductoElegidoVenta;

        system("pause");
        system("cls");

        cout<<"Desea agregar otro producto a su pedido?"<<endl;
        cout<<"1 - SI | 0 - NO"<<endl;
        cin>>finalizar;

        ///============================///
        /// ALMACENAR DETALLE TEMPORAL ///
        ///============================///

        detalles[cantidadDetalles] = detalleventa;
        cantidadDetalles++;
    }

    ///=====================///
    /// RESUMEN DE LA VENTA ///
    ///=====================///

    cout<<endl;
    cout<<"Su total es de "<< TotalFinalVenta<<endl;;
    system("pause");
    system("cls");

    ///===========================================///
    /// SELECCION Y VALIDACION DEL METODO DE PAGO ///
    ///===========================================///


    bool mp = false;

    while(!mp){

        cout<<"1: EFECTIVO | 2: DEBITO | 3: CREDITO"<<endl;
        cout<<"Seleccione su metodo de pago: ";
        cin>>MetodoPagoElegidoVenta;

        if(MetodoPagoElegidoVenta!= 1 && MetodoPagoElegidoVenta!= 2 && MetodoPagoElegidoVenta!= 3){

            cout<<"Ingrese un metodo de pago válido.";
            system("pause");
            system("cls");
        }
        else{

            mp = true;
        }
    }

    ///===========================///
    /// CONFIRMAR Y GUARDAR VENTA ///
    ///===========================///

    venta.set_metodoPagoVenta(MetodoPagoElegidoVenta);
    venta.set_totalVenta(TotalFinalVenta);

    varchivo.guardar(venta);

    ///==============================///
    /// GUARDAR DETALLES DE LA VENTA ///
    ///==============================///

    for(int i = 0; i < cantidadDetalles; i++){

        dvarchivo.guardar(detalles[i]);
    }

    ///===================================///
    /// ACTUALIZAR STOCK DE LOS PRODUCTOS ///
    ///===================================///

    for(int i = 0; i < cantidadProductos; i++){

        producto = parchivo.Leer(posicionesProductos[i]);
        producto.descontarStock(cantidadesProductos[i]);
        parchivo.Modificar(producto, posicionesProductos[i]);
    }

    system("pause");
    system("cls");

    ///=====================///
    /// FINALIZAR OPERACION ///
    ///=====================///

    cout<<"Su Venta fue procesada con Exito.";
    system("pause");
}

void menuCompra(){

    DetalleCompras detallecompra;
    ArchivoDetalleCompras dcarchivo;

    Compras compra;
    ArchivoCompras carchivo;

    Proveedores proveedor;
    ArchivoProveedores proarchivo;

    Productos producto;
    ArchivoProductos parchivo;

    compra.set_idCompra(carchivo.contarRegistros() + 1);

    detallecompra.set_idCompraDetalle(compra.get_idCompra());

    int cantidadProveedores = proarchivo.contarRegistros();
    int IdProveedorIngresadoCompra;
    int IdProductoIngresadoCompra;
    int UnidadesProductoElegidoCompra;
    float TotalFinalCompra = 0;

    ///============================///
    /// ASOCIAR CLIENTE A LA VENTA ///
    ///============================///

    cout<<"0 Para Compra General | ID Proveedor Para Asociar Su Compra"<<endl;
    cout<<"ID: ";
    cin>>IdProveedorIngresadoCompra;
    cout<<endl;

    for(int i = 0; i < cantidadProveedores; i++){

        proveedor = proarchivo.Leer(i);

        if(IdProveedorIngresadoCompra == proveedor.get_idProveedor()){

            compra.set_idProveedorCompra(IdProveedorIngresadoCompra);
            cout<<"Compra asociada al proveedor "<< proveedor.get_nombreEmpresa()<<endl;
            system("pause");
            system("cls");
            break;
        }
        else if(i == cantidadProveedores - 1){

            cout<<"El Proveedor buscado no existe."<<endl;
            return;
        }
    }

    ///==========================================///
    /// GUARDADOS TEMPORALES                     ///
    /// SI LA VENTA SE CANCELA NO SE GUARDA NADA ///
    /// CON ESTO EVITAMOS REGISTROS SUELTOS      ///
    ///==========================================///

    bool finalizar = true;

    DetalleCompras detalles[100];  ///guarda temporalemnte los detalles, si la compra se llega a cancelar en algun punto, no impacta stock ni se genera venta ni detalle venta
    int cantidadDetalles = 0;

    int posicionesProductos[100]; /// esto es para el stock de los productos, misma idea que lo de arriba
    int cantidadesProductos[100]; /// esto a raiz de que se modifica/descuenta el stock antes de confirmar la venta
    int cantidadProductos = 0;

    ///========================///
    /// SELECCION DE PRODUCTOS ///
    ///========================///

    while(finalizar){

    ///=========================================///
    /// MOSTRAR PRODUCTOS DISPONIBLES (ACTIVOS) ///
    ///=========================================///

        system("cls");

        cout<<"MENU PRODUCTOS PARA COMPRAR"<<endl;
        cout<<"=========================="<<endl;

        parchivo.ListarMas();
        cout<<endl<<endl;

        cout<<"0 - Para cancelar la venta."<<endl;
        cout<<"============================="<<endl;
        cout<<"Elija los productos que desea llevar (Cod. Art. / ID): ";
        cin>>IdProductoIngresadoCompra;

        ///============================///
        /// VALIDAR PRODUCTO INGRESADO ///
        ///============================///


        if(IdProductoIngresadoCompra == 0){

            cout<<"!!!VENTA CANCELADA!!!";
            system("pause");
            return;
        }

        int posicion = parchivo.Buscar(IdProductoIngresadoCompra);

        if(posicion == -1){

            cout<<"El producto deseado no existe.";
            system("pause");
            continue;
        }

        producto = parchivo.Leer(posicion);

        ///=============================///
        /// VALIDAR ESTADO DEL PRODUCTO ///
        ///=============================///

        if(!producto.get_estadoProducto()){

            cout<<"El producto seleccionado esta inactivo."<<endl;
            system("pause");
            continue;
        }

        detallecompra.set_idProductoDetalle(producto.get_idProducto());
        detallecompra.set_precioUnitarioDetalle(producto.get_precioProducto());

        bool cantidadValida = false;

        ///==================================///
        /// INGRESO Y VALIDACION DE CANTIDAD ///
        ///==================================///

        while(!cantidadValida){

            cout<<endl<<endl;
            cout<<"0 - Para cancelar la venta."<<endl;
            cout<<"============================="<<endl;
            cout<<"Cuantas unidades de "<<producto.get_nombreProducto()<<" desea llevar?"<<endl;
            cin>>UnidadesProductoElegidoCompra;

            if(UnidadesProductoElegidoCompra > producto.get_stockProducto()){

                cout<<"Ingrese una cantidad menor, no hay suficiente stock.";
                system("pause");
            }
            else{

                cantidadValida = true;
            }
        }

        if(UnidadesProductoElegidoCompra == 0){

            cout<<"!!!VENTA CANCELADA!!!";
            system("pause");
            return;
        }
        else{

            ///===================================///
            /// ALMACENAR STOCK TEMPORALMENTE///
            ///===================================///

            posicionesProductos[cantidadProductos] = posicion;
            cantidadesProductos[cantidadProductos] = UnidadesProductoElegidoCompra;

            cantidadProductos++;
        }

        ///==================================///
        /// GENERAR DETALLE Y ACUMULAR TOTAL ///
        ///==================================///

        detallecompra.set_cantidadUnidadesDetalle(UnidadesProductoElegidoCompra);
        detallecompra.set_subTotalDetalle(detallecompra.get_precioUnitarioDetalle(), detallecompra.get_cantidadUnidadesDetalle());

        TotalFinalCompra += producto.get_precioProducto()*UnidadesProductoElegidoCompra;

        system("pause");
        system("cls");

        cout<<"Desea agregar otro producto a su pedido?"<<endl;
        cout<<"1 - SI | 0 - NO"<<endl;
        cin>>finalizar;

        ///============================///
        /// ALMACENAR DETALLE TEMPORAL ///
        ///============================///

        detalles[cantidadDetalles] = detallecompra;
        cantidadDetalles++;
    }

    ///=====================///
    /// RESUMEN DE LA VENTA ///
    ///=====================///

    cout<<endl;
    cout<<"Su total es de "<< TotalFinalCompra<<endl;;
    system("pause");
    system("cls");

    ///===========================================///
    /// SELECCION Y VALIDACION DEL METODO DE PAGO ///
    ///===========================================///


//    bool mp = false;
//
//    while(!mp){
//
//        cout<<"1: EFECTIVO | 2: DEBITO | 3: CREDITO"<<endl;
//        cout<<"Seleccione su metodo de pago: ";
//        cin>>MetodoPagoElegidoVenta;
//
//        if(MetodoPagoElegidoVenta!= 1 && MetodoPagoElegidoVenta!= 2 && MetodoPagoElegidoVenta!= 3){
//
//            cout<<"Ingrese un metodo de pago válido.";
//            system("pause");
//            system("cls");
//        }
//        else{
//
//            mp = true;
//        }
//    }

    ///============================///
    /// CONFIRMAR Y GUARDAR COMPRA ///
    ///============================///

    compra.set_totalCompra(TotalFinalCompra);

    carchivo.guardar(compra);

    ///==============================///
    /// GUARDAR DETALLES DE LA VENTA ///
    ///==============================///

    for(int i = 0; i < cantidadDetalles; i++){

        dcarchivo.guardar(detalles[i]);
    }

    ///===================================///
    /// ACTUALIZAR STOCK DE LOS PRODUCTOS ///
    ///===================================///

    for(int i = 0; i < cantidadProductos; i++){

        producto = parchivo.Leer(posicionesProductos[i]);
        producto.aumentarStock(cantidadesProductos[i]);
        parchivo.Modificar(producto, posicionesProductos[i]);
    }

    system("pause");
    system("cls");

    ///=====================///
    /// FINALIZAR OPERACION ///
    ///=====================///

    cout<<"Su Venta fue procesada con Exito.";
    system("pause");
}

void menuAbm(){

    int Opcion;
    int OpcionAlta;
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
            cout<<"3 - Alta Proveedor";
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

            case 3:

                altaProveedor();
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
            cout<<"3 - Modificar Proveedor";
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

            case 3:

                modificarProveedor();
                break;

            case 0:

                break;
            }

            break;

        case 4:

            cout<<"MENU LISTADO"<<endl;
            cout<<"========================"<<endl;
            cout<<"1 - Listar Productos";
            cout<<endl;
            cout<<"2 - Listar Clientes";
            cout<<endl;
            cout<<"3 - Listar Proveedores";
            cout<<endl;
            cout<<"4 - Listar Ventas";
            cout<<endl;
            cout<<"5 - Listar Detalle de Ventas";
            cout<<endl;
            cout<<"6 - Listar Compras";
            cout<<endl;
            cout<<"7 - Listar Detalle de Compras";
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

            case 3:

                mostrarProveedores();
                break;

            case 4:

                mostrarVentas();
                break;

            case 5:

                mostrarDetalleVentas();
                break;

            case 6:

                mostrarCompras();
                break;

            case 7:

                mostrarDetalleCompras();
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

void menuReportes(){

    while(true){

        int Opcion;

        system("cls");

        cout<<"MENU REPORTES"<<endl;
        cout<<"========================"<<endl;
        cout<<"1 - Producto mas vendido";                     ///(1 O RANKING - SE PUEDE ELEGIR ENTRE EL PRODUCTO QUE MAS SE VENDE (STOCK) Y LOS 5 MAS VENDIDOS)
        cout<<endl;
        cout<<"2 - Ventas por Categoria";                      ///(TOTAL de cada Categoria) - CAFETERIA $XXXX | BEBIDAS $XXXX | PASTELERIA $XXXX
        cout<<endl;
        cout<<"3 - Metodo de Pago que Mas Recaudo";           ///(PUEDE SER PORCENTUAL) O COMO EL ANTERIOR
        cout<<endl;
        cout<<"4 - Productos en Stock Critico";               ///(LISTA TODOS CON STOCK CRITICO)
        cout<<endl;
        cout<<"5 - Ventas por Producto de una Categoria";     ///(VENTAS POR PRODUCTO (TODOS) FILTRADOS POR CATEGORIA INGRESADA POR EL USUARIO)
        cout<<endl;
        cout<<"6 - TOP 10 Mejores Clientes";                  ///DEFINIR CRITERIO (MAYOR NUMERO DE COMPRAS, MAYOR MONTO EN COMPRAS, ETC)
        cout<<endl;
        cout<<"7 - Ventas Totales";                           ///VENTAS TOTALES DEL DIA, VENTAS TOTALES DEL MES - PODEMOS ELEGIR UNO O VARIOS !!!NECESITAMOS FECHAS!!!
        cout<<endl;
        cout<<"8 - Proveedores sin comprar el anio pasado";   ///PROBEEDORES A LOS QUE NO SE LE HAYAN REALIZADO COMPRAS EL AÑO PASADO !!!NECESITAMOS FECHAS!!!
        cout<<endl;
        cout<<"0 - Salir"<<endl;
        cout<<"========================"<<endl;
        cout<< "INGRESE OPCION: ";
        cin>>Opcion;

        DetalleVentas detalleVenta;
        ArchivoDetalleVentas dvarchivo;

        Productos producto;
        ArchivoProductos parchivo;

        int cantidadAux = 0;
        int cantidadProducto = 0;
        int cantidadMax = 0;
        int idProducto;
        int posicion;

        switch(Opcion){

        case 1:

            for(int i = 0; i < parchivo.contarRegistros(true); i++){

                cantidadAux = 0;
                cantidadProducto = 0;

                producto = parchivo.Leer(i);

                for(int j = 0; j < dvarchivo.contarRegistros(); j++){

                    detalleVenta = dvarchivo.Leer(j);

                    if(producto.get_idProducto() == detalleVenta.get_idProductoDetalle()){

                        cantidadProducto+=detalleVenta.get_cantidadUnidadesDetalle();
                    }
                }

                if(cantidadProducto > cantidadAux){

                    cantidadAux = cantidadProducto;
                }

                if(cantidadAux > cantidadMax){

                    cantidadMax = cantidadAux;
                    idProducto = producto.get_idProducto();
                }
            }

            posicion = parchivo.Buscar(idProducto);
            producto = parchivo.Leer(posicion);

            system("cls");

            cout<<"Producto mas vendido"<<endl;      ///EL MAS VENDIDO ES EL PROD ID 2 CON 5 UNIDADES VENDIDAS.
            cout<<"========================"<<endl;
            cout<<"(ID "<<producto.get_idProducto()<<") "<<producto.get_nombreProducto()<<" Con "<<cantidadMax<<" unidades vendidas desde su creacion!!!"<<endl<<endl;
            system("pause");

            break;

            ///case 2:
            ///
            ///case 3:
            ///
            ///case 4:
            ///
            ///case 5:
            ///
            ///case 6:
            ///
            ///case 7:
            ///
            ///case 8:
            ///
        case 0:

            return;
        }
    }
}

void altaProducto(){

    Productos producto;
    ArchivoProductos archivo;
    int opcion;

    cout<<"1 - Para dar de alta un producto viejo | 2 - Para dar de alta un producto nuevo"<<endl;
    cout<<"Eleccion: ";
    cin>> opcion;

    system("cls");

    if(opcion == 2){

        producto.cargar();
        producto.darAlta();

        system("cls");

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


    if(opcion < 0 || opcion > 3){

        cout<<"Opcion invalida"<<endl;
        system("pause");
        return;
    }

    int cantidadTotal = archivo.Listar();

    int activos = archivo.contarRegistros(true);
    int inactivos = archivo.contarRegistros(false);

    if(opcion == 1 && activos == 0){

        cout<<"No hay productos Acitvos"<<endl;
        system("pause");
        return;
    }

    if(opcion == 2 && inactivos == 0){

        cout<<"No hay productos Inactivos"<<endl;
        system("pause");
        return;
    }

    if(opcion == 3 && cantidadTotal == 0){

        cout<<"No hay productos cargados"<<endl;
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

    if(opcion < 0 || opcion > 3){

        cout<<"Opcion invalida"<<endl;
        system("pause");
        return;
    }

    int cantidadTotal = archivo.Listar();

    int activos = archivo.contarRegistros(true);
    int inactivos = archivo.contarRegistros(false);

    if(opcion == 1 && activos == 0){

        cout<<"Ningun cliente es miembro"<<endl;
        system("pause");
        return;
    }

    if(opcion == 2 && inactivos == 0){

        cout<<"Todos los clientes son miembros"<<endl;
        system("pause");
        return;
    }

    if(opcion == 3 && cantidadTotal == 0){

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

void mostrarVentas(){

    ArchivoVentas archivo;

    archivo.Listar();

    system("pause");
}

void mostrarDetalleVentas(){

    ArchivoDetalleVentas archivo;

    archivo.Listar();

    system("pause");
}

void altaProveedor(){

    Proveedores proveedor;
    ArchivoProveedores archivo;

    proveedor.cargar();

    if(archivo.guardar(proveedor)){

        cout<<"El proveedor se guardo correctamente! :)"<<endl;
    }
    else{

        cout<<"Error al guardar proveedor. :("<<endl;
    }

    system("pause");
}

void mostrarProveedores(){

    ArchivoProveedores archivo;

    archivo.Listar();

    system("pause");
}

void modificarProveedor(){

    Proveedores proveedor;
    ArchivoProveedores archivo;

    int id;
    int posicion;

    cout<<"Ingrese el ID de proveedor que quiere modificar: ";
    cin>>id;

    posicion = archivo.Buscar(id);

    if(posicion < 0){

        cout<<"proveedor NO encontrado."<<endl;
        system("pause");
        return;
    }

    system("cls");
    proveedor = archivo.Leer(posicion);

    int opcion;

    cout<<"Que campo quiere cambiar?"<<endl;
    cout<<"==========================="<<endl;
    cout<<"1 - Nombre"<<endl;
    cout<<"2 - Rubro"<<endl;
    cout<<"3 - Telefono"<<endl;
    cout<<"4 - Pais"<<endl;
    cout<<"5 - Locacion"<<endl;
    cout<<"==========================="<<endl;
    cin>>opcion;

    switch(opcion){

    case 1:

        char nombreNuevo[60];

        cout<<"Ingrese su nuevo nombre: ";
        cin>>nombreNuevo;

        proveedor.set_nombreEmpresa(nombreNuevo);
        break;

    case 2:

        char rubroNuevo[55];

        cout<<"Ingrese su nuevo rubro: ";
        cin>>rubroNuevo;

        proveedor.set_rubroEmpresa(rubroNuevo);
        break;

    case 3:

        char telefonoNuevo[20];

        cout<<"Ingrese su nuevo telefono: ";
        cin>>telefonoNuevo;

        proveedor.set_telefonoEmpresa(telefonoNuevo);
        break;

    case 4:

        char paisNuevo[40];

        cout<<"Ingrese su nuevo mail: ";
        cin>>paisNuevo;

        proveedor.set_paisEmpresa(paisNuevo);
        break;

    case 5:

        char locacioNuevo[40];

        cout<<"Ingrese su nuevo mail: ";
        cin>>locacioNuevo;

        proveedor.set_locacionEmpresa(locacioNuevo);
        break;

    case 0:

        return;
    }

    archivo.Modificar(proveedor, posicion);
}

void mostrarCompras(){

    ArchivoCompras archivo;

    archivo.Listar();

    system("pause");
}

void mostrarDetalleCompras(){

    ArchivoDetalleCompras archivo;

    archivo.Listar();

    system("pause");
}
