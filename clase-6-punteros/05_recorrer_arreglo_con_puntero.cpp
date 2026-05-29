// Dos formas de recorrer un arreglo:
// 1) con un indice i y v[i]
// 2) con un puntero que avanza con p++ (aritmetica de punteros)
// Ojo: si el indice o el puntero se pasan del tamano del arreglo se lee basura
// (memoria que no pertenece al arreglo). Aca se recorre hasta 4 a proposito para verlo.

#include <iostream>
using namespace std;

int main()
{
    int v[3] = {10, 20, 30};

    cout << "&v[0]= " << &v[0] << " --- v[0]= " << v[0] << endl;
    cout << "&v[1]= " << &v[1] << " --- v[1]= " << v[1] << endl;
    cout << "&v[2]= " << &v[2] << " --- v[2]= " << v[2] << endl;

    cout << "------------------" << endl;

    // Recorrido con indice (i llega a 3, fuera del arreglo: v[3] es basura)
    for (int i = 0; i < 4; i++)
    {
        cout << "&v[i]= " << &v[i] << " --- v[i]= " << v[i] << endl;
    }

    cout << "------------------" << endl;

    // Recorrido con puntero: arranca en &v[0] y avanza con p++ hasta &v[0]+4
    for (int* p = &v[0]; p < &v[0] + 4; p++)
    {
        cout << "p= " << p << " --- *p= " << *p << endl;
    }

    return 0;
}
