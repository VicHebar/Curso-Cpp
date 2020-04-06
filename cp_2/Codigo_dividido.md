# Segunda parte

La segunda parte sobre c�mo dividir el c�digo se presenta a continuaci�n.  
Hasta el momento hemos visto que los metodos de las clases tambi�n se pueden dividir en prototipos y definiciones, sin embargo sigue sin ser muy clara la utilidad de poder hacer esto, y que el c�digo sigue vi�ndose confuso y desordenado. Acontinuaci�n veremos la utilidad de la misma.

# Dividir codigo en multiples archivos.

Gracias a que podemos dividir nuestras definiciones y prototipos nosotros somos capaces de dividir nuestro c�digo en multiples archivos para facilitar el uso y depuraci�n del mismo, hagamos un programa para ejemplificar lo antes asegrado.  
El ejemplo ser� un simple programa que que sume, reste y multiplique numeros enteros.  
~~~ c++
#include <iostream>
using namespace std;

int suma (int, int);
int producto (int, int);
int resta (int, int);

int main()
{
  int a,b;
  int op;
  bool reint = false;
  bool salir = false;
  while(!salir)
    {
      cout << "Que numeros deseas operar?" << endl << "Introduce a: ";
      cin >> a;
      cout << "Introduce b: ";
      cin >> b;
      reint = false;
      while(!reint)
        {
          cout << "a: " << a << ", b: " << b << endl;
          cout << "Que operaci�n deseas aplicar?" << endl;
          cout << "1. a + b" << endl;
          cout << "2. a - b" << endl;
          cout << "3. b - a" << endl;
          cout << "4. a * b" << endl;
          cout << "0. Reintroducir a y b" << endl;
          cout << "-1. Salir" << endl;
          cin >> op;
          switch(op)
            {
            case 1:
              cout << "a + b = " << suma(a,b) << endl;
              break;
            case 2:
              cout << "a - b = " << resta(a,b) << endl;
              break;
            case 3:
              cout << "b - a = " << resta(b,a) << endl;
              break;
            case 4:
              cout << "a * b = " << producto(a,b) << endl;
              break;
            case 0:
              reint = true;
              break;
            case -1:
              salir = true;
              break;
            default:
              break;
            }
          system("pause");
          system("cls");
        }
    }
  
}

int suma(int a, int b)
{
  return a + b;
}
int resta(int a, int b)
{
  return a - b;
}
int producto(int a, int b)
{
  return a * b;
}
~~~
Al ser un programa sumamente sencillo no requerir� ninguna explicaci�n, **CLARAMENTE** es f�cil de entender. Guardaremos este codigo como **mainOperaciones.cpp**  
Nuestro inter�s a partir de ahora es poder hacer m�s legible este c�digo, para ello crearemos dos nuevos archivos llamados **operaciones.cpp** y **operaciones.h**, el contenido ser� el siguiente:

### operaciones.h

Este archivo contendr� todos los prototipos de las funciones que hemos creado previamente, por lo tanto su contenido ser� el sigueinte:  
~~~ c++
int suma (int, int);
int producto (int, int);
int resta (int, int);
~~~

### operaciones.cpp

Este archivo contendr� todas las definiciones de las funciones que est�ran en **operaciones.h**, por lo que el contenido ser� el siguiente:  
~~~ c++
#include "../include/operaciones.h"

int suma(int a, int b)
{
  return a + b;
}
int resta(int a, int b)
{
  return a - b;
}
int producto(int a, int b)
{
  return a * b;
}
~~~
Aqu� ser� buena notar que hemos usado comillas ("") en lugar de los usuales picoparentesis (<>), esto se explicar� con mayor detalle m�s adelante. Adem�s de incluir el archivo que previamente hemos creado, se incluye con la direcci�n donde se ubica, es decir, en lugar de escribir simplemente ```#include "operaciones.h"``` se hace ```#include "./include/operaciones.h"```, que es la ubicaci�n del archivo **operaciones.h**.  
Dentro de nuestro **mainOperaciones.cpp** tendremos lo siguiente:  
~~~ c++
#include <iostream>
#include "../include/operaciones.h"

