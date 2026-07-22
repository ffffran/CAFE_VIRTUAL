#include <iostream>
#include <cstring>
#include <cctype>
#include "DetalleCompras.h"
using namespace std;

void DetalleCompras::mostrar(){

    cout<<"ID COMPRA: "<< idCompraDetalle<<endl;
    cout<<"ID PRODUCTO: "<< idProductoDetalle<<endl;
    cout<<"CANT. UNIDADES: "<< cantidadUnidadesDetalle<<endl;
    cout<<"PRECIO UNITARIO: $"<< precioUnitarioDetalle<<endl;
    cout<<"SUBTOTAL: $"<< subTotalDetalle<<endl;
}

void DetalleCompras::set_idCompraDetalle(int id_compra){

    idCompraDetalle = id_compra;
}

void DetalleCompras::set_idProductoDetalle(int id_producto){

    idProductoDetalle = id_producto;
}

void DetalleCompras::set_cantidadUnidadesDetalle(int cantidad_elegida){

    cantidadUnidadesDetalle = cantidad_elegida;
}

void DetalleCompras::set_precioUnitarioDetalle(float precio_unitario){

    precioUnitarioDetalle = precio_unitario;
}

void DetalleCompras::set_subTotalDetalle(float sub_precio_unitario, int sub_cantidad_elegida){

    float subTotalCalculado = sub_precio_unitario * sub_cantidad_elegida;

    subTotalDetalle = subTotalCalculado;
}

int DetalleCompras::get_idCompraDetalle(){

    return idCompraDetalle;
}

int DetalleCompras::get_idProductoDetalle(){

    return idProductoDetalle;
}

int DetalleCompras::get_cantidadUnidadesDetalle(){

    return cantidadUnidadesDetalle;
}

float DetalleCompras::get_precioUnitarioDetalle(){

    return precioUnitarioDetalle;
}

float DetalleCompras::get_subTotalDetalle(){

    return subTotalDetalle;
}



