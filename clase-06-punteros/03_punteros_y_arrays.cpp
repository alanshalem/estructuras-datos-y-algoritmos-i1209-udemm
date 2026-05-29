// PUNTEROS Y ARRAYS (ARITMETICA DE PUNTEROS)
//
// Un array guarda sus elementos JUNTOS y SEGUIDOS en memoria.
// El nombre del array es, en la practica, la direccion del primer elemento.
//
//   v[0]  v[1]  v[2]
//   [10]  [20]  [30]   <- contiguos en memoria
//
// Si p apunta a v[0]:
//   p + 1  -> apunta al SIGUIENTE int (v[1]), no al siguiente byte.
//             El compilador suma sizeof(int) automaticamente.
//   *(p+1) -> el valor de v[1]
//   p++    -> avanza el puntero al proximo elemento

#include <iostream>
using namespace std;

int main()
{
    int v[3] = {10, 20, 30};

    // Cada elemento tiene su propia direccion, separadas por sizeof(int) (4 bytes)
    cout << "&v[0]= " << &v[0] << "  v[0]= " << v[0] << endl;
    cout << "&v[1]= " << &v[1] << "  v[1]= " << v[1] << endl;
    cout << "&v[2]= " << &v[2] << "  v[2]= " << v[2] << endl;

    cout << "------------------" << endl;

    int* p = v;         // equivale a p = &v[0]

    cout << "*p     = " << *p     << endl; // 10
    cout << "*(p+1) = " << *(p+1) << endl; // 20
    cout << "*(p+2) = " << *(p+2) << endl; // 30

    cout << "------------------" << endl;

    // Recorrer el array moviendo el puntero
    for (int* q = v; q < v + 3; q++)
    {
        cout << "q= " << q << "  *q= " << *q << endl;
    }

    cout << "------------------" << endl;

    // p[i] es exactamente lo mismo que *(p+i)
    for (int i = 0; i < 3; i++)
    {
        cout << "p[" << i << "]= " << p[i] << endl;
    }

    return 0;
}
