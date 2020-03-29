# Codigo dividido

Esta va a ser una pequeña guía sobre lo que es el codigo dividido, la idea es que ustedes puedan entender las utillidades de partir códgo en partes para mantener sus scripts más ordenados.

1. 

## Prototipo implementación.

La estructura de un programa usal en C/C++ está formado por **directivas de preprocesador**, **declaracion de variables globales**, **prototipos de funciones**, **función main** y **definición de funciones**. Y se ve de la siguiente manera:  
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
  //Definición del main
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
La idea de tener un prototipo y una definición por separado es mantemer un codigo más ordenado y poder tener un indice de las funciones que se enlistan en el programa.  
Un prototipo de función le da información importante al compilador. En el prototipo se indican el tipo de dato que retorna la función, el número, tipo y orden de parámetros que recibe la misma. El compilador utiliza los prototipos para verificar las llamadas a funciones. Antes el prototipado no existía y el compilador no podía detectar ciertos errores.

## Clase con definiciones externas

Lo primero que haremos será declarar una clase simple que unicamente nos servirá para ejemplificar el punto de este capítulo, esta clase la llamaremos rational, dicha clase nos permitirá crear numeros racionales y operar con ellos. La definición será la siguiente:  
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
Como podemos ver es una clase muy sencilla que unicamente genera numeros racionales y nos permite reducirlos. En esta clase estamos declarando los métodos de la clase dentro de la misma clase, lo que causa que sea dificil de leer un codigo completo, para solucionarlo sepraremos el prototipo de la implementación.  
Al igual que las funciones normales, C++ nos permite crear un prototipo de los métodos de una clase para poder hacer sus definiciones en otra parte del código, la manera de hacerlo es la siguiente.  
Dividiremos el código en tres partes, la primera de ellas será la **definición de la clase**, en ella encontraremos los prototipos de los métodos así como sus atributos, la segunda será **el main** donde podremos hacer las llamadas de todas estas funciones y clases, y la tercera será la **definició de los métodos** de la clase.  
#### Definición de clase

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
Aquí simplemente hacemos la definicion de la clase incluyendo los prototipos de los métodos y los atributos con los que contará la clase.

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
En esta parte del codigo estamos crando un racional ```a``` que será el correspondiente con 2/4, posteriormente creamos otro racional ```b``` como la version reducida del racional ```a```, esto unicamente con fines ilustrativos de los alcances de nuestra prematura clase.

#### Definición de los métodos.

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
Aquí hemos de remarcar la sintaxis con la que están escritas las definiciones, para las funciones metodo se utiliza la sintxis ```tipo_de_retorno clase_padre::nombre_del_del_metodo(valores_de_entrada)```, notese el uso del operador de acceso **::** para especificar que es un metodo de la clase rational, esto dado que se está declarando fuera de de la clase y ya que la clase no pertenece a ningun espacio de nombres es necesario usar dicho operador de acceso y por otra parte aclarar que *clase_padre* se refiere a la clase a la cual el metodo pertenece. Para la definicion de los constructores la sintaxis es similar, siendo ````clase_padre::clase_padre(parametros_del_constructor)```.  
Como resultado final nuestro programa quedará de la siguiente manera:  
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
Hasta este punto pueden encontrar el programa en cuestión en la carpeta **cp_1** con su respectivo archivo make, con las instrucciones para su compilación.
