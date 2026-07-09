#ifndef PROVEEDORES_H_INCLUDED
#define PROVEEDORES_H_INCLUDED

class Proveedores{

private:
    int idProveedor;
    char rubroEmpresa[55];
    char nombreEmpresa[60];
    char paisEmpresa[40];
    char telefonoEmpresa[20];
    char locacionEmpresa[40];
    bool estadoProveedor;

public:
    void cargar();
    void mostrar();

    void set_idProveedor(int);
    void set_rubroEmpresa(char[]);
    void set_nombreEmpresa(char[]);
    void set_paisEmpresa(char[]);
    void set_telefonoEmpresa(char[]);
    void set_locacionEmpresa(char[]);
    void set_estadoProveedor(bool);

    int get_idProveedor();
    char* get_rubroEmpresa();
    char* get_nombreEmpresa();
    char* get_paisEmpresa();
    char* get_telefonoEmpresa();
    char* get_locacionEmpresa();
    bool get_estadoProveedor();

    void darAlta();
    void darBaja();
};

#endif // PROVEEDORES_H_INCLUDED

