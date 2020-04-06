#include "../includes/rational.h"

int main ()
{
  rational a(2,4);
  rational b = a.reduce();
  b.imprime();
  return 0;
}
