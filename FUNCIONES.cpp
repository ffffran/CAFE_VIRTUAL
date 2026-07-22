#include <iostream>
#include <cstring>
#include <iomanip>
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
#include "Fecha.h"

using namespace std;

void menuPrincipal(){

    int opcion, opcionproductos, opcionclientes, opcionproveedores, opcioncompras, opcionventas;

    while(true){

        system("cls");

        cout<<"BIENVENIDO A..."<<endl;
        cout<<" ---------------------------------------------------------------"<<endl;
        cout<<"|              _______  _______  _______  _______               |"<<endl;
        cout<<"|             |       ||   _   ||       ||       |              |"<<endl;
        cout<<"|             |      _||  |_|  ||    ___||    ___|              |"<<endl;
        cout<<"|             |     |  |       ||   |___ |   |___               |"<<endl;
        cout<<"|             |     |_ |       ||    ___||    ___|              |"<<endl;
        cout<<"|             |       ||   _   ||   |    |   |___               |"<<endl;
        cout<<"|             |_______||__| |__||___|    |_______|              |"<<endl;
        cout<<"|  __   __  ___   ______    _______  __   __  _______  ___      |"<<endl;
        cout<<"| |  | |  ||   | |    _ |  |       ||  | |  ||   _   ||   |     |"<<endl;
        cout<<"| |  |_|  ||   | |   | ||  |_     _||  | |  ||  |_|  ||   |     |"<<endl;
        cout<<"| |       ||   | |   |_||_   |   |  |  |_|  ||       ||   |     |"<<endl;
        cout<<"| |       ||   | |    __  |  |   |  |       ||       ||   |___  |"<<endl;
        cout<<"|  |     | |   | |   |  | |  |   |  |       ||   _   ||       | |"<<endl;
        cout<<"|   |___|  |___| |___|  |_|  |___|  |_______||__| |__||_______| |"<<endl;
        cout<<"|                                                               |"<<endl;
        cout<<" ---------------------------------------------------------------"<<endl;
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"========================"<<endl;
        cout<<"1 - Productos"<<endl;
        cout<<"2 - Proveedores"<<endl;
        cout<<"3 - Clientes"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"4 - Compras"<<endl;
        cout<<"5 - Ventas"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"6 - Reportes"<<endl;
        cout<<"0 - Salir"<<endl;
        cout<<"========================"<<endl;
        cout<< "INGRESE OPCION: ";
        cin>>opcion;
        system("cls");

        switch(opcion){

        case 1:

            cout<<"MENU PRODUCTOS"<<endl;
            cout<<"==================="<<endl;
            cout<<"1 - Alta"<<endl;
            cout<<"2 - Baja"<<endl;
            cout<<"3 - Modificar"<<endl;
            cout<<"4 - Listar"<<endl;
            cout<<"0 - Salir"<<endl;
            cout<<"==================="<<endl;
            cin>>opcionproductos;

            system("cls");

            switch(opcionproductos){

            case 1:

                altaProducto();
                break;

            case 2:

                bajaProducto();
                break;

            case 3:

                modificarProducto();
                break;

            case 4:{

                ArchivoProductos aProducto;
                aProducto.Listar();
                system("pause");
                break;
            }
            case 0:

                break;
            }

            break;

        case 2:

            cout<<"MENU PROVEEDORES"<<endl;
            cout<<"==================="<<endl;
            cout<<"1 - Alta"<<endl;
            cout<<"2 - Mostrar"<<endl;
            cout<<"3 - Modificar"<<endl;
            cout<<"0 - Salir"<<endl;
            cout<<"==================="<<endl;
            cin>>opcionproveedores;

            system("cls");

            switch(opcionproveedores){

            case 1:

                altaProveedor();
                break;

            case 2:

                mostrarProveedores();
                break;

            case 3:

                modificarProveedor();
                break;

            case 0:

                break;
            }

            break;

        case 3:

            cout<<"MENU CLIENTES"<<endl;
            cout<<"==================="<<endl;
            cout<<"1 - Alta"<<endl;
            cout<<"2 - Baja"<<endl;
            cout<<"3 - Mostrar"<<endl;
            cout<<"4 - Modificar"<<endl;
            cout<<"0 - Salir"<<endl;
            cout<<"==================="<<endl;
            cin>>opcionclientes;

            system("cls");

            switch(opcionclientes){

            case 1:

                altaCliente();
                break;

            case 2:

                bajaCliente();
                break;

            case 3:

                mostrarClientes();
                break;

            case 4:

                modificarCliente();
                break;

            case 0:

                break;
            }

            break;

        case 4:

            cout<<"MENU COMPRAS"<<endl;
            cout<<"==================="<<endl;
            cout<<"1 - Nueva Compra"<<endl;
            cout<<"2 - Ver Compras"<<endl;
            cout<<"0 - Salir"<<endl;
            cout<<"==================="<<endl;
            cin>>opcioncompras;
            system("cls");

            switch(opcioncompras){

            case 1:

                menuCompra();
                break;

            case 2:{

                ArchivoDetalleCompras detalle;
                int id;

                mostrarCompras();
                cout<<endl;
                cout<<"Ingrese el ID de una compra para ver su detalle: ";
                cin>>id;
                system("cls");

                detalle.Mostrar1(id);

                break;
            }

            case 0:

                break;
            }

            break;

        case 5:

            cout<<"MENU VENTAS"<<endl;
            cout<<"==================="<<endl;
            cout<<"1 - Nueva Venta"<<endl;
            cout<<"2 - Ver Ventas"<<endl;
            cout<<"0 - Salir"<<endl;
            cout<<"==================="<<endl;
            cin>>opcionventas;
            system("cls");

            switch(opcionventas){

            case 1:

                menuVenta();
                break;

            case 2:{

                ArchivoDetalleVentas detalle;
                int id;

                mostrarVentas();
                cout<<endl;
                cout<<"Ingrese el ID de una compra para ver su detalle: ";
                cin>>id;
                system("cls");

                detalle.Mostrar1(id);

                break;
            }

            case 0:

                break;
            }

            break;

        case 6:

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

    Fecha fecha;
    fecha.Cargar();

    DetalleVentas detalleventa;     /// ESTO CONCEPTUALMENTE DEBERIA ESTAR EN EL WHILE CON CADA VUELTA.
    ArchivoDetalleVentas dvarchivo; /// POR AHORA LO VAMOS A DEJAR ACÁ PORQUE ESTÁ TODO ACOMODADO ASÍ. PERO SE PODRÍA MEJORAR CAMBIANDO ESO.

    Ventas venta;
    ArchivoVentas varchivo;

    venta.set_fechaVenta(fecha);

    Clientes cliente;
    ArchivoClientes carchivo;

    Productos producto;
    ArchivoProductos parchivo;

    venta.set_idVenta(varchivo.contarRegistros() + 1);

    detalleventa.set_idVentaDetalle(venta.get_idVenta());

    ///=============================///
    /// DATOS GENERALES DE LA VENTA ///
    ///=============================///

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
    int posicion = carchivo.Buscar(IdClienteIngresadoVenta);

    if(posicion>=0){
        cliente = carchivo.Leer(posicion);
        venta.set_idClienteVenta(IdClienteIngresadoVenta);
        cout<<"Venta asociada al cliente "<<cliente.get_nombreCliente()<<"!"<<endl;
        system("pause");
        system("cls");
    }
    else{
        cout<<"El cliente buscado no existe."<<endl;
        system("pause");
        system("cls");
        return;
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

        cout<<left;
        cout<<setw(6)<<"ID";
        cout<<setw(35)<<"NOMBRE";
        cout<<setw(12)<<"PRECIO";
        cout<<setw(15)<<"CATEGORIA";
        cout<<setw(10)<<"TAMANIO";
        cout<<setw(8)<<"STOCK";
        cout<<setw(10)<<"ESTADO";
        cout<<endl;

        cout<<string(94, '.')<<endl;

        for(int i = 0; i < parchivo.Contar(); i++){

            producto = parchivo.Leer(i);

            if(producto.get_estadoProducto()){

                producto.mostrar();
            }
        }
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
    /// RESUMEN DE LA COMPRA///
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
    /// CONFIRMAR Y GUARDAR COMPRA///
    ///===========================///

    venta.set_metodoPagoVenta(MetodoPagoElegidoVenta);
    venta.set_totalVenta(TotalFinalVenta);

    varchivo.guardar(venta);

    ///==============================///
    /// GUARDAR DETALLES DE LA COMPRA///
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

    int IdProveedorIngresadoCompra;
    int IdProductoIngresadoCompra;
    int UnidadesProductoElegidoCompra;
    float TotalFinalCompra = 0;

    ///============================///
    /// ASOCIAR CLIENTE A LA COMPRA///
    ///============================///

    cout<<"0 Para Compra General | ID Proveedor Para Asociar Su Compra"<<endl;
    cout<<"ID: ";
    cin>>IdProveedorIngresadoCompra;
    cout<<endl;
    int posicion = proarchivo.Buscar(IdProveedorIngresadoCompra);

    if(posicion>=0){
        proveedor = proarchivo.Leer(posicion);
        compra.set_idProveedorCompra(IdProveedorIngresadoCompra);
        cout<<"Compra asociada al proveedor "<< proveedor.get_nombreEmpresa()<<endl;
        system("pause");
        system("cls");
    }
    else{
        cout<<"El proveedor buscado no existe."<<endl;
        system("pause");
        system("cls");
        return;
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
        parchivo.Listar();
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

                //mostrarDetalleVentas();
                break;

            case 6:

                mostrarCompras();
                break;

            case 7:

                //mostrarDetalleCompras();
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

        switch(Opcion){

        case 1:{

            DetalleVentas detalle;
            ArchivoDetalleVentas adventas;

            Productos producto;
            ArchivoProductos aproductos;

            int cantidadProductos = aproductos.contarRegistros(true);
            int *ventasProducto;
            ventasProducto = new int [cantidadProductos];                     ///oooo podemos hacer int *ventasProducto = new int [cantidadProductos];

            for(int i = 0; i < cantidadProductos; i++){                       ///oooo podemos hacer: ventasProducto = new int [cantidadProductos]{};

                ventasProducto[i] = 0;
            }

            int cantidadDetalles = adventas.contarRegistros();

            for(int i = 0; i < cantidadDetalles; i++){

                detalle = adventas.Leer(i);
                ventasProducto[detalle.get_idProductoDetalle() - 1] += detalle.get_cantidadUnidadesDetalle();
            }

            int maximo = 0;
            int indmax = 0;

            for(int i = 0; i < cantidadProductos; i++){

                if(ventasProducto[i] > maximo){

                    maximo = ventasProducto[i];
                    indmax = i;
                }
            }

            producto = aproductos.Leer(indmax);

            system("cls");

            cout<<"Producto mas vendido:"<<endl;
            cout<<"==============================================================="<<endl;
            cout<<"(ID "<<producto.get_idProducto()<<") "<<producto.get_nombreProducto()<<", Con "<<maximo<<" unidades vendidas desde su creacion!!!"<<endl;
            cout<<"==============================================================="<<endl;
            system("pause");

            delete [] ventasProducto;

            break;
        }

        case 2:{

            DetalleVentas detalle;
            ArchivoDetalleVentas adventas;

            Productos producto;
            ArchivoProductos aproductos;

            int cantidadDetalles = adventas.contarRegistros();
            int cantidadProductos = aproductos.contarRegistros(true);

            Productos *productos = new Productos[cantidadProductos];

            for(int i = 0; i < cantidadProductos; i++){

                productos[i] = aproductos.Leer(i);

            }

            float recBebidas = 0;
            float recCafeteria = 0;
            float recPasteleria = 0;

            for(int i = 0; i < cantidadDetalles; i++){

                detalle = adventas.Leer(i);

                // Obtener directamente el producto desde el vector
                producto = productos[detalle.get_idProductoDetalle() - 1];

                float subtotal = detalle.get_subTotalDetalle();

                switch(producto.get_categoriaProducto()){

                case 'B':
                    recBebidas += subtotal;
                    break;

                case 'C':
                    recCafeteria += subtotal;
                    break;

                case 'P':
                    recPasteleria += subtotal;
                    break;
                }
            }

            delete[] productos;

            // Mostrar resultados
            system("cls");

            cout<<"Ventas por Categoria"<<endl;
            cout<<"=================================="<<endl;
            cout<<"CAFETERIA : $"<<recCafeteria<<endl;
            cout<<"BEBIDAS   : $"<<recBebidas<<endl;
            cout<<"PASTELERIA: $"<<recPasteleria<<endl;
            cout<<"=================================="<<endl;

            cout<<endl;

            system("pause");

            break;
        }

        case 3:{

            ArchivoVentas vArchivo;
            Ventas venta;
            int cantidadVentas = vArchivo.contarRegistros();
            float recEfectivo = 0;
            float recDebito = 0;
            float recCredito = 0;

            //Lectura
            for(int i = 0; i < cantidadVentas; i++){

                venta = vArchivo.Leer(i);
                int metodo = venta.get_metodoPagoVenta();
                float plata = venta.get_totalVenta();

                //Acumuladores
                if(metodo == 1) recEfectivo += plata;
                else if(metodo == 2) recDebito += plata;
                else if(metodo == 3) recCredito += plata;
            }

            system("cls");
            cout<<"Metodo de pago mas usado:"<<endl;
            cout<<"========================================="<<endl;

            //Maximo
            if(recEfectivo >= recDebito && recEfectivo >= recCredito){
                cout << "El metodo que mas recaudo fue: EFECTIVO" << endl;
                cout << "Con un total de: " << recEfectivo << "$" << endl;
            }
            else if(recDebito >= recEfectivo && recDebito >= recCredito){
                cout << "El metodo que mas recaudo fue: DEBITO" << endl;
                cout << "Con un total de: " << recDebito << "$" << endl;
            }
            else {
                cout << "El metodo que mas recaudo fue: CREDITO" << endl;
                cout << "Con un total de: " << recCredito << "$" << endl;
                cout<<"========================================="<<endl;
            }

            cout << endl;
            system("pause");

            break;
        }

        case 4:{

            ArchivoProductos pArchivo;
            Productos producto;
            int cantidadTotal = pArchivo.Contar();
            //Contador
            int contCriticos = 0;

            system("cls");
            cout << "Productos con stock critico:" << endl;
            cout << "====================================" << endl;

            for(int i = 0; i < cantidadTotal; i++) {
                producto = pArchivo.Leer(i);
                //Comparacion
                if(producto.get_estadoProducto() && producto.stockBajo()) {
                    cout << "ID: " << producto.get_idProducto() << " | " << "Producto: " << producto.get_nombreProducto() << endl;
                    cout << "Stock Actual: " << producto.get_stockProducto() << " | Stock Minimo: " << producto.get_stockMinimo() << endl;
                    cout << "====================================" << endl;
                    contCriticos++;
                }
            }

            //Vemos si el contador quedo en 0 o no
            if(contCriticos == 0) {
                cout << "No hay productos con stock critico por ahora" << endl;
            }
            else{
                cout << "Total de productos a reponer: " << contCriticos << endl;
            }
            cout << "====================================" << endl;
            cout << endl;
            system("pause");

            break;
        }

        case 5:{
            ArchivoProductos pArchivo;
            ArchivoDetalleVentas dvArchivo;
            Productos producto;
            DetalleVentas detalle;
            char catIngresada;

            system("cls");
            cout << "Ventas por categoria:"<< endl;
            cout << "============================================" << endl;
            cout << "Escoger una de las categorias:"<<endl;
            cout << "B- Bebida"<<endl<<"C- Cafeteria"<<endl<<"P- Pasteleria"<< endl;
            cout << "============================================" << endl;
            cout << "Categoria: ";
            cin >> catIngresada;
            system("cls");
            //Totales de producto y detalle de venta
            int cantProductos = pArchivo.Contar();
            int cantDetalles = dvArchivo.contarRegistros();
            bool huboVentas = false;

            cout << endl << "Listado de ventas para la categoria: " << catIngresada << endl;
            cout << "============================================" << endl;

            //Recorremos los productos
            for(int i = 0; i < cantProductos; i++){
                producto = pArchivo.Leer(i);

            //Vemos si esta en esa categoria
                if(producto.get_categoriaProducto() == catIngresada){
                    int unidadesVendidas = 0;
                    float recaudacionProducto = 0;

            //Buscamos el producto en los detalles de ventas
                    for(int j = 0; j < cantDetalles; j++) {
                        detalle = dvArchivo.Leer(j);

                        if(detalle.get_idProductoDetalle() == producto.get_idProducto()){
                            unidadesVendidas += detalle.get_cantidadUnidadesDetalle();
                            recaudacionProducto += detalle.get_subTotalDetalle();
                        }
                    }

            //Resultado
                    if(unidadesVendidas > 0){
                        cout << "Producto: " << producto.get_nombreProducto() << endl;
                        cout << "Unidades totales: " << unidadesVendidas << endl;
                        cout << "Recaudacion total: " << recaudacionProducto << "$"<< endl;
                        cout << "============================================" << endl;
                        huboVentas = true;
                    }
                }
            }

            if(!huboVentas) {
                cout << "No hay ventas para esta categoria" << endl;
            }

            system("pause");
            break;
        }

        case 6:{
            ArchivoClientes archClientes;
            ArchivoVentas archVentas;

            int cantClientes = archClientes.Contar();
            int cantVentas = archVentas.contarRegistros();

            //Nos fijamos si existen clientes
            if (cantClientes == 0) {
                cout << "No hay clientes registrados" << endl;
                system("pause");
                break;
            }

            //Estructura para asociar el id con el total
            struct GastoCliente {
                int id;
                float totalGastado;
            };

            //Reservamos memoria para todos los clientes
            GastoCliente* listaGastos = new GastoCliente[cantClientes];

            //Iniciamos la lista con los ids ya existentes
            for (int i = 0; i < cantClientes; i++) {
                listaGastos[i].id = archClientes.Leer(i).get_idCliente();
                listaGastos[i].totalGastado = 0;
            }

            //Leemos el archivo de ventas para vincular todo
            for (int i = 0; i < cantVentas; i++) {
                Ventas v = archVentas.Leer(i);
                int idCli = v.get_idClienteVenta();

                //Sumamos el total del cliente buscandolos por id
                for (int j = 0; j < cantClientes; j++) {

                    if (listaGastos[j].id == idCli) {
                        listaGastos[j].totalGastado += v.get_totalVenta();
                        break;
                    }
                }
            }

            //Ordenamos la lista de mayor a menor gasto
            for (int i = 0; i < cantClientes - 1; i++) {
                for (int j = 0; j < cantClientes - i - 1; j++) {
                    if (listaGastos[j].totalGastado < listaGastos[j + 1].totalGastado) {
                        GastoCliente aux = listaGastos[j];
                        listaGastos[j] = listaGastos[j + 1];
                        listaGastos[j + 1] = aux;
                    }
                }
            }

            system("cls");
            cout << "===================================================" << endl;
            cout << "           TOP 10 CLIENTES CON MAYOR GASTO         " << endl;
            cout << "===================================================" << endl;
            cout << left << setw(10) << "PUESTO" << setw(10) << "ID" << setw(20) << "NOMBRE" << "TOTAL GASTADO" << endl;
            cout << "---------------------------------------------------" << endl;

            int tope = (cantClientes < 10) ? cantClientes : 10;
            for (int i = 0; i < tope; i++) {
                //Mostramos solo si hicieron al menos una compra

                if (listaGastos[i].totalGastado > 0) {
                    int pos = archClientes.Buscar(listaGastos[i].id);
                    Clientes c = archClientes.Leer(pos);

                    cout << left << setw(10) << (i + 1)
                        << setw(10) << listaGastos[i].id
                        << setw(20) << c.get_nombreCliente()
                        << "$ " << fixed << setprecision(2) << listaGastos[i].totalGastado << endl;
                }
            }

            cout << "===================================================" << endl;
            //Liberamos memoria
            delete[] listaGastos;
            system("pause");
            break;
        }

        case 7:{
            ArchivoVentas archV;
            Ventas v;
            int tipoReporte;
            float acuTotal = 0;
            int totalRegistros = archV.contarRegistros();
            system("cls");

            cout << "Ventas totales:" << endl;
            cout << "==========================================" << endl;
            cout << "1 - Ventas de una fecha en especifico" << endl;
            cout << "2 - Ventas de un mes en especifico" << endl;
            cout << "==========================================" << endl;
            cout << "Seleccione una opcion: ";
            cin >> tipoReporte;
            system("cls");

            if (tipoReporte == 1) {
                int d, m, a;
                cout << "Ingresar el dia: " << endl;
                cin >> d;
                cout << "Ingresar el mes: " << endl;
                cin >> m;
                cout << "Ingresar el anio: " << endl;
                cin >> a;

                for (int i = 0; i < totalRegistros; i++) {
                    v = archV.Leer(i);
                    Fecha fv = v.get_fechaVenta();

                    //Comparamos todo para ver si concuerda con lo escrito por el usuario
                    if (fv.get_dia() == d && fv.get_mes() == m && fv.get_anio() == a) {
                        acuTotal += v.get_totalVenta();
                    }
                }
                cout << "==========================================" << endl;
                cout << "Recaudacion total del dia " << d << "/" << m << "/" << a << ": " << acuTotal << "$" << endl;

            }
            else if (tipoReporte == 2) {

                int m, a;
                cout << "Ingresar el mes: " << endl;
                cin >> m;
                cout << "Ingresar el anio: " << endl;
                cin >> a;

                for (int i = 0; i < totalRegistros; i++) {
                    v = archV.Leer(i);
                    Fecha fv = v.get_fechaVenta();

                    //Comparamos mes y año
                    if (fv.get_mes() == m && fv.get_anio() == a) {
                        acuTotal += v.get_totalVenta();
                    }
                }
                cout << "==========================================" << endl;
                cout << "Recaudacion total del mes " << m << "/" << a << ": " << acuTotal << "$" << endl;
            }

            system("pause");
            break;
        }

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
        cout<<endl;

        posicion = archivo.Buscar(id);

        if(posicion == -1){

            cout<<"Producto NO encontrado."<<endl;
            system("pause");
            return;
        }

        producto = archivo.Leer(posicion);

        producto.darAlta();

        archivo.Modificar(producto, posicion);

        encabezadoProductos();

        archivo.Listar();
        cout<<endl;

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
    cout<<endl;

    posicion = archivo.Buscar(id);

    if(posicion <= 0){

        cout<<"Producto NO encontrado."<<endl;
        system("pause");
        return;
    }

    producto = archivo.Leer(posicion);

    producto.darBaja();

    archivo.Modificar(producto, posicion);

    encabezadoProductos();

    archivo.Listar();
    cout<<endl;

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

    int cantidadTotal = archivo.Contar();

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
    cout<<"3 - Categoria"<<endl;
    cout<<"4 - Tamanio"<<endl;
    cout<<"5 - Stock Minimo"<<endl;
    cout<<"6 - Estado"<<endl;
    cout<<"0 - Salir"<<endl;
    cout<<"==========================="<<endl;
    cin>>opcion;

    cin.ignore();

    switch(opcion){

    case 1:

        char nombreNuevo[50];

        cout<<"Ingrese su nuevo nombre: ";
        cin.getline(nombreNuevo,50);

        producto.set_nombreProducto(nombreNuevo);
        break;

    case 2:

        float precioNuevo;

        cout<<"Ingrese su nuevo precio: $";
        cin>>precioNuevo;

        producto.set_precioProducto(precioNuevo);
        break;

    case 3:

        char categoriaNueva;

        cout<<"c = cafetería, p = pastelería o b = bebidas"<<endl<<endl;
        cout<<"Ingrese su nueva categoria: ";
        cin>>categoriaNueva;

        producto.set_categoriaProducto(categoriaNueva);
        break;

    case 4:

        char tamanioNuevo;

        cout<<"p = pequeño, m = mediano o g = grande"<<endl<<endl;
        cout<<"Ingrese su nueva categoria: ";
        cin>>tamanioNuevo;

        producto.set_tamanioProducto(tamanioNuevo);
        break;

    case 5:

        int stockMinimoNuevo;

        cout<<"Ingrese su nuevo Stock Minimo: ";
        cin>>stockMinimoNuevo;

        producto.set_stockMinimo(stockMinimoNuevo);
        break;

    case 6:

        bool estadoNuevo;

        cout<<"1 - Activo | 0 - Inactivo"<<endl<<endl;
        cout<<"Ingrese su nuevo estado: ";
        cin>>estadoNuevo;

        producto.set_estadoProducto(estadoNuevo);
        break;

    case 0:

        return;
    }

    archivo.Modificar(producto, posicion);

    system("cls");

    encabezadoProductos();

    producto.mostrar();

    cout<<endl;
    cout<<"El cambio fue realizado con exito :)"<<endl<<endl;
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

void altaCliente(){

    Clientes cliente;
    ArchivoClientes archivo;

    cliente.cargar();
    cliente.darAlta();

    if(archivo.guardar(cliente)){

        archivo.Listar();
        cout<<"El cliente se guardo correctamente! :)"<<endl;
    }
    else{

        cout<<"Error al guardar cliente. :("<<endl;
        system("pause");
    }
}

void bajaCliente(){

    Clientes cliente;
    ArchivoClientes archivo;

    int id;
    int posicion;

    cout<<"Ingrese el ID del Cliente que quiere dar de baja: ";
    cin>> id;

    posicion = archivo.Buscar(id);

    if(posicion <= 0){

        cout<<"Cliente no encontrado.";
        system("pause");
        return;
    }

    cliente = archivo.Leer(posicion);

    cliente.darBaja();

    archivo.Modificar(cliente, posicion);


    if(archivo.Leer(posicion).get_estadoCliente() == false){

        archivo.Listar();
        cout<<"El cliente se dio de baja correctamente! :)"<<endl;
    }
    else{

        cout<<"Error al dar de baja el cliente. :("<<endl;
        system("pause");
    }
}

void mostrarClientes(){

    Clientes cliente;
    ArchivoClientes archivo;

    int opcion;

    cout<<"MENU MOSTRAR CLIENTES"<<endl;
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

    int cantidadTotal = archivo.Contar();

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

        cout<<"No hay clientes cargados aun"<<endl;
        system("pause");
        return;
    }

    system("cls");

    cout<<left;
    cout<<setw(6)<<"ID";
    cout<<setw(35)<<"NOMBRE";
    cout<<setw(12)<<"DNI";
    cout<<setw(20)<<"TELEFONO";
    cout<<setw(40)<<"MAIL";
    cout<<setw(8)<<"MIEMBRO";
    cout<<endl;

    cout<<string(125, '.')<<endl;

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

    cin.ignore();

    switch(opcion){

    case 1:

        char nombreNuevo[40];

        cout<<"Ingrese su nuevo nombre: ";
        cin.getline(nombreNuevo,40);

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
        cin.getline(telefonoNuevo,20);

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

    system("cls");



    cliente.mostrar();

    cout<<endl;
    cout<<"El cambio fue realizado con exito :)"<<endl<<endl;
    system("pause");
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
    proveedor.darAlta();

    if(archivo.guardar(proveedor)){

        cout<<"El proveedor se guardo correctamente! :)"<<endl;
    }
    else{

        cout<<"Error al guardar proveedor. :("<<endl;
    }

    system("pause");
}

void bajaProveedor(){

    Proveedores proveedor;
    ArchivoProveedores archivo;

    int id;
    int posicion;

    cout<<"Ingrese el ID del Proveedor que quiere dar de baja: ";
    cin>> id;

    posicion = archivo.Buscar(id);

    if(posicion <= 0){

        cout<<"Proveedor no encontrado.";
        system("pause");
        return;
    }

    proveedor = archivo.Leer(posicion);

    proveedor.darBaja();

    archivo.Modificar(proveedor, posicion);


    if(archivo.Leer(posicion).get_estadoProveedor() == false){

        cout<<"El proveedor se dio de baja correctamente! :)"<<endl;
    }
    else{

        cout<<"Error al dar de baja el proveedor. :("<<endl;
    }

    system("pause");
}

void mostrarProveedores(){

    Proveedores proveedor;
    ArchivoProveedores archivo;

    int opcion;

    cout<<"MENU MOSTRAR PROVEEDORES"<<endl;
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

    int cantidadTotal = archivo.Contar();

    int activos = archivo.contarRegistros(true);
    int inactivos = archivo.contarRegistros(false);

    if(opcion == 1 && activos == 0){

        cout<<"Ningun Proveedor esta Activo"<<endl;
        system("pause");
        return;
    }

    if(opcion == 2 && inactivos == 0){

        cout<<"Todos los Proveedores estan Activos"<<endl;
        system("pause");
        return;
    }

    if(opcion == 3 && cantidadTotal == 0){

        cout<<"No hay Proveedores cargados aun"<<endl;
        system("pause");
        return;
    }

    system("cls");

    encabezadoProveedores();

    for(int i = 0; i < cantidadTotal; i++){

        proveedor = archivo.Leer(i);

        if(opcion == 1 && proveedor.get_estadoProveedor()){

            proveedor.mostrar();
        }
        else if(opcion == 2 && !proveedor.get_estadoProveedor()){

            proveedor.mostrar();
        }
        else if(opcion == 3){

            proveedor.mostrar();
        }
    }

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

    cin.ignore();

    switch(opcion){

    case 1:

        char nombreNuevo[60];

        cout<<"Ingrese su nuevo nombre: ";
        cin.getline(nombreNuevo,60);

        proveedor.set_nombreEmpresa(nombreNuevo);
        break;

    case 2:

        char rubroNuevo[55];

        cout<<"Ingrese su nuevo rubro: ";
        cin.getline(rubroNuevo,55);

        proveedor.set_rubroEmpresa(rubroNuevo);
        break;

    case 3:

        char telefonoNuevo[20];

        cout<<"Ingrese su nuevo telefono: ";
        cin.getline(telefonoNuevo,20);

        proveedor.set_telefonoEmpresa(telefonoNuevo);
        break;

    case 4:

        char paisNuevo[40];

        cout<<"Ingrese su nuevo mail: ";
        cin.getline(paisNuevo,40);

        proveedor.set_paisEmpresa(paisNuevo);
        break;

    case 5:

        char locacioNuevo[40];

        cout<<"Ingrese su nuevo mail: ";
        cin.getline(locacioNuevo,40);

        proveedor.set_locacionEmpresa(locacioNuevo);
        break;

    case 0:

        return;
    }

    archivo.Modificar(proveedor, posicion);

    system("cls");

    encabezadoProveedores();

    proveedor.mostrar();

    cout<<endl;
    cout<<"El cambio fue realizado con exito :)"<<endl<<endl;
    system("pause");
}

void mostrarCompras(){

    ArchivoCompras archivo;

    archivo.Listar();
}

void encabezadoProductos(){

    cout<<left;
    cout<<setw(6)<<"ID";
    cout<<setw(35)<<"NOMBRE";
    cout<<setw(12)<<"PRECIO";
    cout<<setw(15)<<"CATEGORIA";
    cout<<setw(10)<<"TAMANIO";
    cout<<setw(8)<<"STOCK";
    cout<<setw(8)<<"ESTADO";
    cout<<endl;

    cout<<string(95, '.')<<endl;
}

void encabezadoClientes(){

    cout<<left;
    cout<<setw(6)<<"ID";
    cout<<setw(35)<<"NOMBRE";
    cout<<setw(12)<<"DNI";
    cout<<setw(20)<<"TELEFONO";
    cout<<setw(40)<<"MAIL";
    cout<<setw(8)<<"MIEMBRO";
    cout<<endl;

    cout<<string(125, '.')<<endl;
}

void encabezadoProveedores(){

    cout<<left;
    cout<<setw(6)<<"ID";
    cout<<setw(40)<<"NOMBRE";
    cout<<setw(30)<<"RUBRO";
    cout<<setw(30)<<"PAIS";
    cout<<setw(30)<<"LOCACION";
    cout<<setw(20)<<"TELEFONO";
    cout<<endl;

    cout<<string(155, '.')<<endl;
}

