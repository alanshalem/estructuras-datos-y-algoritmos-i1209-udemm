// El mismo concepto de puntero aplica a cualquier tipo de dato.
// Un puntero a double (double*) guarda la direccion de una variable double.
// El tipo importa: la aritmetica de punteros avanza/retrocede del tamano del tipo.

#include <iostream>
using namespace std;

int main()
{
    double a = 10;
    double b = 20;
    double* c = nullptr; // no apunta a nada todavia

    cout << "&a= " << &a << " --- a= " << a << endl; // direccion donde se guarda a
    cout << "&b= " << &b << " --- b= " << b << endl;

    c = &a; // c apunta a a
    cout << "c= " << c << " --- *c= " << *c << endl;

    c--; // retrocede una posicion double (8 bytes) en memoria
    cout << "c= " << c << " --- *c= " << *c << endl;

    *c = 30; // el puntero modifica lo que hay en esa direccion de memoria
    cout << "&b= " << &b << " --- b= " << b << endl;

    return 0;
}
