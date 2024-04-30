#include <stdio.h>
#include "eje2.h"
#include <assert.h>

void test_digitoEnNumero()
{
  bool result = digitoEnNumero(123, 3);
  assert(result == true);

  result = digitoEnNumero(123, 4);
  assert(result == false);
}

int main()
{
    test_digitoEnNumero();  
    return 0;
}