int main()
{
  int a,b;
  int op;
  bool reint = false;
  bool salir = false;
  while(!salir)
    {
      cout << "Que numeros deseas operar?" << endl << "Introduce a: ";
      cin >> a;
      cout << "Introduce b: ";
      cin >> b;
      reint = false;
      while(!reint)
        {
          cout << "a: " << a << ", b: " << b << endl;
          cout << "Que operaci�n deseas aplicar?" << endl;
          cout << "1. a + b" << endl;
          cout << "2. a - b" << endl;
          cout << "3. b - a" << endl;
          cout << "4. a * b" << endl;
          cout << "0. Reintroducir a y b" << endl;
          cout << "-1. Salir" << endl;
          cin >> op;
          switch(op)
            {
            case 1:
              cout << "a + b = " << suma(a,b) << endl;
              break;
            case 2:
              cout << "a - b = " << resta(a,b) << endl;
              break;
            case 3:
              cout << "b - a = " << resta(b,a) << endl;
              break;
            case 4:
              cout << "a * b = " << producto(a,b) << endl;
              break;
            case 0:
              reint = true;
              break;
            case -1:
              salir = true;
              break;
            default:
              break;
            }
          system("pause");
          system("cls");
        }
    }
  return 0;
}
~~~

As� pues hemos dividido nuestro c�digo en distinatas partes, en un archivo de cabecera (operaciones.h), un archivo de codigo fuente (operaciones.h) y nuestro arachivo donde se utilizan todas las utilidades que incluye nuestro nuevo archivo de cabecera.  
�Por qu� se usan comillas ("") en lugar de picopar�ntesis?, la respuesta a esta pregunta es la siguiente, todas las inclusiones de archivos de cabecera que hemos hecho hasta el momento se encuentran en el est�ndar de C/C++, es por ello que al instalar el compilador (En nuestro caso MinGW) se descargan todas los archivos de cabecera y bibliotecas del est�ndar de C/C++, estas librer�as y archivos de encabezado se encuentran en un lugar est�ndar dentro de la carpeta de instalaci�n de MinGW, hablando de manera concreta podemos encontrarlas en ```C:\MinGW\include```, aqu� podremos encontrar todos los archivos de cabecera (archivos .h) que vienen en el est�ndar de C/C++, mientras que en ```C:\MinGW\lib``` podremos encontrar todos las bibliotecas (library en ingl�s, de all� que la carpeta se llame *lib*) compiladas en c�digo objeto (.o) y archivos de acomulaci�n (.a), para especificar que un archivo de cabecera se encuentra en el estandar se usan los picoparentesis, al usar picoparentesis el compilador buscar� los arachivos en el directorio ```C:\MinGW\include```, en nuestro caso el archivo de cabecera no se encuentra en el estandar debido a que nosotros mismos lo hemos creado, y por eso debemos especificar en d�nde se encuentra, es por ello que usamos las comillas para decirle al compilador que el archivo de cabecer� no deber� buscarlo dentro de la carpeta del est�ndar (```C:\MinGW\include```), sino en la ubicaci�n que nosotros le especifiquemos.

# Compilaci�n

La compilaci�n de un proyecto con distintos m�dulos (m�s de un archivo .cpp) ser� dependiendo del resultado buscado, en nuestro caso lo �nico que deseamos es poder tener esa biblioteca dispopnible para su uso, tendremos que compilar cada archivo por separado (aqu� brillar� en especial el uso de makefile) y siguiendo ciertas directivas de flujo, es decir, algunos archivos deber�n compilarse antes que algunos otros.  
La instrucci�n usual que usamos para compilar es ```g++ -o salida codigo_fuente.cpp```, donde ```-o``` especifica la salida o lo que el compilador producir�, despues de la salida vienen todos los archivos que se deseen compilar o de los cuales dependa la compilaci�n de la salida. A partir de este punto cambiaremos un poco la manera en que solemos compilar archivos, si nosotros intent�ramos compilar de la manera usual el archivo **operaciones.cpp** nos generar�a un error, ya que dentro de **operaciones.cpp** no se encuentra una funci�n **main** la cual enlace todas nuestras funciones, es por ello que se usar� un "flag" m�s en la compilaci�n, esta flag indicar� al compilador que debe compilar sin enlazar el resultado. Dicha flag ser� ```-c``` que indicar� que unicamente se compilar�, no se enlazar� de ninguna manera a un main. Lo primero que se compilar� ser� **operaciones.cpp** para generar un archivo que contenga el funcionamiento de todas las funciones y pueda ser usado en otros m�dulos, la manera de compilaci�n ser� la antes descrita siendo as�:  
```g++ -o bin/operaciones.o -c src/operaciones.cpp```  
Como nos indica la directiva de compilaci�n la salida ser� un archivo de c�digo objeto (.o), dicho c�digo objeto ser� simplemente un compilado de las funciones que hemos definido dentro del archivo **operaciones.cpp**. La idea de generara un archivo de c�digo objeto es crear un bloque de c�digo por separado para no tener que compilar secciones del c�digo que no se est�n siendo modificadas constantemente. Adem�s de lo anterior mencionado podemos ver que dentro de la directiva de compilaci�n se incluye la direcci�n donde deseamos que se encuentren los archivos o la direcci�n donde ya se encuentran los archivos, por ejemplo, en la salida ponemos ```bin/operaciones.o```, esto quiere decir que el archivo **operaciones.o** se encontrar� dentro de la carperta **bin** y en el caso de la entrada escribimos ```src/operaciones.cpp``` ya que el archivo se encuentra dentro de la carpeta **src**. Esta tectnica de separaci�n de archivos es bastante pr�ctic apero siempre debe de tenerse en cuenta que desde este munto las compilaciones deber�n hacerse por separado, es decir, si se modifica el maintendr� que comipilarse el archivo **mainOperaciones.cpp** y si se modifica el archivo **operaciones.cpp** deber� de compilarse el mismo archivos, es decir, los archivos son independientes y su compilaci�n no depende de la compilaci�n de ning�n otro archivo. Es por esta raz�n que les comentaba que el uso de makefile iba a ser fundamental en la divisi�n de c�digo, m�s adelante veremos su modo de empleo.  
Tras la compilaci�n del archivo operaciones.cpp nos encargaremos de compilar el main, la directiva para compilar el main ser�:  
```g++ -o bin/main src/mainOperaciones.cpp bin/operaciones.o```  
Tr�s haber ejecutasdo dichas directivas y haber compilado los archivos obtendremos un archivo llamado **main.exe** que se encontrar� dentro de la carpeta **bin** que ser� nuestro archivo que ejecutar� todo nuestro Programa.

