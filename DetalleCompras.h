#ifndef DETALLECOMPRAS_H_INCLUDED
#define DETALLECOMPRAS_H_INCLUDED

class DetalleCompras{

    private:
        int idCompraDetalle;
        int idProductoDetalle;
        int cantidadUnidadesDetalle;
        float precioUnitarioDetalle;
        float subTotalDetalle;

    public:
        void mostrar();

        void set_idCompraDetalle(int id_compra);
        void set_idProductoDetalle(int id_producto);
        void set_cantidadUnidadesDetalle(int cantidad_elegida);
        void set_precioUnitarioDetalle(float precio_unitario);
        void set_subTotalDetalle(float sub_precio_unitario, int sub_cantidad_elegida);

        int get_idCompraDetalle();
        int get_idProductoDetalle();
        int get_cantidadUnidadesDetalle();
        float get_precioUnitarioDetalle();
        float get_subTotalDetalle();


};




#endif // DETALLECOMPRAS_H_INCLUDED
