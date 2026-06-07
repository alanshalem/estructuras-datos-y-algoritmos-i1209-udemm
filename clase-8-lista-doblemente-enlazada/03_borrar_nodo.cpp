// Borrar un nodo DEL MEDIO de la lista doble por su valor.
//
// Partimos de 50 <-> 100 <-> 150 <-> 200 y borramos el 100.
//
// Para sacar un nodo del medio hay que "puentear" sus vecinos: el de la
// izquierda pasa a apuntar al de la derecha, y viceversa. Despues delete.
//
//   antes:   [50] <-> [100] <-> [150] ...
//   puente:  [50] <----------> [150]   (el 100 queda sin nadie apuntandolo)
//   delete del 100.

#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* anterior;
    Nodo* siguiente;
};

struct estructuraLista
{
    Nodo* primero;
    Nodo* ultimo;
};

int main()
{
    Nodo* nuevo;
    Nodo* p;

    estructuraLista lista;
    lista.primero = nullptr;
    lista.ultimo = nullptr;

    // ---- Armo 50 <-> 100 <-> 200, luego inserto 150 en orden ----
    nuevo = new Nodo;
    nuevo->dato = 100;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;
    lista.primero = nuevo;
    lista.ultimo = nuevo;

    nuevo = new Nodo;
    nuevo->dato = 200;
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;
    lista.ultimo->siguiente = nuevo;
    nuevo->anterior = lista.ultimo;
    lista.ultimo = nuevo;

    nuevo = new Nodo;
    nuevo->dato = 50;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;
    lista.primero->anterior = nuevo;
    nuevo->siguiente = lista.primero;
    lista.primero = nuevo;

    nuevo = new Nodo;
    nuevo->dato = 150;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;
    p = lista.primero;
    while (p != nullptr)
    {
        if (p->dato < nuevo->dato)
        {
            p = p->siguiente;
        }
        else
        {
            nuevo->siguiente = p;
            nuevo->anterior = p->anterior;
            nuevo->anterior->siguiente = nuevo;
            nuevo->siguiente->anterior = nuevo;
            break;
        }
    }

    // Estado: 50 <-> 100 <-> 150 <-> 200
    cout << "-------" << endl;
    p = lista.primero;
    while (p != nullptr)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    // ---- Borrar el nodo cuyo dato es 100 ----
    int datoABorrar = 100;
    p = lista.primero;
    while (p != nullptr)
    {
        if (p->dato != datoABorrar)
        {
            p = p->siguiente; // no es, sigo buscando
        }
        else
        {
            // p es el nodo a borrar (el 100). Puenteo sus vecinos:
            p->anterior->siguiente = p->siguiente; // el 50 apunta al 150
            p->siguiente->anterior = p->anterior;  // el 150 apunta al 50
            delete p;                              // libero el 100
            break;
        }
    }
    // OJO: este puente asume que el nodo NO es el primero ni el ultimo
    // (si lo fuera, p->anterior o p->siguiente serian NULL y rompe).

    // ---- Mostrar resultado ----
    cout << "-------" << endl;
    p = lista.primero;
    while (p != nullptr)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    return 0;
}

// Borrar del medio = puentear los dos vecinos y delete del nodo.
