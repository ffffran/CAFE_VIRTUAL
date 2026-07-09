#include <iostream>
#include <cstring>
#include <cctype>
#include "Ventas.h"
#include "Fecha.h"
using namespace std;

void Ventas::mostrar(){

    cout<<"ID VENTA: "<<idVenta<<endl;
    cout<<"ID CLIENTE: "<<idClienteVenta<<endl;

    if(metodoPagoVenta == 1){
        cout<<"METODO DE PAGO: EFECTIVO"<<" ("<<metodoPagoVenta<<")"<<endl;
    }
    else if(metodoPagoVenta == 2){
        cout<<"METODO DE PAGO: DEBITO"<<" ("<<metodoPagoVenta<<")"<<endl;
    }
    else if(metodoPagoVenta == 3){
        cout<<"METODO DE PAGO: CREDITO"<<" ("<<metodoPagoVenta<<")"<<endl;
    }

    cout<<"TOTAL: $"<<totalVenta<<endl;

    fechaVenta.Mostrar();
}

void Ventas::set_idVenta(int idVentaEnviado){

    if(idVentaEnviado > 0){

        idVenta = idVentaEnviado;
    }
}

void Ventas::set_idClienteVenta(int idClienteVentaEnviado){

    if(idClienteVentaEnviado > 0 ){

        idClienteVenta = idClienteVentaEnviado;
    }
}

void Ventas::set_metodoPagoVenta(int metodoPagoVentaIngresado){

    if(metodoPagoVentaIngresado > 0 && metodoPagoVentaIngresado < 4){

        metodoPagoVenta = metodoPagoVentaIngresado;
    }
    else{

        cout<<"Ingrese un metodo de pago valido";
        system("pause");
    }
}

void Ventas::set_fechaVenta(Fecha fecha){

    fechaVenta = fecha;
}

void Ventas::set_totalVenta(float totalVentaCalculado){

    if(totalVentaCalculado > 0){

        totalVenta = totalVentaCalculado;
    }
}

int Ventas::get_idVenta(){

    return idVenta;
}

int Ventas::get_idClienteVenta(){

    return idClienteVenta;
}

int Ventas::get_metodoPagoVenta(){

    return metodoPagoVenta;
}

Fecha Ventas::get_fechaVenta(){

    return fechaVenta;
}

float Ventas::get_totalVenta(){

    return totalVenta;
}




