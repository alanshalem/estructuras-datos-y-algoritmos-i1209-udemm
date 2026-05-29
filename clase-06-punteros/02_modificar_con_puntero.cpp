// MODIFICAR UNA VARIABLE A TRAVES DE UN PUNTERO
//
// Si p apunta a una variable, entonces *p es esa variable.
// Escribir en *p  CAMBIA la variable original.
//
// Idea clave: el puntero no es una copia. Es un "acceso directo"
// a la variable real. Tocar *p toca el original.

#include <iostream>
using namespace std;

int main()
{
    int numero = 10;
    int* p = &numero;   // p apunta a numero

    cout << "numero antes : " << numero << endl; // 10

    *p = 99;            // entra a la direccion de numero y escribe 99 ahi

    cout << "numero despues: " << numero << endl; // 99  (cambio sin tocar 'numero' directo)

    cout << "------------------" << endl;

    // Tambien podemos operar sobre el valor apuntado
    *p = *p + 1;        // numero = numero + 1
    cout << "numero + 1   : " << numero << endl; // 100

    // Dos punteros pueden apuntar a la MISMA variable
    int* q = &numero;
    *q = 0;             // cambia numero usando q
    cout << "numero via q : " << numero << endl; // 0
    cout << "*p tambien ve : " << *p    << endl; // 0  (p y q apuntan al mismo lugar)

    return 0;
}
