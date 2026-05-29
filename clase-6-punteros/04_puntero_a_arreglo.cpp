// Un arreglo se guarda en posiciones de memoria contiguas (una al lado de la otra).
// El nombre del arreglo y &v[0] apuntan al primer elemento.
// Un puntero puede apuntar al inicio del arreglo y desde ahi recorrerlo.

#include <iostream>
using namespace std;

int main()
{
    int v[3] = {10, 20, 30};
    int* p;

    // Las direcciones de los elementos son consecutivas (separadas por 4 bytes, el tamano de un int)
    cout << "&v[0]= " << &v[0] << " --- v[0]= " << v[0] << endl;
    cout << "&v[1]= " << &v[1] << " --- v[1]= " << v[1] << endl;
    cout << "&v[2]= " << &v[2] << " --- v[2]= " << v[2] << endl;

    p = &v[0]; // p apunta al primer elemento del arreglo
    cout << "&v[0]= " << &v[0] << " --- v[0]= " << v[0] << endl;
    cout << "p= " << p << " --- *p= " << *p << endl; // p es la direccion de v[0], *p es 10

    return 0;
}
