#ifndef TNODOCALENDARIO_H
#define TNODOCALENDARIO_H

#include "tcalendario.h"
#include <iostream>

using namespace std;

class TNodoCalendario {    
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