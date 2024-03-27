#ifndef TLISTAPOS_H
#define TLISTAPOS_H

#include "tnodocalendario.h"
#include <iostream>

using namespace std;

class TListaPos {
    friend ostream & operator<<(ostream &, TListaPos &);
    
    private:
        TNodoCalendario *pos;
    
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

#endif