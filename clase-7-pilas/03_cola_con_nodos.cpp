// Cola (FIFO) implementada a mano con nodos enlazados.
//
// Diferencia clave con la pila:
//   - Pila: UN solo puntero (tope). Entra y sale por el mismo lado.
//   - Cola: DOS punteros (primero y ultimo). Entra por "ultimo",
//           sale por "primero". Primero-en-entrar, primero-en-salir.
//
// Para evitar pasar dos punteros sueltos, los agrupamos dentro de un
// struct "estructuraCola" que contiene los dos extremos.
//
// Representacion despues de encolar 100, 200, 300:
//
//   cola.primero ──► [100 | *] ──► [200 | *] ──► [300 | NULL] ◄── cola.ultimo

#include <iostream>
using namespace std;

// Mismo Nodo que en la pila: dato + puntero al siguiente
struct Nodo
{
    int dato;
    Nodo* siguiente;
};

// La cola necesita recordar los dos extremos para ser eficiente:
//   primero -> de donde sale el proximo (dequeue)
//   ultimo  -> donde se agrega el nuevo (enqueue)
struct estructuraCola
{
    Nodo* primero;
    Nodo* ultimo;
};

int main()
{
    Nodo* nuevo;
    Nodo* p;

    // Cola vacia: los dos extremos en NULL
    estructuraCola cola;
    cola.primero = NULL;
    cola.ultimo = NULL;

    // ---- Encolar 100 ----
    nuevo = new Nodo;          // creo un nodo en, por ejemplo, direccion 10.000
    nuevo->dato = 100;
    nuevo->siguiente = NULL;   // como va al final, no tiene siguiente

    // sizeof devuelve el tamano del PUNTERO (8 bytes en 64 bits),
    // no el del Nodo. Lo dejamos a modo demostrativo.
    cout << sizeof(nuevo) << endl;

    if (cola.primero == NULL) // cola vacia: el nuevo es primero y ultimo a la vez
    {
        cola.primero = nuevo;
        cola.ultimo = nuevo;
    }
    else
    {
        cola.ultimo->siguiente = nuevo; // el viejo ultimo apunta al nuevo
        cola.ultimo = nuevo;            // y ahora el ultimo es el nuevo
    }

    // ---- Encolar 200 ----
    nuevo = new Nodo;
    nuevo->dato = 200;
    nuevo->siguiente = NULL;

    if (cola.primero == NULL)
    {
        cola.primero = nuevo;
        cola.ultimo = nuevo;
    }
    else
    {
        cola.ultimo->siguiente = nuevo; // el siguiente del 100 ahora es el 200
        cola.ultimo = nuevo;            // el ultimo pasa a ser el 200
    }

    // ---- Encolar 300 ----
    nuevo = new Nodo;
    nuevo->dato = 300;
    nuevo->siguiente = NULL;

    if (cola.primero == NULL)
    {
        cola.primero = nuevo;
        cola.ultimo = nuevo;
    }
    else
    {
        cola.ultimo->siguiente = nuevo; // el siguiente del 200 ahora es el 300
        cola.ultimo = nuevo;            // el ultimo pasa a ser el 300
    }

    cout << "-------" << endl;
    cout << "muestro primer dato " << cola.primero->dato << endl;
    cout << "muestro ultimo dato " << cola.ultimo->dato << endl;

    // ---- Recorrer la cola desde primero hasta ultimo ----
    p = cola.primero;
    while (p != NULL)
    {
        cout << p->dato << endl;
        p = p->siguiente;
    }

    // ---- Desencolar (dequeue): saco el primero ----
    // En la pila se saca por el mismo lado que se entra; en la cola se saca
    // por el OTRO lado. El nuevo primero es el "siguiente" del primero viejo.
    p = cola.primero;                       // guardo el primero para liberarlo
    cola.primero = cola.primero->siguiente; // el nuevo primero es el 200
    delete p;                               // libero la memoria del 100

    return 0;
}

// Resumen:
//   Pila = un unico puntero (tope).
//   Cola = dos punteros (primero y ultimo).
