# Instrucciones

Este será un ejercicio donde pondrán a prueba lo aprendido hasta la tercera parte *cp_3* así que la actividad constará de completar la clase de los racionales del ejercicio anterior. En la carpeta includes encontrarán la declaración de la clase completa **ESTE ARCHIVO NO SE PUEDE MODIFICAR Y DEBERÁN APEGARSE A LAS DEFINICIONES AHÍ ESTABLECIDAS** a excepción de que quieran agregar métodos, pero modificar los ya establecidos está prohibido, es decir, ese archivo contendrá lo mínimo que la clase puede hacer. Por ejemplo, supongamos que la clase es de la siguiente manera:  
~~~ c++
class rational
{
private:
  int p;
  int q;
public:
  void reduceNumero();
  rational suma(rational &);
}
~~~
En este caso ustedes tendrán que desarrollar una función de tipo vacío que no toma valores y que reduzca el racional en su interior y una función de tipo rational que tome la referencia de un racional y lo suma al mismo racional del objeto a la cual pertenece el metodo suma.

Acontinuación se describen los métodos y atributos de la clase.

# Atributos

## int p

Este atributo representa el dividendo del racional (p/q).

## int q

Este atributo representa el divisor del racional (p/q)

## bool simp

Este valor almacenará la opción de cuándo un racional se puede simplificar y cuándo no, al ser true el racional estará siempre en su versión más simple, al ser false no se prodrá reducir.

# Métodos

## rational()

Será un constructor por omisión, es decir, el constructor por defecto, este constructor nos iniciará en un valor lógico ```p``` y ```q```, para mí un valor lógico sería el racional que de 0, además de darle valor de false a simp por omisión siempre.

## rational(int, int)

Este será un constructor que nos genere un rational dado dos números (p y q, enteros ambos), es decir, ```rational(1,2)``` nos construirá el ```rational``` 1/2 y el valor de simp será falso por omisión siempre.

## rational(int, int, bool)

El constructor que nos construye el racional de la misma manera que el constructor ```rational(int, int)```, solo que en este caso se especifica el valor de la variable simp, en caso de ser true su valor, guardará el valor simplificado del rational que hemos introducido.

## rational(const rational &)

Este es el constructor de copia, nos construye objeto de tipo rational a partir de otro rational dado, el constructor lógico sería el que copia textualmente los valores de p, q y simp del objeto rational de entrada. Un ejemplo de esto sería tener un ```rational r = (1,2)``` que represente el número 1/2, y al hacer ```rational t = rational(r)``` t representará el rational 1/2 de la misma manera.

## void setP(int)

El setter del dividendo p del racional.

## void setQ(int)

El setter del divisor q del rational.

## void setSimp(bool)

El setter de simp.

## int getP()

El getter del dividendo p del rational.

## int getQ()

el getter del divisor q del rational.

## bool getSimp()

El getter del valor de simp.

## void imprime()

Una función que nos permita ver en pantalla el rational, es decir, supongamos que tenemos un rational ```rational r = rational(1,2)```, la función ```r.imprime()``` nos imprimirá en pantalla ```1/2```.

## bool isReduc()

Este método nos dirá cuándo el rational es reducible y cuándo no. Por ejemplo, si tenemos ```rational r = rational(1/2)``` y ```rational t = rational(4/8)``` al hacer ```bool isItReduc = r.isReduc()``` y ```bool isItReduc2 = t.isReduc()``` las variables ```isItReduc``` y ```isItReduc2``` tendrán los correspondientes valores false y true.

## rational reduc()

Este método nos regresa un objeto rational que representa la versión simplificada de nuestro rational en cuestión, es decir, supongamos que tenemos ```rational r = rational(4/8)```, al usar el método ```rational y = r.reduc()``` ```y``` tendrá el valor 1/2, pero ```r``` seguirá teniendo el valor 4/8. Este método es independiente del valor que pueda tener simp, es decir, si es false o true, el método ```reduc()``` simpre regresará la versión reducida del racional en cuestión.

## void simplify()

Este método hará exactamente lo mismo que reduc, solo que en este caso sí modificará el valor del rational si el valor de simp es true, es ese caso retornará un valor boleando, siendo ```false``` en caso de que no sea posible reducirlo y ```true``` en caso de haberlo reducido con éxito, es decir, supongamos que tenemos ```rational r = rational(4/8);``` y ```rational t = rational(1/2);```, al hacer ```bool sePudo = r.simplify();``` y ```bool sePudo2 = t.simplify()``` la variable ```sePudo``` tendrá valor true y r ahora representará el racional 1/2, en el caso de t ```sePudo2``` tendrá valor false y el rational t seguirá representando el valor 1/2. En el caso en el que la variable simp es false, el método regresará el valor de false y no modificará ningún valor del rational.

## rational sum(rational &)

Este método representa la suma de números racionales, es decir, si tenemos ```rational r = rational(1,2)``` y ```rational t = rational(3/2)``` el ```rational sum = r.sum(t)``` tendrá valor 4/2 si simp tiene el valor false y valdrá 2/1 si simp tiene valor true.

## rational sub(rational &)

Este método representa la resta de números racionales, y funciona de la misma manera que la suma.

## rational div(rational &)

Respresenta la división de números racionales, su funcionamiento es igual al de la suma.

## rational mult(rational &)

Respresenta la multiplicación de números racionales, su funcionamiento es igual al de la suma.

## rational exp(int)

representa la exponenciación de numeros racionales, funciona igual que la suma.

## double ReAprox()

Este método nos calcula la aproximación real del numero racional en cuestión, es decir, si tenemos ```rational r = rational(1/2)``` y hacemos ```double val = r.reAprox()``` val tendrá el valor 0.5. Este método es independiente del valor de simp.
