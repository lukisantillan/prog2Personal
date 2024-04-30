#include <stdio.h>
#include "eje1.h"
#include <assert.h>

void test_dondeEstaElPunto()
{
  enum Referencia result = dondeEstaElPunto(0, 0, 5, 2, 2);
  assert(result == INTERNO);

  result = dondeEstaElPunto(0, 0, 5, 5, 0);
  assert(result == EN_CIRCUNFERENCIA);

  result = dondeEstaElPunto(0, 0, 5, 8, 8);
  assert(result == EXTERNO);
}

int main()
{
    test_dondeEstaElPunto();
    
    return 0;
}