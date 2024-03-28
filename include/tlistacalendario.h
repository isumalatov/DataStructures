#ifndef TLISTACALENDARIO_H
#define TLISTACALENDARIO_H

#include "tvectorcalendario.h"
#include "tcalendario.h"
#include <iostream>
#include <string.h>

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
        bool operator==(TListaCalendario &);
        TListaCalendario operator+(TListaCalendario &);
        TListaCalendario operator-(TListaCalendario &);
        bool Insertar(const TCalendario &);
        bool Borrar(TCalendario &);
        bool Borrar(const TListaPos &);
        bool Borrar(int, int, int);
        bool EsVacia() const;
        TCalendario Obtener(const TListaPos &) const;
        bool Buscar(TCalendario &) const;
        int Longitud() const;
        TListaPos Primera() const;
        TListaPos Ultima()const;
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
        bool operator==(const TListaPos &) const;
        bool operator!=(const TListaPos &) const;
        TListaPos Siguiente() const;
        bool EsVacia() const;
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