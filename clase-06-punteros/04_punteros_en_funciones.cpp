// PUNTEROS EN FUNCIONES (PASAJE POR REFERENCIA)
//
// Por defecto, C++ pasa los argumentos POR COPIA:
// la funcion recibe una copia y los cambios NO afectan al original.
//
// Si pasamos un PUNTERO (la direccion de la variable), la funcion
// puede entrar a esa direccion y modificar la variable REAL del que llama.
//
//   void f(int* p)  -> recibe una direccion
//   *p = ...        -> escribe en la variable original

#include <iostream>
using namespace std;

// POR COPIA: no funciona, modifica una copia local
void duplicarMal(int n)
{
    n = n * 2;
}

// POR PUNTERO: si funciona, modifica el original
void duplicarBien(int* p)
{
    *p = *p * 2;
}

// Caso clasico: intercambiar dos variables
void intercambiar(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int x = 5;

    duplicarMal(x);
    cout << "Despues de duplicarMal : " << x << endl; // 5  (no cambio)

    duplicarBien(&x);   // pasamos la DIRECCION de x
    cout << "Despues de duplicarBien: " << x << endl; // 10 (cambio)

    cout << "------------------" << endl;

    int a = 1, b = 2;
    cout << "Antes : a=" << a << " b=" << b << endl; // a=1 b=2
    intercambiar(&a, &b);
    cout << "Despues: a=" << a << " b=" << b << endl; // a=2 b=1

    return 0;
}
