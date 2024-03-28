#ifndef TLISTACALENDARIO_H
#define TLISTACALENDARIO_H

#include "tvectorcalendario.h"
#include <iostream>

using namespace std;
class TNodoCalendario;
class TListaPos;
class TListaCalendario {
    friend ostream & operator<<(ostream &, TListaCalendario &);
    
    private:
        TNodoCalendario *primero;
        void copia(const TListaCalendario &);
    
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

class TListaPos {    
    friend class TListaCalendario;
    private:
        TNodoCalendario *pos;
        void copia(const TListaPos &);
    
    public:
        TListaPos();
        TListaPos(const TListaPos &);
        ~TListaPos();
        TListaPos & operator=(const TListaPos &);
        bool operator==(const TListaPos &);
        bool operator!=(const TListaPos &);
        TListaPos Siguiente();
        bool EsVacia();
};

class TNodoCalendario {  
    friend class TListaCalendario;
    friend class TListaPos;  
    private:
        TCalendario c;
        TNodoCalendario *siguiente;
        void copia(const TNodoCalendario &);
    
    public:
        TNodoCalendario();
        TNodoCalendario(const TNodoCalendario &);
        ~TNodoCalendario();
        TNodoCalendario & operator=(const TNodoCalendario &);
};

#endif