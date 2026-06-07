// Insertar un nodo EN EL MEDIO manteniendo la lista ordenada.
//
// Partimos de la lista 50 <-> 100 <-> 200 y queremos meter el 150 en su
// lugar (entre 100 y 200) sin romper los enlaces.
//
// La clave de la lista doble: para insertar entre dos nodos hay que tocar
// CUATRO punteros (los dos del nodo nuevo, y un puntero de cada vecino).
//
//   antes:  ... [100] <-> [200] ...
//   busco el primer nodo cuyo dato sea MAYOR que 150 -> es el 200.
//   inserto el 150 ANTES de ese nodo:
//   despues: ... [100] <-> [150] <-> [200] ...

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

    // ---- Armo la lista base: 100, atras 200, adelante 50 ----
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

    // Estado: 50 <-> 100 <-> 200

    // ---- Insertar 150 en orden ----
    nuevo = new Nodo;
    nuevo->dato = 150;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;

    // Recorro hasta encontrar el primer nodo con dato >= 150.
    // El nuevo nodo va a quedar JUSTO ANTES de ese nodo p.
    p = lista.primero;
    while (p != nullptr)
    {
        if (p->dato < nuevo->dato)
        {
            p = p->siguiente; // todavia es chico, sigo buscando
        }
        else
        {
            // p es el primer nodo mayor (el 200). Inserto el nuevo antes de p:
            nuevo->siguiente = p;             // nuevo -> p
            nuevo->anterior = p->anterior;    // nuevo <- vecino izquierdo (100)
            nuevo->anterior->siguiente = nuevo; // 100 -> nuevo
            nuevo->siguiente->anterior = nuevo; // 200 <- nuevo
            break;
        }
    }

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

// Insertar en el medio de una lista doble = reconectar 4 punteros:
//   nuevo->siguiente, nuevo->anterior,
//   vecino_izquierdo->siguiente, vecino_derecho->anterior.
