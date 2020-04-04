#include <iostream>
#include "../includes/operaciones.h"

using namespace std;

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
          cout << "5. Salir" << endl;
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
            case 5:
              salir = true;
              reint = true;
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
