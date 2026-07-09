#include <iostream>
#include "Fecha.h"
#include <ctime>

using namespace std;

Fecha::Fecha(int d, int m, int a){
    dia = d;
    mes = m;
    anio = a;
}

void Fecha::Cargar(){

    time_t t = time(nullptr);
    tm *hoy = localtime(&t);

    dia = hoy->tm_mday;
    mes = hoy->tm_mon + 1;
    anio = hoy->tm_year + 1900;
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio;
}

void Fecha::set_dia(int d){

    if(d >= 1 && d <= 31){
        dia = d;
    }
}

void Fecha::set_mes(int m){

    if(m >= 1 && m <= 12){
        mes = m;
    }
}

void Fecha::set_anio(int a){

    if(a >= 1900){

        anio = a;
    }
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

