// Conceptos basicos de punteros
// &variable : operador "direccion de" -> devuelve la direccion de memoria de la variable
// int* c    : declara un puntero, una variable que guarda una direccion de memoria
// *c        : operador "contenido de" -> devuelve el valor guardado en esa direccion

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int* c; // puntero a int, todavia no apunta a ninguna direccion valida

    cout << "&a=" << &a << "--- a=" << a << endl; // &a es la direccion donde vive a
    cout << "&b=" << &b << "--- b=" << b << endl;
    cout << "c=" << c << "--- *c=" << *c << endl; // c apunta a basura (aun no se asigno)

    c = &a; // ahora c guarda la direccion de a
    cout << "c=" << c << "--- *c=" << *c << endl; // c es la direccion de a, *c es 10

    c--; // aritmetica de punteros: retrocede una posicion int (4 bytes) en memoria

    return 0;
}
