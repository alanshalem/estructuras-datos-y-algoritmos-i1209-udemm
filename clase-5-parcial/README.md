# Clase 5 - Parcial (ejercicios integradores)

Ejercicios tipo **parcial** de la materia **Estructuras de Datos y Algoritmos** - UdeMM.

Cada ejercicio combina lo visto en las clases anteriores (pilas, colas, listas, árboles y structs) eligiendo la estructura de datos adecuada según lo que pide el enunciado.

## ¿Por qué cada estructura?

| Estructura | Propiedad | Para qué sirve en el parcial |
|------------|-----------|------------------------------|
| Pila (`stack`) | LIFO (último en entrar, primero en salir) | Invertir el orden de ingreso |
| Cola (`queue`) | FIFO (primero en entrar, primero en salir) | Conservar el orden de ingreso |
| Lista (`list`) | `push_front` / `push_back` en O(1) | Separar grupos hacia el frente y el final |
| Árbol (`set`) | Siempre ordenado, sin duplicados | Mostrar en orden ascendente |
| `struct` | Agrupa varios datos en un tipo | Modelar una persona (dni + edad), una pareja, etc. |

> Nota: los ejercicios simulan el ingreso del usuario con un arreglo `datos[]`
> que termina en `0` (en lugar de `cin`), recorrido con un índice. El `0` es el
> centinela que corta la lectura y no se agrega.

## Archivos

| Archivo | Estructura | Enunciado |
|---------|------------|-----------|
| `01_pares_inverso_pila.cpp` | Pila | Pares en orden **inverso** al ingresado |
| `02_impares_orden_cola.cpp` | Cola | Impares en el **mismo** orden de ingreso |
| `03_pares_inverso_impares_orden_lista.cpp` | Lista | Pares invertidos al frente, impares en orden al final |
| `04_arbol_orden_ascendente.cpp` | Árbol | Mostrar todo lo ingresado **ordenado** tras cada número |
| `05_parejas_hombres_mujeres.cpp` | Cola + Pila + Lista + structs | Emparejar 1er hombre con última mujer hasta agotar uno |

## Ejemplos de salida

```
01 (pila):  10 15 20 25 30 35 0  ->  30  20  10
02 (cola):  10 15 20 25 30 35 0  ->  15  25  35
03 (lista): 10 15 20 25 30 35 0  ->  30 20 10 15 25 35
04 (arbol): 20 35 10 15 0        ->  20 / 20 35 / 10 20 35 / 10 15 20 35
05 (parejas):
    hombres: 40000001,25  40000002,27  40000003,29
    mujeres: 39000002,25  39000001,23
    ->  40000001, 25, 39000001, 23
        40000002, 27, 39000002, 25
        (40000003 queda sin pareja)
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

Los datos están escritos dentro de cada `.cpp` (arreglo `datos[]`), así que no hay que ingresar nada por teclado: compilar y ejecutar.

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

## Headers usados en esta clase

```cpp
#include <stack>   // pilas
#include <queue>   // colas
#include <list>    // listas
#include <set>     // arboles
```
