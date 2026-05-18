// SALIRSE DEL ARRAY (otro peligro clasico)
//
// Ejemplo original de la clase. El array tiene 3 elementos (indices 0,1,2),
// pero los bucles recorren 4. Acceder a v[3] es salirse del array:
// es comportamiento indefinido, lee/usa memoria que no es del array.
//
// Lección: el limite siempre es < tamano (i < 3, no i < 4).
// El array NO avisa cuando te pasas: simplemente lee basura.

#include <iostream>
using namespace std;

int main()
{
    int v[3] = {10, 20, 30};

    cout << "&v[0]= " << &v[0] << " --- v[0]= " << v[0] << endl;
    cout << "&v[1]= " << &v[1] << " --- v[1]= " << v[1] << endl;
    cout << "&v[2]= " << &v[2] << " --- v[2]= " << v[2] << endl;

    cout << "------------------" << endl;

    // PELIGRO: i llega a 3, pero v[3] NO existe (solo 0,1,2)
    for (int i = 0; i < 4; i++)
    {
        cout << "&v[i]= " << &v[i] << " --- v[i]= " << v[i] << endl;
    }

    cout << "------------------" << endl;

    // PELIGRO: el puntero pasa una posicion de mas (&v[0]+4 -> 4 elementos)
    for (int* p = &v[0]; p < &v[0] + 4; p++)
    {
        cout << "p= " << p << " --- *p= " << *p << endl;
    }

    return 0;
}
