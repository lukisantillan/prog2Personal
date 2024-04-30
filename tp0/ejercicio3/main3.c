#include <stdio.h>
#include "eje3.h"
#include <assert.h>

void test_dondeEstaElPuntoBis()
{
  struct Punto centroC = {0, 0};
  struct Punto p = {2, 2};
  enum Referencia result = dondeEstaElPuntoBis(centroC, 5, p);
  assert(result == INTERNO);

  p.x = 5;
  p.y = 0;
  result = dondeEstaElPuntoBis(centroC, 5, p);
  assert(result == EN_CIRCUNFERENCIA);

  p.x = 8;
  p.y = 8;
  result = dondeEstaElPuntoBis(centroC, 5, p);
  assert(result == EXTERNO);
}

int main()
{
    test_dondeEstaElPuntoBis();
    return 0;
}
