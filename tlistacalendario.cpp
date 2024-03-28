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
}

bool TListaPos::operator==(const TListaPos &l) {
    return pos == l.pos;
}

bool TListaPos::operator!=(const TListaPos &l) {
    return pos != l.pos;
}

TListaPos TListaPos::Siguiente() {
    TListaPos l;
    if (pos != NULL) {
        l.pos = pos->siguiente;
    }
    return l;
}

bool TListaPos::EsVacia() {
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

bool TListaCalendario::operator==(const TListaCalendario &l) {
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

TListaCalendario TListaCalendario::operator+(const TListaCalendario &l) {
    TListaCalendario aux(*this);
    TNodoCalendario *n = l.primero;
    while (n != NULL) {
        aux.Insertar(n->c);
        n = n->siguiente;
    }
    return aux;
}

TListaCalendario TListaCalendario::operator-(const TListaCalendario &l) {
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

bool TListaCalendario::Borrar(const TCalendario &c) {
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

bool TListaCalendario::EsVacia() {
    return primero == NULL;
}

TCalendario TListaCalendario::Obtener(const TListaPos &p) {
    return p.pos->c;
}

bool TListaCalendario::Buscar(const TCalendario &c) {
    TNodoCalendario *n = primero;
    while (n != NULL && n->c != c) {
        n = n->siguiente;
    }
    return n != NULL;
}

int TListaCalendario::Longitud() {
    int l = 0;
    TNodoCalendario *n = primero;
    while (n != NULL) {
        l++;
        n = n->siguiente;
    }
    return l;
}

TListaPos TListaCalendario::Primera() {
    TListaPos p;
    p.pos = primero;
    return p;
}

TListaPos TListaCalendario::Ultima() {
    TListaPos p;
    TNodoCalendario *n = primero;
    while (n != NULL && n->siguiente != NULL) {
        n = n->siguiente;
    }
    p.pos = n;
    return p;
}

TListaCalendario TListaCalendario::SumarSubl(int i, int j, TListaCalendario &l, int k, int m) {
    TListaCalendario aux;
    TNodoCalendario *n = primero;
    int c = 1;
    while (n != NULL && c < i) {
        n = n->siguiente;
        c++;
    }
    while (n != NULL && c <= j) {
        aux.Insertar(n->c);
        n = n->siguiente;
        c++;
    }
    TNodoCalendario *m = l.primero;
    c = 1;
    while (m != NULL && c < k) {
        m = m->siguiente;
        c++;
    }
    while (m != NULL && c <= m) {
        aux.Insertar(m->c);
        m = m->siguiente;
        c++;
    }
    return aux;
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











