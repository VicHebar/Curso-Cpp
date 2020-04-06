# Instrucciones

Este ser� un ejercicio donde pondr�n a prueba lo aprendido hasta la tercera parte *cp_3* as� que la actividad constar� de completar la clase de los racionales del ejercicio anterior. En la carpeta includes encontrar�n la declaraci�n de la clase completa **ESTE ARCHIVO NO SE PUEDE MODIFICAR Y DEBER�N APEGARSE A LAS DEFINICIONES AH� ESTABLECIDAS** a excepci�n de que quieran agregar m�todos, pero modificar los ya establecidos est� prohibido, es decir, ese archivo contendr� lo m�nimo que la clase puede hacer. Por ejemplo, supongamos que la clase es de la siguiente manera:  
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
En este caso ustedes tendr�n que desarrollar una funci�n de tipo vac�o que no toma valores y que reduzca el racional en su interior y una funci�n de tipo rational que tome la referencia de un racional y lo suma al mismo racional del objeto a la cual pertenece el metodo suma.

Acontinuaci�n se describen los m�todos y atributos de la clase.

# Atributos

## int p

Este atributo representa el dividendo del racional (p/q).

## int q

Este atributo representa el divisor del racional (p/q)

## bool simp

Este valor almacenar� la opci�n de cu�ndo un racional se puede simplificar y cu�ndo no, al ser true el racional estar� siempre en su versi�n m�s simple, al ser false no se prodr� reducir.

# M�todos

## rational()

Ser� un constructor por omisi�n, es decir, el constructor por defecto, este constructor nos iniciar� en un valor l�gico ```p``` y ```q```, para m� un valor l�gico ser�a el racional que de 0, adem�s de darle valor de false a simp por omisi�n siempre.

## rational(int, int)

Este ser� un constructor que nos genere un rational dado dos n�meros (p y q, enteros ambos), es decir, ```rational(1,2)``` nos construir� el ```rational``` 1/2 y el valor de simp ser� falso por omisi�n siempre.

## rational(int, int, bool)

El constructor que nos construye el racional de la misma manera que el constructor ```rational(int, int)```, solo que en este caso se especifica el valor de la variable simp, en caso de ser true su valor, guardar� el valor simplificado del rational que hemos introducido.

## rational(const rational &)

Este es el constructor de copia, nos construye objeto de tipo rational a partir de otro rational dado, el constructor l�gico ser�a el que copia textualmente los valores de p, q y simp del objeto rational de entrada. Un ejemplo de esto ser�a tener un ```rational r = (1,2)``` que represente el n�mero 1/2, y al hacer ```rational t = rational(r)``` t representar� el rational 1/2 de la misma manera.

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

Una funci�n que nos permita ver en pantalla el rational, es decir, supongamos que tenemos un rational ```rational r = rational(1,2)```, la funci�n ```r.imprime()``` nos imprimir� en pantalla ```1/2```.

## bool isReduc()

Este m�todo nos dir� cu�ndo el rational es reducible y cu�ndo no. Por ejemplo, si tenemos ```rational r = rational(1/2)``` y ```rational t = rational(4/8)``` al hacer ```bool isItReduc = r.isReduc()``` y ```bool isItReduc2 = t.isReduc()``` las variables ```isItReduc``` y ```isItReduc2``` tendr�n los correspondientes valores false y true.

## rational reduc()

Este m�todo nos regresa un objeto rational que representa la versi�n simplificada de nuestro rational en cuesti�n, es decir, supongamos que tenemos ```rational r = rational(4/8)```, al usar el m�todo ```rational y = r.reduc()``` ```y``` tendr� el valor 1/2, pero ```r``` seguir� teniendo el valor 4/8. Este m�todo es independiente del valor que pueda tener simp, es decir, si es false o true, el m�todo ```reduc()``` simpre regresar� la versi�n reducida del racional en cuesti�n.

## void simplify()

Este m�todo har� exactamente lo mismo que reduc, solo que en este caso s� modificar� el valor del rational si el valor de simp es true, es ese caso retornar� un valor boleando, siendo ```false``` en caso de que no sea posible reducirlo y ```true``` en caso de haberlo reducido con �xito, es decir, supongamos que tenemos ```rational r = rational(4/8);``` y ```rational t = rational(1/2);```, al hacer ```bool sePudo = r.simplify();``` y ```bool sePudo2 = t.simplify()``` la variable ```sePudo``` tendr� valor true y r ahora representar� el racional 1/2, en el caso de t ```sePudo2``` tendr� valor false y el rational t seguir� representando el valor 1/2. En el caso en el que la variable simp es false, el m�todo regresar� el valor de false y no modificar� ning�n valor del rational.

## rational sum(rational &)

Este m�todo representa la suma de n�meros racionales, es decir, si tenemos ```rational r = rational(1,2)``` y ```rational t = rational(3/2)``` el ```rational sum = r.sum(t)``` tendr� valor 4/2 si simp tiene el valor false y valdr� 2/1 si simp tiene valor true.

## rational sub(rational &)

Este m�todo representa la resta de n�meros racionales, y funciona de la misma manera que la suma.

## rational div(rational &)

Respresenta la divisi�n de n�meros racionales, su funcionamiento es igual al de la suma.

## rational mult(rational &)

Respresenta la multiplicaci�n de n�meros racionales, su funcionamiento es igual al de la suma.

## rational exp(int)

representa la exponenciaci�n de numeros racionales, funciona igual que la suma.

## double ReAprox()

Este m�todo nos calcula la aproximaci�n real del numero racional en cuesti�n, es decir, si tenemos ```rational r = rational(1/2)``` y hacemos ```double val = r.reAprox()``` val tendr� el valor 0.5. Este m�todo es independiente del valor de simp.
