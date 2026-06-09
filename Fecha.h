#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{

    private:
        int dia;
        int mes;
        int anio;

    public:

        Fecha(int d=1, int m=1, int a=1900);

        void Cargar();
        void Mostrar();

        void set_dia(int);
        void set_mes(int);
        void set_anio(int);

        int get_dia();
        int get_mes();
        int get_anio();
};

#endif // CLSFECHA_H_INCLUDED
