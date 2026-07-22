#include <iostream>
#include <cstring>
#include <cctype>
#include "Compras.h"
#include "Fecha.h"
using namespace std;

void Compras::mostrar(){

    cout<<"ID COMPRA: "<<idCompra<<endl;
    cout<<"ID PROVEEDOR: "<<idProveedorCompra<<endl;
    cout<<"TOTAL: $"<<totalCompra<<endl;
    fechaCompra.Mostrar();
}

void Compras::set_idCompra(int idCompraEnviado){

    if(idCompraEnviado > 0){

        idCompra = idCompraEnviado;
    }
}

void Compras::set_idProveedorCompra(int idProveedorEnviado){

    if(idProveedorEnviado >= 0 ){

        idProveedorCompra = idProveedorEnviado;
    }
}

void Compras::set_fechaCompra(Fecha fecha){

    fechaCompra = fecha;
}

void Compras::set_totalCompra(float totalCompraCalculado){

    if(totalCompraCalculado > 0){

        totalCompra = totalCompraCalculado;
    }
}

int Compras::get_idCompra(){

    return idCompra;
}

int Compras::get_idProveedorCompra(){

    return idProveedorCompra;
}

Fecha Compras::get_fechaCompra(){

    return fechaCompra;
}

float Compras::get_totalCompra(){

    return totalCompra;
}



