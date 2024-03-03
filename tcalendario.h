#ifndef TCALENDARIO_H
#define TCALENDARIO_H

#include <iostream>

using namespace std;

class TCalendario {
    friend ostream & operator<<(ostream &, TCalendario &);
    
    private:
        int dia, mes, anyo;
        char* mensaje;
        int daysInMonth(int, int);
        void copia(const TCalendario &c);

    public:
        TCalendario();
        TCalendario(int dia, int mes, int anyo, char * mens);
        TCalendario(const TCalendario &); 
        ~TCalendario();
        TCalendario & operator=(const TCalendario &);
        TCalendario operator+(int); 
        TCalendario operator-(int); 
        TCalendario operator++(int); 
        TCalendario & operator++(); 
        TCalendario operator--(int); 
        TCalendario & operator--();
        bool ModFecha(int, int, int); 
        bool ModMensaje(char *);
        bool operator==(TCalendario &);
        bool operator!=(TCalendario &);
        bool operator>(TCalendario &); 
        bool operator<(TCalendario &);
        bool EsVacio();
        int Dia();
        int Mes();
        int Anyo();
        char * Mensaje();
};

#endif