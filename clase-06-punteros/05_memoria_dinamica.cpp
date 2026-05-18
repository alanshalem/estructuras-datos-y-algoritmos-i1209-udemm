// MEMORIA DINAMICA (new / delete)
//
// Hasta ahora las variables se creaban solas y se destruian solas
// (memoria "automatica"). A veces necesitamos pedir memoria nosotros
// mientras el programa corre: eso es memoria DINAMICA.
//
//   new int        -> pide espacio para 1 int, devuelve su direccion
//   new int[n]     -> pide espacio para n int seguidos (array dinamico)
//   delete p       -> libera lo pedido con new
//   delete[] p     -> libera lo pedido con new[]
//
// REGLA: todo lo que se pide con new se DEBE liberar con delete.
// Si no, se pierde memoria (memory leak).

#include <iostream>
using namespace std;

int main()
{
    // --- Un solo valor dinamico ---
    int* p = new int;   // pide memoria para un int
    *p = 42;            // guardamos un valor ahi
    cout << "Valor dinamico: " << *p << endl; // 42
    delete p;           // liberamos
    p = nullptr;        // buena practica: ya no apunta a nada valido

    cout << "------------------" << endl;

    // --- Array dinamico (tamano decidido en ejecucion) ---
    int n;
    cout << "Cuantos numeros? ";
    cin >> n;

    int* v = new int[n];   // array de n enteros en memoria dinamica

    for (int i = 0; i < n; i++)
        v[i] = (i + 1) * 10;   // 10, 20, 30, ...

    cout << "Contenido: ";
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;

    delete[] v;   // liberar array: ojo, delete[] con corchetes
    v = nullptr;

    return 0;
}
