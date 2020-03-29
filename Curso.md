# Codigo dividido

Esta va a ser una peque�a gu�a sobre lo que es el codigo dividido, la idea es que ustedes puedan entender las utillidades de partir c�dgo en partes para mantener sus scripts m�s ordenados.

1. 

## Prototipo implementaci�n.

La estructura de un programa usal en C/C++ est� formado por **directivas de preprocesador**, **declaracion de variables globales**, **prototipos de funciones**, **funci�n main** y **definici�n de funciones**. Y se ve de la siguiente manera:  
~~~ c++
#include <some_include.h>
...
#include <other_includes.h>
#define some_define some_value
...
#define other_define other_value

int variable;
double other_variable;

void function(int, double, bool);
int other_function(double, bool, float);

int main()
{
  //Definici�n del main
  return 0;
}

void function(int a, double b, bool c)
{
  //Definicion de la funcion
}

int other_function(double a, bool b, float c)
{
  //Definicion de funcion
  return some_int_value
}
~~~
La idea de tener un prototipo y una definici�n por separado es mantemer un codigo m�s ordenado y poder tener un indice de las funciones que se enlistan en el programa.  
Un prototipo de funci�n le da informaci�n importante al compilador. En el prototipo se indican el tipo de dato que retorna la funci�n, el n�mero, tipo y orden de par�metros que recibe la misma. El compilador utiliza los prototipos para verificar las llamadas a funciones. Antes el prototipado no exist�a y el compilador no pod�a detectar ciertos errores.

## Clase con definiciones externas

Lo primero que haremos ser� declarar una clase simple que unicamente nos servir� para ejemplificar el punto de este cap�tulo, esta clase la llamaremos rational, dicha clase nos permitir� crear numeros racionales y operar con ellos. La definici�n ser� la siguiente:  
~~~ c++
#include <iostream>

using namespace std;
  
class rational
{
  int p;
  int q;
    
public:
  rational()
  {
    p = 0;
    q = 1;
  }
  rational(int p, int q)
  {
    this -> p = p;
    this -> q = q;
  }
  rational(const rational &a) = default;
  int getP()
  {
    return p;
  }
  int getQ()
  {
    return q;
  }
  void setP(int p)
  {
    this -> p = p;
  }
  void setQ(int q)
  {
    this -> q = q;
  }
  void imprime()
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

};
int main()
{
  system("pause");
  return 0;
}
~~~
Como podemos ver es una clase muy sencilla que unicamente genera numeros racionales y nos permite reducirlos. En esta clase estamos declarando los m�todos de la clase dentro de la misma clase, lo que causa que sea dificil de leer un codigo completo, para solucionarlo sepraremos el prototipo de la implementaci�n.  
Al igual que las funciones normales, C++ nos permite crear un prototipo de los m�todos de una clase para poder hacer sus definiciones en otra parte del c�digo, la manera de hacerlo es la siguiente.  
Dividiremos el c�digo en tres partes, la primera de ellas ser� la **definici�n de la clase**, en ella encontraremos los prototipos de los m�todos as� como sus atributos, la segunda ser� **el main** donde podremos hacer las llamadas de todas estas funciones y clases, y la tercera ser� la **definici� de los m�todos** de la clase.  
#### Definici�n de clase

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
~~~
Aqu� simplemente hacemos la definicion de la clase incluyendo los prototipos de los m�todos y los atributos con los que contar� la clase.

#### Main

~~~ c++
int main ()
{
  rational a(2,4);
  rational b = a.reduce();
  b.imprime();
  return 0;
}
~~~
En esta parte del codigo estamos crando un racional ```a``` que ser� el correspondiente con 2/4, posteriormente creamos otro racional ```b``` como la version reducida del racional ```a```, esto unicamente con fines ilustrativos de los alcances de nuestra prematura clase.

#### Definici�n de los m�todos.

~~~ c++
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
Aqu� hemos de remarcar la sintaxis con la que est�n escritas las definiciones, para las funciones metodo se utiliza la sintxis ```tipo_de_retorno clase_padre::nombre_del_del_metodo(valores_de_entrada)```, notese el uso del operador de acceso **::** para especificar que es un metodo de la clase rational, esto dado que se est� declarando fuera de de la clase y ya que la clase no pertenece a ningun espacio de nombres es necesario usar dicho operador de acceso y por otra parte aclarar que *clase_padre* se refiere a la clase a la cual el metodo pertenece. Para la definicion de los constructores la sintaxis es similar, siendo ````clase_padre::clase_padre(parametros_del_constructor)```.  
Como resultado final nuestro programa quedar� de la siguiente manera:  
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
Hasta este punto pueden encontrar el programa en cuesti�n en la carpeta **cp_1** con su respectivo archivo make, con las instrucciones para su compilaci�n.
