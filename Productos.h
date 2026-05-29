#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

class Productos{

    private:
        int idProducto;
        char nombreProducto [50];
        float precioProducto;
        char categoriaProducto [20]; ///(cafetería, pastelería o bebidas)
        char tamanioProducto [15];    ///(pequeño, mediano o grande)
        int stockProducto;
        bool estadoProducto;

    public:
        void cargar();
        void mostrar();

        void set_idProducto(int);
        void set_nombreProducto(char nombre[]);
        void set_precioProducto(float);
        void set_categoriaProducto(char);
        void set_tamanioProducto(char);
        void set_stockProducto(int);
        void set_estadoProducto(bool);

        int get_idProducto();
        char* get_nombreProducto();
        float get_precioProducto();
        char* get_categoriaProducto();
        char* get_tamanioProducto();
        int get_stockProducto();
        bool get_estadoProducto();


        void hayStock();
        void aumentarStock();
        void descontarStock();
        void stockBajo();

        void darAlta();
        void darBaja();
};

#endif // PRODUCTOS_H_INCLUDED
