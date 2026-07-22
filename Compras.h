#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED
#include "Fecha.h"

class Compras{

    private:
        int idCompra;
        int idProveedorCompra;
        Fecha fechaCompra;
        float totalCompra;

    public:
        void mostrar();

        void set_idCompra(int id);
        void set_idProveedorCompra(int id);
        void set_fechaCompra(Fecha);
        void set_totalCompra(float total);

        int get_idCompra();
        int get_idProveedorCompra();
        Fecha get_fechaCompra();
        float get_totalCompra();
};




#endif // COMPRAS_H_INCLUDED
