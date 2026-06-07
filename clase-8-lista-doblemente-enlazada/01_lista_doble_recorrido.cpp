// Lista DOBLEMENTE enlazada: cada nodo apunta al siguiente Y al anterior.
//
// Diferencia con la cola de clase-7:
//   - Cola: cada nodo solo conoce al "siguiente". Se recorre en un sentido.
//   - Lista doble: cada nodo conoce "siguiente" y "anterior".
//                  Se puede recorrer del primero al ultimo y al reves.
//
// Como en la cola, guardamos los dos extremos (primero y ultimo) en un struct.
//
// Representacion despues de agregar 100, atras 200, adelante 50:
//
//   NULL <- [50 | *] <-> [100 | *] <-> [200 | *] -> NULL
//           primero                     ultimo
//   (<-> = cada nodo tiene puntero "anterior" y "siguiente")

#include <iostream>
using namespace std;

// Nodo con DOS punteros: uno hacia atras, uno hacia adelante.
struct Nodo
{
    int dato;
    Nodo* anterior;   // puntero al nodo de la izquierda
    Nodo* siguiente;  // puntero al nodo de la derecha
};

// La lista recuerda sus dos extremos.
struct estructuraLista
{
    Nodo* primero;
    Nodo* ultimo;
};

int main()
{
    Nodo* nuevo;
    Nodo* p;

    // Lista vacia: los dos extremos en NULL.
    estructuraLista lista;
    lista.primero = nullptr;
    lista.ultimo = nullptr;

    // ---- Primer nodo: 100 ----
    nuevo = new Nodo;
    nuevo->dato = 100;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;

    // sizeof(*nuevo) = 24 bytes: 4 (int dato) + 8 (anterior) + 8 (siguiente)
    // + 4 de padding para alinear a 8. Mide el Nodo, no el puntero.
    cout << sizeof(*nuevo) << endl;

    // La lista vacia arranca apuntando al primer nodo por los dos lados.
    lista.primero = nuevo;
    lista.ultimo = nuevo;

    // ---- Agregar ATRAS un 200 ----
    nuevo = new Nodo;
    nuevo->dato = 200;
    nuevo->anterior = nullptr;
    nuevo->siguiente = nullptr;

    lista.ultimo->siguiente = nuevo; // el viejo ultimo apunta adelante al nuevo
    nuevo->anterior = lista.ultimo;  // el nuevo apunta atras al viejo ultimo
    lista.ultimo = nuevo;            // el ultimo pasa a ser el nuevo

    // ---- Agregar ADELANTE un 50 ----
    nuevo = new Nodo;
    nuevo->dato = 50;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;

    lista.primero->anterior = nuevo;  // el viejo primero apunta atras al nuevo
    nuevo->siguiente = lista.primero; // el nuevo apunta adelante al viejo primero
    lista.primero = nuevo;            // el primero pasa a ser el nuevo

    cout << "-------" << endl;
    cout << "muestro primer dato " << lista.primero->dato << endl;
    cout << "muestro ultimo dato " << lista.ultimo->dato << endl;

    // ---- Recorrer del PRIMERO al ULTIMO (uso "siguiente") ----
    p = lista.primero;
    while (p != nullptr)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    // ---- Recorrer del ULTIMO al PRIMERO (uso "anterior") ----
    // Esto es lo que la lista doble permite y la simple no.
    cout << "-------" << endl;
    p = lista.ultimo;
    while (p != nullptr)
    {
        cout << p->dato << endl;
        p = p->anterior;
    }

    return 0;
}

// Pila = un puntero (tope).
// Cola = dos punteros (primero y ultimo), un sentido.
// Lista doble = dos punteros + cada nodo enlazado en los dos sentidos.
