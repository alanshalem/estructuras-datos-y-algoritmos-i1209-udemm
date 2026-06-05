// Dos pilas dinamicas viviendo al mismo tiempo en el mismo programa.
//
// Cada pila es solo un puntero al primer nodo (tope). Como son punteros
// distintos, pila1 y pila2 son INDEPENDIENTES: hacer push en una no afecta
// a la otra, aunque los nodos sean del mismo tipo.
//
// Tambien mostramos:
//   - POP sobre pila1
//   - SWAP de las dos pilas (intercambiar los punteros, no copiar nodos)
//
// Detalle importante (motivo del error que vimos en clase):
//   En C++ no se puede declarar dos veces la misma variable en el mismo bloque.
//   Si escribimos "Nodo* nuevo = new Nodo;" arriba y mas abajo otra vez
//   "Nodo* nuevo = new Nodo;", el compilador tira error de redeclaracion.
//   Solucion: declarar nuevo (y p) UNA sola vez al principio de main y
//   despues reutilizarlos sin la palabra "Nodo*".

#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

int main()
{
    // Declaro los auxiliares UNA sola vez para reutilizarlos en las dos pilas
    Nodo* nuevo;
    Nodo* p;

    // =================== PILA 2 ===================
    Nodo* pila2 = NULL;

    // PUSH 100
    nuevo = new Nodo;
    nuevo->dato = 100;
    nuevo->siguiente = pila2;
    pila2 = nuevo;

    // PUSH 200
    nuevo = new Nodo;
    nuevo->dato = 200;
    nuevo->siguiente = pila2;
    pila2 = nuevo;

    // PUSH 300
    nuevo = new Nodo;
    nuevo->dato = 300;
    nuevo->siguiente = pila2;
    pila2 = nuevo;

    // =================== PILA 1 ===================
    Nodo* pila1 = NULL;

    // PUSH 10
    nuevo = new Nodo;
    nuevo->dato = 10;
    nuevo->siguiente = pila1;
    pila1 = nuevo;

    // PUSH 20
    nuevo = new Nodo;
    nuevo->dato = 20;
    nuevo->siguiente = pila1;
    pila1 = nuevo;

    // PUSH 30
    nuevo = new Nodo;
    nuevo->dato = 30;
    nuevo->siguiente = pila1;
    pila1 = nuevo;

    // ---- Mostrar pila1 (tope a fondo: 30, 20, 10) ----
    p = pila1;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    // ---- POP en pila1: saco el 30 ----
    p = pila1;                 // guardo el tope para liberarlo
    pila1 = pila1->siguiente;  // el nuevo tope es el 20
    delete p;                  // libero la memoria del nodo del 30

    cout << "---Pila 1---" << endl;
    p = pila1;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    cout << "---Pila 2---" << endl;
    // pila2 sigue intacta: no se mezclo con pila1
    p = pila2;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    // =================== SWAP de las dos pilas ===================
    // Intercambio los punteros (no copio nodos). Pila1 ahora apunta a lo
    // que apuntaba pila2 y viceversa. Es O(1) y no toca la memoria.
    p = pila1;
    pila1 = pila2;
    pila2 = p;

    cout << "---Despues de intercambiar los punteros---" << endl;

    cout << "---Pila 1---" << endl;
    p = pila1;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    cout << "---Pila 2---" << endl;
    p = pila2;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    return 0;
}
