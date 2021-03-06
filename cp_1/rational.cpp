#include <iostream>

using namespace std;
  
class rational
{
  int p;
  int q;
    
public:
  rational();
  rational(int, int);
  rational(const rational &);
  int getP();
  int getQ();
  void setP(int);
  void setQ(int);
  void imprime();
  rational reduce();
};

int main ()
{
  rational a(9,3);
  rational b = a.reduce();
  b.imprime();
  return 0;
}

rational::rational()
{
  p = 0;
  q = 1;
}
rational::rational(int p, int q)
{
  this -> p = p;
  this -> q = q;
}
rational::rational(const rational &r) = default;
int rational::getP()
{
  return p;
}
int rational::getQ()
{
  return q;
}
void rational::setP(int p)
{
  this -> p = p;
}
void rational::setQ(int q)
{
  this -> q = q;
}
void rational::imprime()
{
  cout << p << "/" << q;
}
rational rational::reduce ()
{
  int q_ = q;
  int p_ = p;
  int i;
  if(p_ > q_)
    i = q_;
  else
    i = p_;
  while(i > 0)
  {
    if(q_%i == 0)
    {
      if(p_%i == 0)
      {
        p_ /= i;
        q_ /= i;
        if(p_ > q_)
          i = q_;
        else
          i = p_;
        i--;
      }
    }
    else
    {
      i--;
    }
  }
  return rational(p_, q_);
}
