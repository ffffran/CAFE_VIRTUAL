#include <iostream>
#include <cstring>
#include <cctype>
#include "DetalleVentas.h"
using namespace std;

void DetalleVentas::mostrar(){

    cout<<"ID VENTA: "<< idVentaDetalle<<endl;
    cout<<"ID PRODUCTO: "<< idProductoDetalle<<endl;
    cout<<"CANT. UNIDADES: "<< cantidadUnidadesDetalle<<endl;
    cout<<"PRECIO UNITARIO: $"<< precioUnitarioDetalle<<endl;
    cout<<"SUBTOTAL: $"<< subTotalDetalle<<endl;
}

void DetalleVentas::set_idVentaDetalle(int id_venta){

    idVentaDetalle = id_venta;
}

void DetalleVentas::set_idProductoDetalle(int id_producto){

    idProductoDetalle = id_producto;
}

void DetalleVentas::set_cantidadUnidadesDetalle(int cantidad_elegida){

    cantidadUnidadesDetalle = cantidad_elegida;
}

void DetalleVentas::set_precioUnitarioDetalle(float precio_unitario){

    precioUnitarioDetalle = precio_unitario;
}

void DetalleVentas::set_subTotalDetalle(float sub_precio_unitario, int sub_cantidad_elegida){

    float subTotalCalculado = sub_precio_unitario * sub_cantidad_elegida;

    subTotalDetalle = subTotalCalculado;
}

int DetalleVentas::get_idVentaDetalle(){

    return idVentaDetalle;
}

int DetalleVentas::get_idProductoDetalle(){

    return idProductoDetalle;
}

int DetalleVentas::get_cantidadUnidadesDetalle(){

    return cantidadUnidadesDetalle;
}

float DetalleVentas::get_precioUnitarioDetalle(){

    return precioUnitarioDetalle;
}

float DetalleVentas::get_subTotalDetalle(){

    return subTotalDetalle;
}




