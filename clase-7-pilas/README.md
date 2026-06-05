# Clase 7 - Pilas dinámicas (implementadas con nodos)

Ejercicios de la materia **Estructuras de Datos y Algoritmos** - UdeMM.

En esta clase armamos la **pila a mano** usando **memoria dinámica** (`new` / `delete`) y nodos enlazados, en lugar de usar `std::stack` como en la clase 1.

## ¿Qué cambia respecto a la clase 1?

| | Clase 1 (`std::stack`) | Clase 7 (nodos) |
|---|---|---|
| Quién maneja la memoria | La librería estándar | Nosotros, a mano |
| Cómo se agrega un elemento | `p.push(x)` | Crear nodo con `new` y enlazarlo |
| Cómo se elimina | `p.pop()` | `delete` del nodo del tope |
| Qué hay que entender | Sólo la interfaz | Punteros, `struct`, `new`/`delete` |

## La idea: nodos enlazados

Cada elemento de la pila es un **nodo** que contiene un dato y un puntero al **siguiente** nodo (el de abajo). El puntero principal `pila` apunta siempre al **tope** (el último en entrar).

```
   pila ──► [ 30 | * ] ──► [ 20 | * ] ──► [ 10 | NULL ]
             tope                            fondo
```

```cpp
struct Nodo {
    int  dato;        // valor guardado
    Nodo* siguiente;  // puntero al nodo de abajo
};
```

## PUSH paso a paso

```cpp
nuevo = new Nodo;          // 1. reservo memoria para el nodo nuevo
nuevo->dato = x;           // 2. cargo el dato
nuevo->siguiente = pila;   // 3. el nuevo apunta al tope viejo
pila = nuevo;              // 4. el tope ahora es el nuevo nodo
```

## POP paso a paso

```cpp
p = pila;                  // 1. guardo el tope para poder liberarlo despues
pila = pila->siguiente;    // 2. el nuevo tope es el siguiente
delete p;                  // 3. libero la memoria del nodo viejo
```

> Si nos olvidamos del `delete`, esa memoria queda **perdida** hasta que termine el programa (*memory leak*).

## Recorrer la pila

```cpp
p = pila;                  // arranco desde el tope
while (p != NULL) {
    cout << p->dato << endl;
    p = p->siguiente;      // bajo al siguiente nodo
}
```

> Uso un puntero auxiliar `p` para no perder `pila` durante el recorrido.

## `NULL` vs `nullptr`

`NULL` es un valor **nulo** que indica que el puntero **no apunta a nada**. No es lo mismo que el número 0 (aunque en muchos compiladores valga `0`). En C++ moderno se recomienda usar `nullptr`, pero el profe usa `NULL` y los dos funcionan igual.

```cpp
Nodo* pila = NULL;         // estilo del profe
Nodo* pila = nullptr;      // C++ moderno (equivalente)
```

## Archivos

| Archivo | Descripción |
|---------|-------------|
| `01_pila_push_pop.cpp` | Pila con `Nodo`: `push` (10, 20, 30), mostrar, `pop`, mostrar |
| `02_dos_pilas_independientes.cpp` | `pila1` y `pila2` conviven en el mismo `main`, `pop` sobre una y **swap** de punteros |
| `03_cola_con_nodos.cpp` | Cola (FIFO) a mano con `struct estructuraCola { primero, ultimo }` y `dequeue` |

## Bonus: SWAP de pilas en O(1)

Como una pila es **un solo puntero**, intercambiar dos pilas no requiere mover nodos: alcanza con intercambiar los punteros.

```cpp
p = pila1;
pila1 = pila2;
pila2 = p;
```

## Bonus: Cola con nodos (clase-7 EJ3)

La pila usa **un** puntero (al tope). La cola necesita **dos** punteros: uno al primero (de donde sale el próximo) y uno al último (donde se agrega el nuevo). Los agrupamos en un `struct`:

```cpp
struct estructuraCola {
    Nodo* primero;
    Nodo* ultimo;
};
```

Encolar (al final):

```cpp
nuevo = new Nodo;
nuevo->dato = x;
nuevo->siguiente = NULL;
if (cola.primero == NULL) {        // cola vacia
    cola.primero = nuevo;
    cola.ultimo  = nuevo;
} else {
    cola.ultimo->siguiente = nuevo; // el viejo ultimo apunta al nuevo
    cola.ultimo = nuevo;            // el ultimo pasa a ser el nuevo
}
```

Desencolar (por el primero):

```cpp
p = cola.primero;
cola.primero = cola.primero->siguiente;
delete p;
```

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
g++ 01_pila_push_pop.cpp -o programa
./programa
# Salida:
# 30
# 20
# 10
# --------
# 20
# 10
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
