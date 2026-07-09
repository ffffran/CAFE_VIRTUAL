#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

class Clientes{

    private:
        int idCliente;
        char nombreCliente[40];
        bool miembroCliente;
        int dniCliente;
        char telefonoCliente[20];
        char mailCliente[60];
        bool estadoCliente;

    public:
        void cargar();
        void mostrar();

        void set_idCliente(int);
        void set_nombreCliente(char nombre[]);
        void set_miembroCliente(bool);
        void set_dniCliente(int);
        void set_telefonoCliente(char telefono[]);
        void set_mailCliente(char mail[]);
        void set_estadoCliente(bool);

        int get_idCliente();
        char* get_nombreCliente();
        bool get_miembroCliente();
        int get_dni();
        char* get_telefonoCliente();
        char* get_mailCliente();
        bool get_estadoCliente();

        void darAlta();
        void darBaja();
};


#endif // CLIENTES_H_INCLUDED
