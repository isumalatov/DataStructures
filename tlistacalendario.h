#ifndef TLISTACALENDARIO_H
#define TLISTACALENDARIO_H

#include "tnodocalendario.h"
#include "tlistapos.h"
#include <iostream>

using namespace std;

class TListaCalendario {
    friend ostream & operator<<(ostream &, TListaCalendario &);
    
    private:
        TNodoCalendario *primero;
    
    public:
        TListaCalendario();
        TListaCalendario(const TListaCalendario &);
        ~TListaCalendario();
        TListaCalendario & operator=(const TListaCalendario &);
        bool operator==(const TListaCalendario &);
        TListaCalendario operator+(const TListaCalendario &);
        TListaCalendario operator-(const TListaCalendario &);
        bool Insertar(const TCalendario &);
        bool Borrar(const TCalendario &);
        bool Borrar(const TListaPos &);
        bool Borrar(int, int, int);
        bool EsVacia();
        TCalendario Obtener(const TListaPos &);
        bool Buscar(const TCalendario &);
        int Longitud();
        TListaPos Primera();
        TListaPos Ultima();
        TListaCalendario SumarSubl(int, int, TListaCalendario &, int, int);
        TListaCalendario ExtraerRango(int, int);
};

#endif