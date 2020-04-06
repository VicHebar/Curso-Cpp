# Segunda parte

La segunda parte sobre cómo dividir el código se presenta a continuación.  
Hasta el momento hemos visto que los metodos de las clases también se pueden dividir en prototipos y definiciones, sin embargo sigue sin ser muy clara la utilidad de poder hacer esto, y que el código sigue viéndose confuso y desordenado. Acontinuación veremos la utilidad de la misma.

# Dividir codigo en multiples archivos.

Gracias a que podemos dividir nuestras definiciones y prototipos nosotros somos capaces de dividir nuestro código en multiples archivos para facilitar el uso y depuración del mismo, hagamos un programa para ejemplificar lo antes asegrado.  
El ejemplo será un simple programa que que sume, reste y multiplique numeros enteros.  
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
          cout << "Que operación deseas aplicar?" << endl;
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
Al ser un programa sumamente sencillo no requerirá ninguna explicación, **CLARAMENTE** es fácil de entender. Guardaremos este codigo como **mainOperaciones.cpp**  
Nuestro interés a partir de ahora es poder hacer más legible este código, para ello crearemos dos nuevos archivos llamados **operaciones.cpp** y **operaciones.h**, el contenido será el siguiente:

### operaciones.h

Este archivo contendrá todos los prototipos de las funciones que hemos creado previamente, por lo tanto su contenido será el sigueinte:  
~~~ c++
int suma (int, int);
int producto (int, int);
int resta (int, int);
~~~

### operaciones.cpp

Este archivo contendrá todas las definiciones de las funciones que estáran en **operaciones.h**, por lo que el contenido será el siguiente:  
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
Aquí será buena notar que hemos usado comillas ("") en lugar de los usuales picoparentesis (<>), esto se explicará con mayor detalle más adelante. Además de incluir el archivo que previamente hemos creado, se incluye con la dirección donde se ubica, es decir, en lugar de escribir simplemente ```#include "operaciones.h"``` se hace ```#include "./include/operaciones.h"```, que es la ubicación del archivo **operaciones.h**.  
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
          cout << "Que operación deseas aplicar?" << endl;
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

Así pues hemos dividido nuestro código en distinatas partes, en un archivo de cabecera (operaciones.h), un archivo de codigo fuente (operaciones.h) y nuestro arachivo donde se utilizan todas las utilidades que incluye nuestro nuevo archivo de cabecera.  
¿Por qué se usan comillas ("") en lugar de picoparéntesis?, la respuesta a esta pregunta es la siguiente, todas las inclusiones de archivos de cabecera que hemos hecho hasta el momento se encuentran en el estándar de C/C++, es por ello que al instalar el compilador (En nuestro caso MinGW) se descargan todas los archivos de cabecera y bibliotecas del estándar de C/C++, estas librerías y archivos de encabezado se encuentran en un lugar estándar dentro de la carpeta de instalación de MinGW, hablando de manera concreta podemos encontrarlas en ```C:\MinGW\include```, aquí podremos encontrar todos los archivos de cabecera (archivos .h) que vienen en el estándar de C/C++, mientras que en ```C:\MinGW\lib``` podremos encontrar todos las bibliotecas (library en inglés, de allí que la carpeta se llame *lib*) compiladas en código objeto (.o) y archivos de acomulación (.a), para especificar que un archivo de cabecera se encuentra en el estandar se usan los picoparentesis, al usar picoparentesis el compilador buscará los arachivos en el directorio ```C:\MinGW\include```, en nuestro caso el archivo de cabecera no se encuentra en el estandar debido a que nosotros mismos lo hemos creado, y por eso debemos especificar en dónde se encuentra, es por ello que usamos las comillas para decirle al compilador que el archivo de cabecerá no deberá buscarlo dentro de la carpeta del estándar (```C:\MinGW\include```), sino en la ubicación que nosotros le especifiquemos.

# Compilación

