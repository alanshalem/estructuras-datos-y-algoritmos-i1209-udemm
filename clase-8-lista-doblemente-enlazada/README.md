# Clase 8 - Listas doblemente enlazadas

Ejercicios de la materia **Estructuras de Datos y Algoritmos** - UdeMM.

En esta clase armamos una **lista doblemente enlazada** a mano con memoria dinámica (`new` / `delete`). Es el siguiente paso después de la pila (clase-7, un puntero) y la cola (clase-7, dos punteros, un solo sentido).

## ¿Qué cambia respecto a la clase 7?

| | Pila (clase 7) | Cola (clase 7) | Lista doble (clase 8) |
|---|---|---|---|
| Punteros de la estructura | 1 (`tope`) | 2 (`primero`, `ultimo`) | 2 (`primero`, `ultimo`) |
| Punteros por nodo | 1 (`siguiente`) | 1 (`siguiente`) | **2** (`anterior` y `siguiente`) |
| Sentidos de recorrido | 1 | 1 | **2** (adelante y atrás) |
| Insertar/borrar en el medio | no | no | **sí** |

## La idea: cada nodo mira a los dos lados

En la pila y la cola cada nodo sólo conocía al `siguiente`. Acá cada nodo guarda **dos** punteros: uno al nodo de la izquierda (`anterior`) y otro al de la derecha (`siguiente`). Eso permite recorrer la lista en los dos sentidos e insertar/borrar en cualquier posición.

```
   NULL <── [50 | * | *] <──> [100 | * | *] <──> [200 | * | *] ──> NULL
            primero                                ultimo
```

```cpp
struct Nodo {
    int   dato;
    Nodo* anterior;   // puntero al nodo de la izquierda
    Nodo* siguiente;  // puntero al nodo de la derecha
};

struct estructuraLista {
    Nodo* primero;
    Nodo* ultimo;
};
```

## Agregar ATRÁS (al final)

```cpp
lista.ultimo->siguiente = nuevo;  // el viejo ultimo apunta adelante al nuevo
nuevo->anterior = lista.ultimo;   // el nuevo apunta atras al viejo ultimo
lista.ultimo = nuevo;             // el ultimo pasa a ser el nuevo
```

## Agregar ADELANTE (al principio)

```cpp
lista.primero->anterior = nuevo;  // el viejo primero apunta atras al nuevo
nuevo->siguiente = lista.primero; // el nuevo apunta adelante al viejo primero
lista.primero = nuevo;            // el primero pasa a ser el nuevo
```

## Recorrer en los dos sentidos

```cpp
// Del primero al ultimo
p = lista.primero;
while (p != nullptr) { cout << p->dato << endl; p = p->siguiente; }

// Del ultimo al primero (lo que la lista doble permite y la simple no)
p = lista.ultimo;
while (p != nullptr) { cout << p->dato << endl; p = p->anterior; }
```

## Insertar EN EL MEDIO (4 punteros)

Para meter un nodo entre dos vecinos hay que reconectar **cuatro** punteros: los dos del nodo nuevo y un puntero de cada vecino.

```cpp
nuevo->siguiente = p;               // nuevo -> p (vecino derecho)
nuevo->anterior = p->anterior;      // nuevo <- vecino izquierdo
nuevo->anterior->siguiente = nuevo; // vecino izquierdo -> nuevo
nuevo->siguiente->anterior = nuevo; // vecino derecho <- nuevo
```

## Borrar DEL MEDIO (puentear vecinos)

El vecino de la izquierda pasa a apuntar al de la derecha y viceversa; después `delete`.

```cpp
p->anterior->siguiente = p->siguiente; // izquierdo -> derecho
p->siguiente->anterior = p->anterior;  // derecho <- izquierdo
delete p;                              // libero el nodo
```

> ⚠️ Este puente asume que el nodo **no es** el primero ni el último. Si lo fuera, `p->anterior` o `p->siguiente` serían `NULL` y `p->anterior->siguiente` rompería (segfault). Para borrar extremos hay que tratar esos casos aparte.

## Invertir la lista (sin crear nodos)

Truco: en **cada** nodo se intercambian `anterior` y `siguiente`; al terminar, se intercambian los extremos `primero` y `ultimo`. No se mueve ningún dato ni se reserva memoria.

```cpp
p = lista.primero;
Nodo* aux;
while (p != nullptr) {
    aux = p->siguiente;         // recuerdo el siguiente original
    p->siguiente = p->anterior; // doy vuelta los punteros del nodo
    p->anterior = aux;
    p = p->anterior;            // avanzo (el siguiente viejo quedo en anterior)
}
aux = lista.primero;
lista.primero = lista.ultimo;   // intercambio los extremos
lista.ultimo = aux;
```

## `NULL` vs `nullptr`

Ambos indican que el puntero **no apunta a nada**. En C++ moderno se recomienda `nullptr`; el profe a veces usa `NULL`. Los dos funcionan igual.

## Archivos

| Archivo | Descripción |
|---------|-------------|
| `01_lista_doble_recorrido.cpp` | Crear la lista, agregar atrás y adelante, recorrer en los dos sentidos |
| `02_insertar_ordenado.cpp` | Insertar un nodo en el medio manteniendo el orden (4 punteros) |
| `03_borrar_nodo.cpp` | Borrar un nodo del medio por su valor, puenteando los vecinos |
| `04_invertir_lista.cpp` | Invertir la lista entera intercambiando punteros, sin crear nodos |

## Cómo compilar y ejecutar

### En Linux / Mac (terminal)

```bash
g++ nombre_del_archivo.cpp -o programa
./programa
```

### En Windows (PowerShell o CMD)

```powershell
g++ nombre_del_archivo.cpp -o programa.exe
.\programa.exe
```

### Ejemplo concreto

```bash
g++ 01_lista_doble_recorrido.cpp -o programa
./programa
# Salida:
# 24
# -------
# muestro primer dato 50
# muestro ultimo dato 200
# 50
# 100
# 200
# -------
# 200
# 100
# 50
```

## Requisito: tener instalado g++

### Linux (Ubuntu/Debian)
```bash
sudo apt install g++
```

### Mac
```bash
xcode-select --install
```

### Windows
Instalar [MinGW](https://www.mingw-w64.org/) o usar el compilador que viene con VS Code + extensión C/C++.

## Header necesario

No hace falta ningún header especial: `struct`, `new` y `delete` son parte del lenguaje.

```cpp
#include <iostream>
```
