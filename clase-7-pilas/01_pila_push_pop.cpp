// Pila implementada "a mano" con nodos enlazados y memoria dinamica.
//
// A diferencia de clase-1 que usa std::stack, aca armamos la pila nosotros:
//   - Cada nodo guarda un dato y un puntero al "siguiente" nodo.
//   - El puntero "pila" siempre apunta al TOPE de la pila (el ultimo en entrar).
//   - PUSH: crear nodo nuevo, enlazarlo al tope anterior, mover el tope.
//   - POP : guardar el tope en p, mover el tope al siguiente, delete p.
//
// Representacion en memoria despues de push 10, 20, 30:
//
//   pila --> [30 | *] --> [20 | *] --> [10 | NULL]
//             tope                       fondo

#include <iostream>
using namespace std;

// struct Nodo: cada elemento de la pila
struct Nodo
{
    int dato;          // valor que guarda el nodo
    Nodo* siguiente;   // puntero al nodo de abajo en la pila
};

int main()
{
    Nodo* pila = NULL; // pila vacia: el tope no apunta a ningun nodo
    Nodo* nuevo;       // puntero auxiliar para crear nodos
    Nodo* p;           // puntero auxiliar para recorrer / hacer pop

    // ---- PUSH 10 ----
    nuevo = new Nodo;          // reservo memoria para un nodo nuevo
    nuevo->dato = 10;          // cargo el dato
    nuevo->siguiente = pila;   // el nuevo apunta al tope viejo (que era NULL)
    pila = nuevo;              // el tope ahora es el nodo nuevo

    // ---- PUSH 20 ----
    nuevo = new Nodo;
    nuevo->dato = 20;
    nuevo->siguiente = pila;   // 20 apunta al 10
    pila = nuevo;              // el tope ahora es el 20

    // ---- PUSH 30 ----
    nuevo = new Nodo;
    nuevo->dato = 30;
    nuevo->siguiente = pila;   // 30 apunta al 20
    pila = nuevo;              // el tope ahora es el 30

    // ---- Mostrar pila desde el tope hasta el fondo ----
    // Uso p para recorrer, asi no pierdo el puntero pila
    p = pila;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->siguiente; // bajo al siguiente nodo
    }

    // ---- POP: sacar el tope (el 30) ----
    p = pila;                  // guardo el tope para poder liberarlo
    pila = pila->siguiente;    // el nuevo tope es el siguiente (20)
    delete p;                  // libero la memoria del 30 (si no, queda perdida)

    cout << "--------" << endl;

    // ---- Mostrar pila despues del pop ----
    p = pila;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    return 0;
}
