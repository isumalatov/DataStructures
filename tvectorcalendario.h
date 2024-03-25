#ifndef TVECTORCALENDARIO_H
#define TVECTORCALENDARIO_H

#include <iostream>
#include "tcalendario.h"

using namespace std;

class TVectorCalendario {
    friend ostream & operator<<(ostream &, TVectorCalendario &);
    
    private:
        TCalendario *c;
        int tamano;
        TCalendario error;
        int daysInMonth(int, int);
        void copia(const TVectorCalendario &);

    public:
        TVectorCalendario();
        TVectorCalendario(int tamaño);
        TVectorCalendario(const TVectorCalendario &);
        ~TVectorCalendario();
        TVectorCalendario & operator=(const TVectorCalendario &);
        bool operator==(const TVectorCalendario &);
        bool operator!=(const TVectorCalendario &);
        TCalendario & operator[](int);
        int Tamano();
        int Ocupadas();
        bool ExisteCal(TCalendario &);
        void MostrarMensajes(int, int, int);
        bool Redimensionar(int);
};

#endif
