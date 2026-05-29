// Un puntero permite leer Y modificar el valor guardado en una direccion de memoria.
// Asignando *c = valor se cambia lo que hay en la direccion a la que apunta c.

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int* c = nullptr; // nullptr: el puntero arranca sin apuntar a nada

    cout << "&a=" << &a << " --- a=" << a << endl;
    cout << "&b=" << &b << " --- b=" << b << endl;

    c = &a; // c apunta a a
    c--;    // retrocede una posicion en memoria (queda apuntando a la direccion anterior a a)
    *c = 30; // escribe 30 en esa direccion de memoria

    cout << "c=" << c << " --- *c=" << *c << endl;
    cout << "&b=" << &b << " --- b=" << b << endl; // segun como ordene la memoria, b puede haber cambiado

    return 0;
}
