// Puntero a char (char*).
// Un char guarda un caracter (1 byte). El codigo ASCII de 'A' es 65, el de 'Z' es 90.
// Al imprimir &b como char* la consola lo trata como texto, por eso se castea a (void*)
// para ver la direccion de memoria en lugar de la cadena.

#include <iostream>
using namespace std;

int main()
{
    int a = 72;
    char b = 'A';
    char* c = &b; // c apunta al char b

    cout << "&a=" << &a << "--- a=" << a << endl;
    cout << "&b=" << (void*)&b << "--- b=" << b << endl; // (void*) para mostrar la direccion, no el texto
    cout << "c=" << c << "--- *c=" << *c << endl;

    c = &b; // c apunta a b
    c++;    // avanza una posicion char (1 byte) en memoria
    cout << "c=" << c << "--- *c=" << *c << endl;

    *c = 'Z'; // escribe 'Z' en esa direccion de memoria
    cout << "a=" << a << endl; // segun el orden de memoria, a puede verse afectado

    return 0;
}
