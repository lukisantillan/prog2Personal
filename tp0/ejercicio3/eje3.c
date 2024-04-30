#include <math.h>
#include "eje3.h"

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p){
    float distancia = sqrt(pow(p.x-centroC.x,2) + pow(p.y-centroC.y,2));
    if (distancia == rc)
    {
        return EN_CIRCUNFERENCIA;
    } else if (distancia < rc)
    {
        return INTERNO;
    } else return EXTERNO;
}
