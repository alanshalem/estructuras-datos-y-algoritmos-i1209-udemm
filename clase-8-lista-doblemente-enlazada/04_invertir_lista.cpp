// Invertir (reverse) una lista doble "a mano", sin crear nodos nuevos.
//
// Partimos de 100 <-> 200 <-> 300 <-> 400 y queremos dejarla
// 400 <-> 300 <-> 200 <-> 100.
//
// Truco: en cada nodo INTERCAMBIAMOS sus punteros anterior y siguiente.
// Cuando todos los nodos quedan dados vuelta, lo unico que falta es
// intercambiar tambien los extremos primero <-> ultimo de la lista.
//
// No se mueve ningun dato ni se reserva memoria: solo se reescriben punteros.

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

    // ---- Armo 100 <-> 200 <-> 300 <-> 400 agregando siempre atras ----
    int valores[] = {100, 200, 300, 400};
    for (int i = 0; i < 4; i++)
    {
        nuevo = new Nodo;
        nuevo->dato = valores[i];
        nuevo->anterior = nullptr;
        nuevo->siguiente = nullptr;

        if (lista.primero == nullptr) // lista vacia: primer nodo
        {
            lista.primero = nuevo;
            lista.ultimo = nuevo;
        }
        else
        {
            lista.ultimo->siguiente = nuevo;
            nuevo->anterior = lista.ultimo;
            lista.ultimo = nuevo;
        }
    }

    cout << "-------" << endl;
    p = lista.primero;
    while (p != nullptr)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    // ---- Reverse: en cada nodo intercambio anterior <-> siguiente ----
    p = lista.primero;
    Nodo* aux; // guarda temporal para no perder el siguiente original
    while (p != nullptr)
    {
        aux = p->siguiente;        // recuerdo a donde seguia ANTES del swap
        p->siguiente = p->anterior; // doy vuelta los punteros del nodo
        p->anterior = aux;

        p = p->anterior;           // avanzo: el "siguiente" viejo quedo en anterior
    }

    // Todos los nodos quedaron dados vuelta; ahora invierto los extremos.
    aux = lista.primero;
    lista.primero = lista.ultimo;
    lista.ultimo = aux;

    // ---- Mostrar lista invertida ----
    cout << "-------" << endl;
    p = lista.primero;
    while (p != nullptr)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    return 0;
}

// Invertir lista doble = en cada nodo swap(anterior, siguiente)
// + al final swap(lista.primero, lista.ultimo). Cero memoria nueva.