## Uso de makefile para la compilaci�n

El usar makefile para compilar codigo dividido ser� especialmente util, ya que makefile compilar� todo el archivo que haya sido modificado al ejecutar la sentencia **make**, es por ello que no necesitaremos estar compilando por separado cada archivo, makefile compilar� lo necesario para que nuestro programa compile. En este caso en concreto vamos a utilizar el siguiente archivo makefile (Este archivo va a estar incluido en la carpeta del proyecto):  
~~~ makefile
bin/main: src /mainOperaciones.cpp bin/operaciones.o
	g++ -o bin/main src/mainOperaciones.cpp bin/operaciones.o
~~~
La primera parte unicamente ser� la directiva de compilaci�n para el main, la primera linea especifica el archivo que se desea compilar, es este caso el archivo es **main** que en conjunto con la ubicaci�n donde queremos que est� para obeter como resultado **bin/main**, despu�s de los dos puntos (:) escribimos todos los archivos de los cuales va a depender, es decir, al intentar compilar el archivo **bin/main**, makefile confirmar� que los archivos que se encuentran despu�s de los dos puntos **existan** o est�n **actualizados**, si es que no existen, make buscar� alguna directiva dentro del mismo archivo makefile para crearlo (es decir, buscar� dentro del archivo makefile alg�n lugar donde t� l�e hayas dicho c�mo hacer el archivo del cu�l depende nuestro **bim/main**, de aqu� que el programa se llame **make**, en ingl�s hacer es make), y en caso de que no est� actualizado har� exactamente lo mismo.  
La segunda linea empieza con un tabulado, todas las l�neas consecuentes a la primera que empiecen con un tabulado se interpretar�n como acciones a realizar en cadena, en este caso unicamente vamos a ocupar una, despu�s del tabulado viene exactamente lo que quieres que haga en la consola, as� que pondremos textualmente la directiva de compilaci�n del main.  
La siguente directiva de compilaci�n ser� la que especifique c�mo crear el archivo **bin/operaciones.o**, ya que en la directiva de la creaci�n del main nos dice que main depende de este archivo, por ello es necesario crear una directiva especial para crearlo en caso de que no existiera, la directiva ser�:  
~~~ makefile
bin/operaciones.o: src/operaciones.cpp
	g++ -o bin/operaciones.o -c src/operaciones.cpp
~~~
Esta directiva tiene la misma explicaci�n que la anterior, dado a que operaciones.o unicamente depende del contenido de su mismo archivo de codigo fuente **operaciones.cpp** no es necesario poner ning�n arachivo m�s.  
La ultima directiva que tendr� el archivo makefile ser� una que nos permita ejecutar el programa sin tener que cambiar la ubicaci�n en la consola, esta ser�:  
~~~ makefile
exec:
	bin/main
~~~
Esta directiva nos permitir� ejecutar el archivo **mainOperaciones.exe** desde la ubicaciones del archivo make, sin tener que cambiar la ubicaci�n en la consola de comandos.
