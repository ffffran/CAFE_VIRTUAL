#include <iostream>
#include "Fecha.h"

using namespace std;

Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::Cargar(){

    int diaIngresado;

    cout<<"Ingrese día: ";
    cin>> diaIngresado;
    set_dia(diaIngresado);
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio;
}

void Fecha::set_dia(int d){
    dia = d;
}

void Fecha::set_mes(int m){

}

void Fecha::set_anio(int a){

}

int Fecha::get_dia(){
    return dia;
}

int Fecha::get_mes(){
    return mes;
}

int Fecha::get_anio(){
    return anio;
}

