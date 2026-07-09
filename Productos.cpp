#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include "Productos.h"
#include "ArchivoProductos.h"

using namespace std;

void Productos::cargar(){
    cin.ignore();
    char nombre [50];
    float precio;
    char categoria;  ///(c = cafetería, p = pastelería o b = bebidas)
    char tamanio;    ///(p = pequeño, m = mediano o g = grande)
    int stock;
    int stockMin;

    ArchivoProductos archivo;

    set_idProducto(archivo.Contar() + 1);

    cout<<"Alta de Productos - Nombre"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el nombre del producto: ";
    cin.getline(nombre,50);
    set_nombreProducto(nombre);

    system("cls");

    cout<<"Alta de Productos - Precio"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el precio del producto: $";
    cin>> precio;
    set_precioProducto(precio);

    system("cls");

    cout<<"Alta de Productos - Categoria"<<endl;
    cout<<"========================"<<endl;
    cout<<"IMPORTANTE!!: B (Bebida) | C (cafeteria) | P (pasteleria)"<<endl<<endl;
    cout<<"Ingrese la categoria del producto: ";
    cin>> categoria;

    set_categoriaProducto(categoria);

    system("cls");

    cout<<"Alta de Productos - Tamanio"<<endl;
    cout<<"========================"<<endl;
    cout<<"IMPORTANTE!!: P (Pequenio) | M (Mediano) | G (Grande)"<<endl<<endl;
    cout<<"Ingrese el tamanio del producto: ";
    cin>> tamanio;

    set_tamanioProducto(tamanio);

    system("cls");

    cout<<"Alta de Productos - Stock"<<endl;
    cout<<"========================"<<endl;
    cout<<"Ingrese el stock del producto: ";
    cin>> stock;
    set_stockProducto(stock);

    system("cls");

    cout<<"Alta de Productos - Stock Minimo"<<endl;
    cout<<"========================"<<endl;
    cout<<"Nota: Es el stock minimo antes de comprar para reponer"<<endl<<endl;
    cout<<"Ingrese el stock MINIMO del producto: ";
    cin>> stockMin;
    set_stockMinimo(stockMin);
}

void Productos::mostrar(){

    cout<<left;

    cout<<setw(6)<<idProducto;

    cout<<setw(35)<<nombreProducto;

    cout<<fixed<<setprecision(2);
    cout<<"$"<<setw(12)<<precioProducto;

    switch(categoriaProducto){

    case 'c':
        cout<<setw(15)<<"Cafeteria";
        break;

    case 'p':
        cout<<setw(15)<<"Pasteleria";
        break;

    case 'b':
        cout<<setw(15)<<"Bebidas";
        break;

    default:
        cout<<setw(15)<<"-";
    }

    switch(tamanioProducto){

    case 'p':
        cout<<setw(10)<<"Pequeño";
        break;

    case 'm':
        cout<<setw(10)<<"Mediano";
        break;

    case 'g':
        cout<<setw(10)<<"Grande";
        break;

    default:
        cout << setw(10) << "-";
    }

    cout<<setw(8)<<stockProducto;

    cout<<endl;
}

void Productos::set_idProducto(int idPorductoIngresado){

    if(idPorductoIngresado > 0){

        idProducto = idPorductoIngresado;
    }
}

void Productos::set_nombreProducto(char nombreIngresado[]){

    if(strlen(nombreIngresado) <= 50 && strlen(nombreIngresado) > 1){

        strcpy(nombreProducto, nombreIngresado);
    }

    for(int i = 0; nombreProducto[i] != '\0'; i ++){

        nombreProducto[i] = toupper(nombreProducto[i]);
    }
}

void Productos::set_precioProducto(float precioProductoIngresado){

    if(precioProductoIngresado > 0){

        precioProducto = precioProductoIngresado;
    }
}

void Productos::set_categoriaProducto(char categoriaProductoIngresado){

    categoriaProductoIngresado = toupper(categoriaProductoIngresado);

    if( categoriaProductoIngresado == 'B' || categoriaProductoIngresado == 'C' || categoriaProductoIngresado == 'P'){

        categoriaProducto = categoriaProductoIngresado;
    }
}

void Productos::set_tamanioProducto(char tamanioProductoIngresado){

    tamanioProductoIngresado = toupper(tamanioProductoIngresado);

    if( tamanioProductoIngresado == 'B' || tamanioProductoIngresado == 'C' || tamanioProductoIngresado == 'P'){

        tamanioProducto = tamanioProductoIngresado;
    }
}

void Productos::set_stockProducto(int stockIngresado){

    if(stockIngresado >= 0){

        stockProducto = stockIngresado;
    }
}

void Productos::set_estadoProducto(bool estadoIngresado){

    estadoIngresado = estadoProducto;
}

void Productos::set_stockMinimo(int stockMinimoIngresado){

    if(stockMinimoIngresado > 0){

        stockMinimo = stockMinimoIngresado;
    }
}

int Productos::get_idProducto(){

    return idProducto;
}

char* Productos::get_nombreProducto(){

    return nombreProducto;
}

float Productos::get_precioProducto(){

    return precioProducto;
}

char Productos::get_categoriaProducto(){

    return categoriaProducto;
}

char Productos::get_tamanioProducto(){

    return tamanioProducto;
}

int Productos::get_stockProducto(){

    return stockProducto;
}

bool Productos::get_estadoProducto(){

    return estadoProducto;
}

int Productos::get_stockMinimo(){

    return stockMinimo;
}

bool Productos::hayStock(){

    if(stockProducto > 0){

        return true;
    }
    else{

        return false;
    }
}

void Productos::aumentarStock(int compra){

    if(compra > 0){

        stockProducto += compra;
    }
}

void Productos::descontarStock(int venta){

    if(stockProducto > venta){

        stockProducto -= venta;
    }
}

bool Productos::stockBajo(){

    if(stockProducto <= stockMinimo){

        return true;
    }
    else{

        return false;
    }
}

void Productos::darAlta(){

    estadoProducto = true;
}

void Productos::darBaja(){

    estadoProducto = false;
}





