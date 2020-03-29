#include <iostream>
#include "../includes/Complex.h"
#include <math.h>
using namespace std;

int main()
{
  double re, im;
  Complex a, b;
  int op = 0, e = 0;
  bool calculadora = true;
  while(true)
  {
    cout << "Dame los valores de a" << endl;
    cout << "Re: ";
    cin >> re;
    cout << "im: ";
    cin >> im;
    a = Complex(re,im);
    cout << "Dame los valores de b" << endl;
    cout << "Re: ";
    cin >> re;
    cout << "im: ";
    cin >> im;
    b = Complex(re,im);
    system("cls");
    calculadora = true;
    while(calculadora)
    {
      cout << "a: ";
      a.imprime();
      cout << ", b: ";
      b.imprime();
      cout << endl;
      cout << "Que deseas hacer?: " << endl;
      cout << "1. Sumarlos" << endl;
      cout << "2. Restar a - b" << endl;
      cout << "3. Restar b - a" << endl;
      cout << "4. Multiplicarlos" << endl;
      cout << "5. Dividir a / b" << endl;
      cout << "6. Dividir b / a" << endl;
      cout << "7. Sacar su norma" << endl;
      cout << "8. Sacar su argumento" << endl;
      cout << "9. Exponenciar a y b" << endl;
      cout << "0: Reingresar a y b" << endl;
      cin >> op;
      switch(op)
      {
      case 1:
        (a.Add(b)).imprime();
        cout << endl;
        break;
      case 2:
        (a.Sub(b)).imprime();
        cout << endl;
      case 3:
        (b.Sub(a)).imprime();
        cout << endl;
        break;
      case 4:
        (a.Mult(b)).imprime();
        cout << endl;
        break;
      case 5:
        (a.Div(b)).imprime();
        cout << endl;
        break;
      case 6:
        (b.Div(a)).imprime();
        cout << endl;
        break;
      case 7:
        cout << "La norma de a es: " << a.norm() << endl;
        cout << "La norma de b es: " << b.norm() << endl;
        break;
      case 8:
        cout << "El argumento de a es: " << a.arg() << endl;
        cout << "El argumento de b es: " << b.arg() << endl;
        break;
      case 9:
        cout << "a que potencia deseas exponenciarlos?" << endl;
        cin >> e;
        (a.exp(e)).imprime();
        cout << endl;
        (b.exp(e)).imprime();
        cout << endl;
        break;
      case 0:
        calculadora = false;
        break;
      }
      system("pause");
      system("cls");
    }
  }
  
  return 0;
}


