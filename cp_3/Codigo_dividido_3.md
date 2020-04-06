# Tercera parte

La tercera parte será la última parte en la que trataremos la separación de codigo, no porque ya no haya más que hablar al respecto, sino, porque será hasta este momento todo lo que requeriremos para este curso.  
Con lo visto hasta el momento hemos podido corroborar las ventajas de dividir código en distintos módulos, pondremos a prueba esto ahora con las clases.

# Dividir codigo de clases

Nuestra próxima aproximación a la división de código será a través de las clases, reiterando que la utilidad de dividir código es la ventaja de no compilar código que no se ha modificado. Retomaremos nuestro ejemplo de los números racionales, ya teniendo este código dividido dentro de un mismo archivo nuestro siguiente paso será poner este código en distintos módulos. Recordando nustro código tennemos las siguientes líneas:  
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
Partiremos este módulo en 3 archivos más y, de igual manera que con las funciones del ejemplo anterior, estos archivos serán **main**, **header** y **source code** de las funciones.

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

A pesar de lo que podrían estar pensando no es necesario dar una explicación de lo que está pasando aquí, ya que simplemente hemos repetido el proceso de las funciones con las declaraciones de la clase.  
El makefile para su compilación será el siguiente:  
~~~ makefile
bin/main: src/mainRational.cpp src/rational.cpp
    g++ -o bin/main src/mainRational.cpp bin/rational.o

bin/rational.o: src/rational.cpp
    g++ -o bin/rational.o -c src/rational.cpp
    
exec:
    bin/main
~~~
