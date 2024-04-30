#include <math.h>
#include "eje2.h"

bool digitoEnNumero(long n, short d)
{
  while (n > 0)
  {
    if (n % 10 == d)
    {
      return true;
    }
    n = n / 10;
  }
  return false;
}