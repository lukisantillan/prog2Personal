#include <stdbool.h>
#include <stdio.h>
//Ejercicio1

enum Referencia
{
    INTERNO = -1,
    EN_CIRCUNFERENCIA,
    EXTERNO
};

enum Referencia dondeEstaElPunto(int xc, int yc, int xp, int yp, int rc);