#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED
#include "Fecha.h"

class Ventas{

    private:
        int idVenta;
        int idClienteVenta;
        Fecha fechaVenta;
        int metodoPagoVenta; /// 1: EFECTIVO | 2: DEBITO | 3: CREDITO
        float totalVenta;

    public:
        void mostrar();

        void set_idVenta(int);
        void set_idClienteVenta(int);
        void set_fechaVenta(Fecha);
        void set_metodoPagoVenta(int);
        void set_totalVenta(float);

        int get_idVenta();
        int get_idClienteVenta();
        Fecha get_fechaVenta();
        int get_metodoPagoVenta();
        float get_totalVenta();
};

#endif // VENTAS_H_INCLUDED
