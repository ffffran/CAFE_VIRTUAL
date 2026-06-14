#ifndef COMPRAS_H_INCLUDED
#define COMPRAS_H_INCLUDED

class Compras{

    private:
        int idCompra;
        int idProveedorCompra;
        ///Fecha fechaVenta;
        float totalCompra;

    public:
        void mostrar();

        void set_idCompra(int id);
        void set_idProveedorCompra(int id);
        ///void set_fechaVenta();
        void set_totalCompra(float total);

        int get_idCompra();
        int get_idProveedorCompra();
        ///fecha get_fechaVenta();
        float get_totalCompra();
};




#endif // COMPRAS_H_INCLUDED
