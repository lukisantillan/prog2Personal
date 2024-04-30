#include <math.h>
#include "eje1.h"
enum Referencia dondeEstaElPunto(int xc, int yc, int rc,int xp,int yp) {
    float distancia = sqrt(pow(xp-xc,2) + pow(yp-yc,2));
    if (distancia == rc)
    {
        return EN_CIRCUNFERENCIA;
    } else if (distancia < rc)
    {
        return INTERNO;
    } else {return EXTERNO;}
}