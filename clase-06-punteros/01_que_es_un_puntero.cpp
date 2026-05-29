// QUE ES UN PUNTERO
//
// Cada variable vive en una direccion de memoria (como el numero de una casa).
// Un PUNTERO es una variable especial que NO guarda un valor normal,
// guarda la DIRECCION de otra variable (donde vive).
//
// Dos operadores nuevos:
//   &x   -> "direccion de x"      (donde esta guardada x en memoria)
//   *p   -> "el valor apuntado"   (entra a esa direccion y trae el valor)
//
// Declarar un puntero:
//   int* p;   ->  "p es un puntero a un int"
//
// El * en la declaracion solo dice "esto es un puntero".
// El * usado despues (ej: *p) significa "el valor que esta en esa direccion".

#include <iostream>
using namespace std;

int main()
{
    int edad = 25;     // variable normal: guarda el numero 25
    int* p;            // puntero a int: por ahora no apunta a nada util

    p = &edad;         // p ahora guarda la DIRECCION de edad

    cout << "Valor de edad        : " << edad  << endl; // 25
    cout << "Direccion de edad    : " << &edad << endl; // algo como 0x7ffe...
    cout << "Valor de p (direccion): " << p     << endl; // la MISMA direccion que &edad
    cout << "Valor apuntado por p : " << *p    << endl; // 25  (entra a la direccion)

    // *p es otra forma de leer/escribir edad, porque p apunta a edad
    cout << "------------------" << endl;
    cout << "edad == *p ? los dos valen lo mismo: " << edad << " y " << *p << endl;

    return 0;
}
