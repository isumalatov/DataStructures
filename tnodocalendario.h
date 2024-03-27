#ifndef TNODOCALENDARIO_H
#define TNODOCALENDARIO_H

#include "tcalendario.h"
#include <iostream>

using namespace std;

class TNodoCalendario {
    friend ostream & operator<<(ostream &, TNodoCalendario &);
    
    private:
        TCalendario c;
        TNodoCalendario *siguiente;
    
    public:
        TNodoCalendario();
        TNodoCalendario(const TNodoCalendario &);
        ~TNodoCalendario();
        TNodoCalendario & operator=(const TNodoCalendario &);
};

#endif