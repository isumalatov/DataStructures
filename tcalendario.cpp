#include "tcalendario.h"

int
TCalendario::daysInMonth(int m, int a) {
    int days;
    switch (m) {
        case 2:
            if (a % 4 == 0 && (a % 100 != 0 || a % 400 == 0)) {
                days = 29;
            } else {
                days = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        default:
            days = 31;
            break;
    }
    return days;
}

TCalendario::TCalendario() {
    dia = 1;
    mes = 1;
    anyo = 1900;
    mensaje = NULL;
}

TCalendario::TCalendario(int d, int m, int a, char * mens) {
    // Check if the date is correct
    if (a < 1900 || m < 1 || m > 12 || d < 1 || d > daysInMonth(m, a)) {
        // If the date is incorrect, initialize to 1/1/1900 and set mensaje to NULL
        dia = 1;
        mes = 1;
        anyo = 1900;
        mensaje = NULL;
    } else {
        dia = d;
        mes = m;
        anyo = a;
        mensaje = mens;
    }
}

TCalendario::TCalendario(const TCalendario &c) {
    dia = c.dia;
    mes = c.mes;
    anyo = c.anyo;
    if (c.mensaje != NULL) {
        mensaje = new char[strlen(c.mensaje) + 1];
        strcpy(mensaje, c.mensaje);
    } else {
        mensaje = NULL;
    }
}

TCalendario::~TCalendario() {
    dia = 1;
    mes = 1;
    anyo = 1900;
    if (mensaje != NULL) {
        delete[] mensaje;
        mensaje = NULL;
    }
}

TCalendario & TCalendario::operator=(const TCalendario &c) {
    if (this != &c) { // Protección contra autoasignación
        dia = c.dia;
        mes = c.mes;
        anyo = c.anyo;
        delete[] mensaje; // Liberar la memoria antigua
        if (c.mensaje != NULL) {
            mensaje = new char[strlen(c.mensaje) + 1];
            strcpy(mensaje, c.mensaje);
        } else {
            mensaje = NULL;
        }
    }
    return *this; // Devolver una referencia a este objeto
}