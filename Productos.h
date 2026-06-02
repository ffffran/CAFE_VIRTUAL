#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

class Productos{

    private:
        int idProducto;
        char nombreProducto [50];
        float precioProducto;
        char categoriaProducto;  ///(c = cafetería, p = pastelería o b = bebidas)
        char tamanioProducto;    ///(p = pequeño, m = mediano o g = grande)
        int stockProducto;
        bool estadoProducto;
        int stockMinimo;

    public:
        void cargar();
        void mostrar();

        void set_idProducto(int);
        void set_nombreProducto(char nombre[]);
        void set_precioProducto(float);
        void set_categoriaProducto(char categoria);
        void set_tamanioProducto(char tamanio);
        void set_stockProducto(int);
        void set_estadoProducto(bool);
        void set_stockMinimo(int);

        int get_idProducto();
        char* get_nombreProducto();
        float get_precioProducto();
        char get_categoriaProducto();
        char get_tamanioProducto();
        int get_stockProducto();
        bool get_estadoProducto();
        int get_stockMinimo();


        bool hayStock();
        void aumentarStock(int compra);
        void descontarStock(int venta);
        bool stockBajo();

        void darAlta();
        void darBaja();
};

#endif // PRODUCTOS_H_INCLUDED
