#include "tlistacalendario.h"

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

void TListaPos::copia(const TListaPos &l) {
    pos = l.pos;
}

TListaPos::TListaPos() {
    pos = NULL;
}

TListaPos::TListaPos(const TListaPos &l) {
    copia(l);
}

TListaPos::~TListaPos() {
    pos = NULL;
}

TListaPos & TListaPos::operator=(const TListaPos &l) {
    if (this != &l) {
        this->~TListaPos();
        copia(l);
    }
    return *this;
}

bool TListaPos::operator==(const TListaPos &l) const{
    return pos == l.pos;
}

bool TListaPos::operator!=(const TListaPos &l) const{
    return pos != l.pos;
}

TListaPos TListaPos::Siguiente() const{
    TListaPos l;
    if (pos != NULL) {
        l.pos = pos->siguiente;
    }
    return l;
}

bool TListaPos::EsVacia() const{
    return pos == NULL;
}

void TListaCalendario::copia(const TListaCalendario &l) {
    TNodoCalendario *n = l.primero;
    TNodoCalendario *p = NULL;
    while (n != NULL) {
        TNodoCalendario *aux = new TNodoCalendario();
        aux->c = n->c;
        if (p == NULL) {
            primero = aux;
        } else {
            p->siguiente = aux;
        }
        p = aux;
        n = n->siguiente;
    }
}

TListaCalendario::TListaCalendario() {
    primero = NULL;
}

TListaCalendario::TListaCalendario(const TListaCalendario &l) {
    copia(l);
}

TListaCalendario::~TListaCalendario() {
    TNodoCalendario *n = primero;
    while (n != NULL) {
        TNodoCalendario *aux = n;
        n = n->siguiente;
        delete aux;
    }
    primero = NULL;
}

TListaCalendario & TListaCalendario::operator=(const TListaCalendario &l) {
    if (this != &l) {
        this->~TListaCalendario();
        copia(l);
    }
    return *this;
}

bool TListaCalendario::operator==(TListaCalendario &l) {
    TNodoCalendario *n = primero;
    TNodoCalendario *m = l.primero;
    while (n != NULL && m != NULL) {
        if (n->c != m->c) {
            return false;
        }
        n = n->siguiente;
        m = m->siguiente;
    }
    return n == NULL && m == NULL;
}

TListaCalendario TListaCalendario::operator+(TListaCalendario &l) {
    TListaCalendario aux(*this);
    TNodoCalendario *n = l.primero;
    while (n != NULL) {
        aux.Insertar(n->c);
        n = n->siguiente;
    }
    return aux;
}

TListaCalendario TListaCalendario::operator-(TListaCalendario &l) {
    TListaCalendario aux(*this);
    TNodoCalendario *n = l.primero;
    while (n != NULL) {
        aux.Borrar(n->c);
        n = n->siguiente;
    }
    return aux;
}

bool TListaCalendario::Insertar(const TCalendario &c) {
    TNodoCalendario *n = new TNodoCalendario();
    n->c = c;
    if (primero == NULL) {
        primero = n;
    } else {
        TNodoCalendario *p = primero;
        while (p->siguiente != NULL) {
            p = p->siguiente;
        }
        p->siguiente = n;
    }
    return true;
}

bool TListaCalendario::Borrar(TCalendario &c) {
    TNodoCalendario *n = primero;
    TNodoCalendario *p = NULL;
    while (n != NULL && n->c != c) {
        p = n;
        n = n->siguiente;
    }
    if (n != NULL) {
        if (p == NULL) {
            primero = n->siguiente;
        } else {
            p->siguiente = n->siguiente;
        }
        delete n;
        return true;
    }
    return false;
}

bool TListaCalendario::Borrar(const TListaPos &p) {
    TNodoCalendario *n = p.pos;
    TNodoCalendario *m = primero;
    TNodoCalendario *q = NULL;
    while (m != NULL && m != n) {
        q = m;
        m = m->siguiente;
    }
    if (m != NULL) {
        if (q == NULL) {
            primero = m->siguiente;
        } else {
            q->siguiente = m->siguiente;
        }
        delete m;
        return true;
    }
    return false;
}

bool TListaCalendario::Borrar(int d, int m, int a) {
    TCalendario c(d, m, a, NULL);
    return Borrar(c);
}

bool TListaCalendario::EsVacia() const{
    return primero == NULL;
}

TCalendario TListaCalendario::Obtener(const TListaPos &p) const{
    return p.pos->c;
}

bool TListaCalendario::Buscar(TCalendario &c) const{
    TNodoCalendario *n = primero;
    while (n != NULL && n->c != c) {
        n = n->siguiente;
    }
    return n != NULL;
}

int TListaCalendario::Longitud() const{
    int l = 0;
    TNodoCalendario *n = primero;
    while (n != NULL) {
        l++;
        n = n->siguiente;
    }
    return l;
}

TListaPos TListaCalendario::Primera() const{
    TListaPos p;
    p.pos = primero;
    return p;
}

TListaPos TListaCalendario::Ultima() const{
    TListaPos p;
    TNodoCalendario *n = primero;
    while (n != NULL && n->siguiente != NULL) {
        n = n->siguiente;
    }
    p.pos = n;
    return p;
}

TListaCalendario TListaCalendario::SumarSubl(int i, int j, TListaCalendario &l, int k, int m) {
    TListaCalendario l1, l2, l3;
    l1 = ExtraerRango(i, j);
    l2 = l.ExtraerRango(k, m);
    l3 = l1 + l2;
    return l3;
}

TListaCalendario TListaCalendario::ExtraerRango(int i, int j) {
    TListaCalendario aux;
    TNodoCalendario *n = primero;
    int c = 1;
    while (n != NULL && c < i) {
        n = n->siguiente;
        c++;
    }
    while (n != NULL && c <= j) {
        aux.Insertar(n->c);
        TNodoCalendario *m = n;
        n = n->siguiente;
        delete m;
        c++;
    }
    return aux;
}











