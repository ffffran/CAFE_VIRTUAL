#ifndef DETALLEVENTAS_H_INCLUDED
#define DETALLEVENTAS_H_INCLUDED

class DetalleVentas{

    private:
        int idVentaDetalle;
        int idProductoDetalle;
        int cantidadUnidadesDetalle;
        float precioUnitarioDetalle;
        float subTotalDetalle;

    public:
        void mostrar();

        void set_idVentaDetalle(int id_venta);
        void set_idProductoDetalle(int id_producto);
        void set_cantidadUnidadesDetalle(int cantidad_elegida);
        void set_precioUnitarioDetalle(float precio_unitario);
        void set_subTotalDetalle(float sub_precio_unitario, int sub_cantidad_elegida);

        int get_idVentaDetalle();
        int get_idProductoDetalle();
        int get_cantidadUnidadesDetalle();
        float get_precioUnitarioDetalle();
        float get_subTotalDetalle();
};

#endif // DETALLEVENTAS_H_INCLUDED