La compilación de un proyecto con distintos módulos (más de un archivo .cpp) será dependiendo del resultado buscado, en nuestro caso lo único que deseamos es poder tener esa biblioteca dispopnible para su uso, tendremos que compilar cada archivo por separado (aquí brillará en especial el uso de makefile) y siguiendo ciertas directivas de flujo, es decir, algunos archivos deberán compilarse antes que algunos otros.  
La instrucción usual que usamos para compilar es ```g++ -o salida codigo_fuente.cpp```, donde ```-o``` especifica la salida o lo que el compilador producirá, despues de la salida vienen todos los archivos que se deseen compilar o de los cuales dependa la compilación de la salida. A partir de este punto cambiaremos un poco la manera en que solemos compilar archivos, si nosotros intentáramos compilar de la manera usual el archivo **operaciones.cpp** nos generaría un error, ya que dentro de **operaciones.cpp** no se encuentra una función **main** la cual enlace todas nuestras funciones, es por ello que se usará un "flag" más en la compilación, esta flag indicará al compilador que debe compilar sin enlazar el resultado. Dicha flag será ```-c``` que indicará que unicamente se compilará, no se enlazará de ninguna manera a un main. Lo primero que se compilará será **operaciones.cpp** para generar un archivo que contenga el funcionamiento de todas las funciones y pueda ser usado en otros módulos, la manera de compilación será la antes descrita siendo así:  
```g++ -o bin/operaciones.o -c src/operaciones.cpp```  
Como nos indica la directiva de compilación la salida será un archivo de código objeto (.o), dicho código objeto será simplemente un compilado de las funciones que hemos definido dentro del archivo **operaciones.cpp**. La idea de generara un archivo de código objeto es crear un bloque de código por separado para no tener que compilar secciones del código que no se están siendo modificadas constantemente. Además de lo anterior mencionado podemos ver que dentro de la directiva de compilación se incluye la dirección donde deseamos que se encuentren los archivos o la dirección donde ya se encuentran los archivos, por ejemplo, en la salida ponemos ```bin/operaciones.o```, esto quiere decir que el archivo **operaciones.o** se encontrará dentro de la carperta **bin** y en el caso de la entrada escribimos ```src/operaciones.cpp``` ya que el archivo se encuentra dentro de la carpeta **src**. Esta tectnica de separación de archivos es bastante práctic apero siempre debe de tenerse en cuenta que desde este munto las compilaciones deberán hacerse por separado, es decir, si se modifica el maintendrá que comipilarse el archivo **mainOperaciones.cpp** y si se modifica el archivo **operaciones.cpp** deberá de compilarse el mismo archivos, es decir, los archivos son independientes y su compilación no depende de la compilación de ningún otro archivo. Es por esta razón que les comentaba que el uso de makefile iba a ser fundamental en la división de código, más adelante veremos su modo de empleo.  
Tras la compilación del archivo operaciones.cpp nos encargaremos de compilar el main, la directiva para compilar el main será:  
```g++ -o bin/main src/mainOperaciones.cpp bin/operaciones.o```  
Trás haber ejecutasdo dichas directivas y haber compilado los archivos obtendremos un archivo llamado **main.exe** que se encontrará dentro de la carpeta **bin** que será nuestro archivo que ejecutará todo nuestro Programa.

## Uso de makefile para la compilación

El usar makefile para compilar codigo dividido será especialmente util, ya que makefile compilará todo el archivo que haya sido modificado al ejecutar la sentencia **make**, es por ello que no necesitaremos estar compilando por separado cada archivo, makefile compilará lo necesario para que nuestro programa compile. En este caso en concreto vamos a utilizar el siguiente archivo makefile (Este archivo va a estar incluido en la carpeta del proyecto):  
~~~ makefile
bin/main: src /mainOperaciones.cpp bin/operaciones.o
	g++ -o bin/main src/mainOperaciones.cpp bin/operaciones.o
~~~
La primera parte unicamente será la directiva de compilación para el main, la primera linea especifica el archivo que se desea compilar, es este caso el archivo es **main** que en conjunto con la ubicación donde queremos que esté para obeter como resultado **bin/main**, después de los dos puntos (:) escribimos todos los archivos de los cuales va a depender, es decir, al intentar compilar el archivo **bin/main**, makefile confirmará que los archivos que se encuentran después de los dos puntos **existan** o estén **actualizados**, si es que no existen, make buscará alguna directiva dentro del mismo archivo makefile para crearlo (es decir, buscará dentro del archivo makefile algún lugar donde tú lñe hayas dicho cómo hacer el archivo del cuál depende nuestro **bim/main**, de aquí que el programa se llame **make**, en inglés hacer es make), y en caso de que no esté actualizado hará exactamente lo mismo.  
La segunda linea empieza con un tabulado, todas las líneas consecuentes a la primera que empiecen con un tabulado se interpretarán como acciones a realizar en cadena, en este caso unicamente vamos a ocupar una, después del tabulado viene exactamente lo que quieres que haga en la consola, así que pondremos textualmente la directiva de compilación del main.  
La siguente directiva de compilación será la que especifique cómo crear el archivo **bin/operaciones.o**, ya que en la directiva de la creación del main nos dice que main depende de este archivo, por ello es necesario crear una directiva especial para crearlo en caso de que no existiera, la directiva será:  
~~~ makefile
bin/operaciones.o: src/operaciones.cpp
	g++ -o bin/operaciones.o -c src/operaciones.cpp
~~~
Esta directiva tiene la misma explicación que la anterior, dado a que operaciones.o unicamente depende del contenido de su mismo archivo de codigo fuente **operaciones.cpp** no es necesario poner ningún arachivo más.  
La ultima directiva que tendrá el archivo makefile será una que nos permita ejecutar el programa sin tener que cambiar la ubicación en la consola, esta será:  
~~~ makefile
exec:
	bin/main
~~~
Esta directiva nos permitirá ejecutar el archivo **mainOperaciones.exe** desde la ubicaciones del archivo make, sin tener que cambiar la ubicación en la consola de comandos.
