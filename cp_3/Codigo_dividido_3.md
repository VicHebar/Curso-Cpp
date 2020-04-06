# Tercera parte

La tercera parte ser� la �ltima parte en la que trataremos la separaci�n de codigo, no porque ya no haya m�s que hablar al respecto, sino, porque ser� hasta este momento todo lo que requeriremos para este curso.  
Con lo visto hasta el momento hemos podido corroborar las ventajas de dividir c�digo en distintos m�dulos, pondremos a prueba esto ahora con las clases.

# Dividir codigo de clases

Nuestra pr�xima aproximaci�n a la divisi�n de c�digo ser� a trav�s de las clases, reiterando que la utilidad de dividir c�digo es la ventaja de no compilar c�digo que no se ha modificado. Retomaremos nuestro ejemplo de los n�meros racionales, ya teniendo este c�digo dividido dentro de un mismo archivo nuestro siguiente paso ser� poner este c�digo en distintos m�dulos. Recordando nustro c�digo tennemos las siguientes l�neas:  
~~~ c++
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
  rational a(2,4);
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
~~~
Partiremos este m�dulo en 3 archivos m�s y, de igual manera que con las funciones del ejemplo anterior, estos archivos ser�n **main**, **header** y **source code** de las funciones.

### Main

mainRational.cpp:  
~~~ c++
#include "../includes/rational.h"

int main ()
{
  rational a(2,4);
  rational b = a.reduce();
  b.imprime();
  return 0;
}
~~~

### Header

rational.h:  
~~~ c++
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
~~~

### Source code

rational.cpp:  
~~~ c++
#include "../includes/rational.h"
#include <iostream>

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
~~~

A pesar de lo que podr�an estar pensando no es necesario dar una explicaci�n de lo que est� pasando aqu�, ya que simplemente hemos repetido el proceso de las funciones con las declaraciones de la clase.  
El makefile para su compilaci�n ser� el siguiente:  
~~~ makefile
bin/main: src/mainRational.cpp src/rational.cpp
    g++ -o bin/main src/mainRational.cpp bin/rational.o

bin/rational.o: src/rational.cpp
    g++ -o bin/rational.o -c src/rational.cpp
    
exec:
    bin/main
~~~
