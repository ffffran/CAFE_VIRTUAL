#include <iostream>
#include <cstring>
#include "Productos.h"

using namespace std;

/// void Productos::cargar()

/// void Productos::mostrar()

void Productos::set_idProducto(int idP){

    if(idP > 0){

        idProducto = idP;
    }
}

void Productos::set_nombreProducto(char nombre[]){

    if(strlen(nombre) > 50 || strlen(nombre) < 1){
        strcpy(nombreProducto, nombre);

    }
}

void Productos::set_precioProducto(float pP){

    if(pP > 0){

        precioProducto = pP;
    }
}
