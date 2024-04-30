#include <stdbool.h>
#include <stdio.h>

enum Referencia
{
    INTERNO = -1,
    EN_CIRCUNFERENCIA,
    EXTERNO
};

struct Punto {
    int x, y;
};

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p);