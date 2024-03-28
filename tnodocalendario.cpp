#include "tnodocalendario.h"

void TNodoCalendario::copia(const TNodoCalendario &n) {
    c = n.c;
    siguiente = n.siguiente;
}

TNodoCalendario::TNodoCalendario() {
    siguiente = NULL;
}

TNodoCalendario::TNodoCalendario(const TNodoCalendario &n) {
    copia(n);
}

TNodoCalendario::~TNodoCalendario() {
    c.~TCalendario();
    siguiente = NULL;
}

TNodoCalendario & TNodoCalendario::operator=(const TNodoCalendario &n) {
    if (this != &n) {
        this->~TNodoCalendario();
        copia(n);
    }
    return *this;
}



